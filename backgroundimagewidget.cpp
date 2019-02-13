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
    filepath = prefix + "/background_" + number + ".png";
    ImageLoader::rendor();
}

void BackgroundImageWidget::updatePrefix(QString path)
{
    this->prefix = path;
}

void BackgroundImageWidget::updateImage(QString number)
{
    this->number = number;
}
