#include "imagewidget.h"

#include <QtDebug>

ImageWidget::ImageWidget(QWidget *parent) : QWidget (parent)
{
    qDebug() << "Image widget mounted.";
}

void ImageWidget::bind(QLabel *backgroundLabel, QLabel *characterLabel)
{
    this->background = new BackgroundImageWidget(backgroundLabel);
    this->character = new CharacterImageWidget(characterLabel);
}

ImageWidget::~ImageWidget()
{
    delete background;
    delete character;
}
