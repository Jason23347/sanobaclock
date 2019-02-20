#include "backgroundimagewidget.h"

#include <QtDebug>

BackgroundImageWidget::BackgroundImageWidget(QWidget *parent) : ImageLoader (parent)
{
    qDebug() << "background-image widget mounted.";
}

BackgroundImageWidget::~BackgroundImageWidget()
{
    qDebug() << "background-image widget delocated.";
}

void BackgroundImageWidget::boot()
{
    QString suffix = (game != "sanoba") ? ".jpg" : ".png";
    filepath = prefix + "/background_" + game + "_" + number + suffix;
    ImageLoader::rendor();
}

void BackgroundImageWidget::updatePrefix(QString path)
{
    this->prefix = path;
}

void BackgroundImageWidget::updateImage(QString game, QString number)
{
    this->game = game;
    this->number = number;
}
