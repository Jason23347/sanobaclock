#include "characterimagewidget.h"

#include <QtDebug>

CharacterImageWidget::CharacterImageWidget(QWidget *parent) : ImageLoader (parent)
{
    qDebug() << "character-image widget mounted.";
}

CharacterImageWidget::~CharacterImageWidget()
{
    qDebug() << "character-image widget delocated.";
}

void CharacterImageWidget::boot()
{
    filepath = prefix + "/" + character + "_" +
            "costume_" + costume + "_" +
            "type_" + type + ".png";
    ImageLoader::rendor();
}

void CharacterImageWidget::updatePrefix(QString path)
{
    this->prefix = path;
}

void CharacterImageWidget::updateImage(QString name, QString costume, QString type)
{
    this->character = name;
    this->costume = costume;
    this->type = type;
}
