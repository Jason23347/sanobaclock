#include "clockwidget.h"

#include <QTimer>
#include <QtDebug>
#include <QDateTime>
#include <QDir>

ClockWidget::ClockWidget(QWidget *parent) : QWidget(parent)
{
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(rendor()));
    timer->start(980);

    player = new QMediaPlayer();
    playlist = new QMediaPlaylist();

    qDebug() << "clock widget mounted.";
}

ClockWidget::~ClockWidget()
{
    delete timer;
    delete player;
    delete playlist;

    qDebug() << "clock widget delocated.";
}

void ClockWidget::bind(QLabel *dateLabel,
                       QLabel *weekLabel, QLabel *timeLabel)
{
    this->dateLabel = dateLabel;
    this->weekLabel = weekLabel;
    this->timeLabel = timeLabel;
}

void ClockWidget::rendor()
{
    QDateTime time = QDateTime::currentDateTime();
    dateLabel->setText(time.toString("M月dd日"));
    weekLabel->setText(time.toString("ddd"));
    timeLabel->setText(time.toString("HH:mm"));

    int minute = time.toString("mm").toInt();
    QString second = time.toString("ss");

    if (minute % gap == 0 && second == "00")
        report();
}

void ClockWidget::report()
{
    if ( character == "miu" ||
         character == "azu" ||
         character == "rio" ||
         character == "ele"
         ) {
        qDebug() << "report time v1";
        reportV1();
    } else if ( character == "nen" ||
                character == "meg" ||
                character == "tmg" ||
                character == "tok" ||
                character == "wak"
                ) {
        qDebug() << "report time v2";
        reportV2();
    } else {
        qDebug() << "report time v3";
        reportV3();
    }
}

void ClockWidget::reportV1()
{
    QDateTime time = QDateTime::currentDateTime();
    QLocale locale = QLocale::English;

    int hour = locale.toString(time, "h").toInt() % 12;
    if(hour == 0)
        hour = 12;

    playlist->clear();

    playlist->addMedia(QMediaContent(
                           QUrl::fromLocalFile(
                               prefix + "/" + character + "_clock_start.mp3")));
    playlist->addMedia(QMediaContent(
                           QUrl::fromLocalFile(
                               prefix + "/" + character + "_clock_" +
                               locale.toString(time, "ap") + ".mp3")));
    playlist->addMedia(QMediaContent(
                           QUrl::fromLocalFile(
                               prefix + "/" + character + "_clock_h_" +
                               QString::number(hour) + ".mp3")));
    playlist->addMedia(QMediaContent(
                           QUrl::fromLocalFile(
                               prefix + "/" + character + "_clock_mm_" + time.toString("mm") + ".mp3" )));
    playlist->addMedia(QMediaContent(
                           QUrl::fromLocalFile(
                               prefix + "/" + character + "_clock_end.mp3")));

    playlist->setPlaybackMode(QMediaPlaylist::Sequential);

    player->setPlaylist(playlist);
    player->play();
}

