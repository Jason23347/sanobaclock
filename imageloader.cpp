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
    this->setPixmap(QPixmap::fromImage(
                        image->scaled(600, 900,
                                      Qt::KeepAspectRatio, Qt::SmoothTransformation)));
    this->setScaledContents(true);
}
