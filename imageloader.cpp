#include "imageloader.h"

#include <QMessageBox>
#include <QtDebug>

ImageLoader::ImageLoader(QWidget *parent) : QLabel(parent)
{
    image = new QImage();
}

ImageLoader::~ImageLoader()
{
    delete image;
}

void ImageLoader::rendor()
{
    if (!image->load(filepath)) {
        qDebug() << "Cannot open file" << filepath;
        return;
    }
    if (image->width()*1.0/image->height() < 448.0 / 730) {
        qDebug() << "width not enough";
        this->setPixmap(QPixmap::fromImage(
                            image->scaledToWidth(448, Qt::SmoothTransformation)));
    } else {
        qDebug() << "height not enough";
        this->setPixmap(QPixmap::fromImage(
                            image->scaledToHeight(730, Qt::SmoothTransformation)));
    }
    this->setAlignment(Qt::AlignCenter);
}
