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
}

void ClockWidget::report()
{
    QDateTime time = QDateTime::currentDateTime();
    QLocale locale = QLocale::English;

    int num = time.toString("mm").toInt();
    int m = num % 10;
    int mm = (num - m)/10;

    playlist->clear();

    playlist->addMedia(QMediaContent(
                           QUrl::fromLocalFile(
                               prefix + "/" + character + "_app_" + locale.toString(time, "ap") + ".mp3")));
    playlist->addMedia(QMediaContent(
                           QUrl::fromLocalFile(
                               prefix + "/" + character + "_app_" + "h_" + QString::number(locale.toString(time, "h").toInt()%12) + ".mp3")));
    if (mm > 0) {
        playlist->addMedia(QMediaContent(
                               QUrl::fromLocalFile(
                                   prefix + "/" + character + "_app_mm_m_" + QString::number(mm) + ".mp3")));
    }
    if (m > 0) {
        playlist->addMedia(QMediaContent(
                               QUrl::fromLocalFile(
                                   prefix + "/" + character + "_app_" + "m_m_" + QString::number(m) + ".mp3")));
    }
    playlist->addMedia(QMediaContent(
                           QUrl::fromLocalFile(
                               prefix + "/" + character + "_app_end.mp3")));
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
    this->prefix = QDir::currentPath() + "/" + path;
}

void ClockWidget::updateCharacter(QString name)
{
    this->character = name;
}
