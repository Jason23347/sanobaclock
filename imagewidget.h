#ifndef IMAGEWIDGET_H
#define IMAGEWIDGET_H

#include <QWidget>
#include <QLabel>

#include "backgroundimagewidget.h"
#include "characterimagewidget.h"

class ImageWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ImageWidget(QWidget *parent = nullptr);
    ~ImageWidget();

    void bind(QLabel *backgroundLabel = nullptr,
              QLabel *characterLabel = nullptr);

private:
    BackgroundImageWidget *background;
    CharacterImageWidget *character;
public slots:

};

#endif // IMAGEWIDGET_H
