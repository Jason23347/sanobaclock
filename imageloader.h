#ifndef IMAGELOADER_H
#define IMAGELOADER_H

#include <QString>
#include <QImage>
#include <QLabel>

/**
 * @brief The ImageLoader class
 * @author Jason <jason23347@gmail.com>
 */
class ImageLoader : public QLabel
{
public:
    explicit ImageLoader(QWidget *parent = nullptr);
    ~ImageLoader();

protected:
    QString filepath;
    QImage *image;
    void rendor();
};

#endif // IMAGELOADER_H