void ClockWidget::reportV2()
{

    QDateTime time = QDateTime::currentDateTime();
    QLocale locale = QLocale::English;

    int hour = locale.toString(time, "h").toInt() % 12;
    if(hour == 0)
        hour = 12;

    int num = time.toString("mm").toInt();
    int m = num % 10;
    int mm = (num - m)/10;

    playlist->clear();

    playlist->addMedia(QMediaContent(
                           QUrl::fromLocalFile(
                               prefix + "/" + character + "_clock_" +
                               locale.toString(time, "ap") + ".mp3")));
    playlist->addMedia(QMediaContent(
                           QUrl::fromLocalFile(
                               prefix + "/mute.mp3")));
    playlist->addMedia(QMediaContent(
                           QUrl::fromLocalFile(
                               prefix + "/" + character + "_clock_" + "h_" +
                               QString::number(hour) + ".mp3")));
    playlist->addMedia(QMediaContent(
                           QUrl::fromLocalFile(
                               prefix + "/mute.mp3")));
    if (m == 0) {
        if(mm > 0) {
            playlist->addMedia(QMediaContent(
                                   QUrl::fromLocalFile(
                                       prefix + "/" + character + "_clock_mm_m_" +
                                       QString::number(mm) + ".mp3")));
        }
        playlist->addMedia(QMediaContent(
                               QUrl::fromLocalFile(
                                   prefix + "/mute.mp3")));
    } else if (mm > 0) {
        playlist->addMedia(QMediaContent(
                               QUrl::fromLocalFile(
                                   prefix + "/" + character + "_clock_mm_" + QString::number(mm) + ".mp3")));
        playlist->addMedia(QMediaContent(
                               QUrl::fromLocalFile(
                                   prefix + "/mute.mp3")));
    }

    if (m > 0) {
        playlist->addMedia(QMediaContent(
                               QUrl::fromLocalFile(
                                   prefix + "/" + character + "_clock_" + "m_m_" + QString::number(m) + ".mp3")));
        playlist->addMedia(QMediaContent(
                               QUrl::fromLocalFile(
                                   prefix + "/mute.mp3")));
    }
    playlist->addMedia(QMediaContent(
                           QUrl::fromLocalFile(
                               prefix + "/" + character + "_clock_end.mp3")));
    playlist->setPlaybackMode(QMediaPlaylist::Sequential);

    player->setPlaylist(playlist);
    player->play();
}

void ClockWidget::reportV3()
{

    QDateTime time = QDateTime::currentDateTime();
    QLocale locale = QLocale::English;

    int hour = locale.toString(time, "h").toInt() % 12;
    if(hour == 0)
        hour = 12;

    int num = time.toString("mm").toInt();
    int m = num % 10;
    int mm = (num - m)/10;

    playlist->clear();

    playlist->addMedia(QMediaContent(
                           QUrl::fromLocalFile(
                               prefix + "/" + character + "_watch_" +
                               locale.toString(time, "ap") + ".ogg")));
    playlist->addMedia(QMediaContent(
                           QUrl::fromLocalFile(
                               prefix + "/" + character + "_watch_" + "h_" +
                               QString::number(hour) + ".ogg")));
    if (m == 0) {
        if(mm > 0) {
            playlist->addMedia(QMediaContent(
                                   QUrl::fromLocalFile(
                                       prefix + "/" + character + "_watch_mm_m_" +
                                       QString::number(mm) + ".ogg")));
        }
    } else if (mm > 0) {
        playlist->addMedia(QMediaContent(
                               QUrl::fromLocalFile(
                                   prefix + "/" + character + "_watch_mm_" + QString::number(mm) + ".ogg")));
    }

    if (m > 0) {
        playlist->addMedia(QMediaContent(
                               QUrl::fromLocalFile(
                                   prefix + "/" + character + "_watch_" + "m_m_" + QString::number(m) + ".ogg")));
    }
    playlist->addMedia(QMediaContent(
                           QUrl::fromLocalFile(
                               prefix + "/" + character + "_watch_end.ogg")));
    playlist->setPlaybackMode(QMediaPlaylist::Sequential);

    player->setPlaylist(playlist);
    player->play();
}

void ClockWidget::mousePressEvent(QMouseEvent *event)
{
    this->report();
}

void ClockWidget::updatePrefix(QString path)
{
    this->prefix = path;
}

void ClockWidget::updateCharacter(QString name)
{
    this->character = name;
}

void ClockWidget::updateFontColor(QString color)
{
    QPalette pe;
    if (color == "white") {
        pe.setColor(QPalette::WindowText,Qt::white);
    }else {
        pe.setColor(QPalette::WindowText,Qt::black);
    }

    this->dateLabel->setPalette(pe);
    this->weekLabel->setPalette(pe);
    this->timeLabel->setPalette(pe);
}

void ClockWidget::updateTimeGap(int gap)
{
    this->gap = gap;
}
