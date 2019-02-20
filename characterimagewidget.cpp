#include "characterimagewidget.h"

#include <QMouseEvent>
#include <QtDebug>

CharacterImageWidget::CharacterImageWidget(QWidget *parent) : ImageLoader (parent)
{
    player = new QMediaPlayer();
    connect(player, &QMediaPlayer::stateChanged,
            this, &CharacterImageWidget::refresh);
    qDebug() << "character-image widget mounted.";
}

CharacterImageWidget::~CharacterImageWidget()
{
    delete player;
    qDebug() << "character-image widget delocated.";
}

void CharacterImageWidget::mousePressEvent(QMouseEvent *mouse)
{
    qDebug() << "touch event currently not available";
    return;
    if (locked) {
        qDebug() << "image locked.";
        return;
    }
    locked = true;

    int x = mouse->pos().x();
    int y = mouse->pos().y();

    QString tmp = this->type;
    QString pmp = this->pose;

    qDebug() << "x: " << x << ", y: " << y;


    if ((x > 270 && x < 326) &&
            (y > 310 && y < 660))
    {
        qDebug() << "touched shoulder.";

        updateImage(character, costume, pose, "4");
        boot();
        updateImage(character, costume, pmp, tmp);

        player->setMedia(QMediaContent(
                             QUrl::fromLocalFile(prefix + "/" + character + "_touch_02.mp3")));
        player->play();
        return;
    }

    if ((x > 130 && x < 310) && (y > 140 && y < 300))
    {
        qDebug() << "touched head.";

        tmp = this->type;
        updateImage(character, costume, pose, "2");
        boot();
        updateImage(character, costume, pmp, tmp);

        player->setMedia(QMediaContent(
                             QUrl::fromLocalFile(prefix + "/" + character + "_touch_01.mp3")));
        player->play();
    }

    if (x > 120 && x < 340)
    {
        if ((x > 220 && x < 240) && (y > 535 && y < 545)) {
            qDebug() << "touched panty!!! You hentai!!!";

            tmp = this->type;
            updateImage(character, costume, pose, "4");
            boot();
            updateImage(character, costume,pmp, tmp);

            player->setMedia(QMediaContent(
                                 QUrl::fromLocalFile(prefix + "/" + character + "_touch_04.mp3")));
            player->play();
            return;
        }
        if (y > 299 && y < 515) {
            qDebug() << "touched chest or belly!!!";

            tmp = this->type;
            updateImage(character, costume, pose, "3");
            boot();
            updateImage(character, costume, pmp, tmp);

            player->setMedia(QMediaContent(
                                 QUrl::fromLocalFile(prefix + "/" + character + "_touch_03.mp3")));
            player->play();
            return;
        } else if (y > 514) {
            qDebug() << "touched legs!!!";

            tmp = this->type;
            updateImage(character, costume, pose, "6");
            boot();
            updateImage(character, costume, pmp, tmp);

            player->setMedia(QMediaContent(
                                 QUrl::fromLocalFile(prefix + "/" + character + "_touch_04.mp3")));
            player->play();
            return;
        }
    }
}

void CharacterImageWidget::boot()
{
    filepath = prefix + "/" + character + "_" +
            "costume_" + costume + "_" +
            "pose_" + pose + "_" +
            "type_" + type + ".png";
    ImageLoader::rendor();
}

void CharacterImageWidget::updatePrefix(QString path)
{
    this->prefix = path;
}

void CharacterImageWidget::updateImage(QString name, QString costume, QString pose, QString type)
{
    this->character = name;
    this->costume = costume;
    this->pose = pose;
    this->type = type;
}

void CharacterImageWidget::refresh(QMediaPlayer::State state)
{
    if (state == QMediaPlayer::StoppedState) {
        boot();
        locked = false;
        qDebug() << "image refreshed.";
    }
}
