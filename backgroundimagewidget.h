#ifndef BACKGROUNDIMAGEWIDGET_H
#define BACKGROUNDIMAGEWIDGET_H

#include <QWidget>

#include "imageloader.h"

class BackgroundImageWidget : public ImageLoader
{
    Q_OBJECT

public:
    explicit BackgroundImageWidget(QWidget *parent = nullptr);
    ~BackgroundImageWidget();

    void boot();

private:
    QString number;
    QString game;
    QString prefix;

public slots:
    void updateImage(QString game, QString number);
    void updatePrefix(QString path);
};

#endif // BACKGROUNDIMAGELOADER_H
