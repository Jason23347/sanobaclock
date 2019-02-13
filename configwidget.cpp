#include "configwidget.h"

#include <QtDebug>

ConfigWidget::ConfigWidget(QWidget *parent) : QMenu(parent)
{
    settings = new QSettings("config.ini", QSettings::IniFormat);

    path = settings->value("/asset/path").toString();

    // background
    background_number = settings->value("/background/number").toString();

    // character
    character_name = settings->value("/character/name").toString();
    character_costume = settings->value("/character/costume").toString();
    character_type = settings->value("/character/type").toString();

    qDebug() << "config widget mounted.";
}

ConfigWidget::~ConfigWidget()
{
    delete settings;
}

void ConfigWidget::boot()
{
    emit updatePath(path);
    emit updateBackground(background_number);
    emit updateCharacter(character_name,
                         character_costume, character_type);
}
