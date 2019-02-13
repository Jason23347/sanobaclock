#ifndef CHARACTERIMAGELOADER_H
#define CHARACTERIMAGELOADER_H

#include "imageloader.h"

class CharacterImageLoader : public ImageLoader
{
    Q_OBJECT

public:
    explicit CharacterImageLoader(QLabel *label);
    explicit CharacterImageLoader(QString path, QLabel *label);
    ~CharacterImageLoader();
    CharacterImageLoader *setCostume(int costume);
    CharacterImageLoader *setType(int type);
    void boot();

private:
    QString prefix = "./files";
    QString character = "nen";
    int costume = 0;
    int type = 0;
};

#endif // CHARACTERIMAGELOADER_H
