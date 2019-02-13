#ifndef CLOCKWIDGET_H
#define CLOCKWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QMediaPlayer>
#include <QMediaPlaylist>

class ClockWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ClockWidget(QWidget *parent = nullptr);
    ~ClockWidget();

    void bind(QLabel *dateLabel = nullptr,
              QLabel *weekLabel = nullptr,
              QLabel *timeLabel = nullptr);

protected:
    void mousePressEvent(QMouseEvent *event);

private:
    QLabel *dateLabel;
    QLabel *weekLabel;
    QLabel *timeLabel;

    QTimer *timer;

    QMediaPlayer *player;
    QMediaPlaylist *playlist;

    QString prefix;
    QString character = "nen";

    void report();

public slots:
    void updatePrefix(QString path);
    void updateCharacter(QString name);
    void rendor();
};

#endif // CLOCKWIDGET_H
