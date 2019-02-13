#ifndef CHARACTERIMAGEWIDGET_H
#define CHARACTERIMAGEWIDGET_H

#include "imageloader.h"

class CharacterImageWidget : public ImageLoader
{
    Q_OBJECT

public:
    explicit CharacterImageWidget(QWidget *parent);
    ~CharacterImageWidget();

    void boot();

private:
    QString prefix = "./asset";
    QString character = "nen";
    QString costume = "0";
    QString type = "0";

public slots:
    void updatePrefix(QString);
    void updateImage(QString name, QString costume, QString type);
};

#endif // CharacterImageWidget_H