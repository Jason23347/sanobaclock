#include "configwidget.h"

#include <QDir>
#include <QtDebug>
#include <QMouseEvent>
#include <QCoreApplication>

ConfigWidget::ConfigWidget(QWidget *parent) : QMenu(parent)
{
    settings = new QSettings(QCoreApplication::applicationDirPath() + "/config.ini", QSettings::IniFormat);
    characterForm = new CharacterForm();

    path = (new QDir(settings->value("/asset/path").toString()))->absolutePath();
    qDebug() << "path is: " << path;

    // background
    background_game = settings->value("/background/game").toString();
    background_number = settings->value("/background/number").toString();

    // clock
    clock_font_color = settings->value("/clock/fontcolor").toString();
    clock_gap = settings->value("/clock/gap").toInt();

    // character
    character_name = settings->value("/character/name").toString();
    character_costume = settings->value("/character/costume").toString();
    character_pose = settings->value("/character/pose").toString();
    character_type = settings->value("/character/type").toString();

    qDebug() << "config widget mounted.";
}

ConfigWidget::~ConfigWidget()
{
    delete settings;
    delete characterForm;
}

void ConfigWidget::mousePressEvent(QMouseEvent *mouse)
{
    qDebug() << mouse->pos();
    characterForm->show();
}

void ConfigWidget::boot()
{
    emit updatePath(path);
    emit updateBackground(background_game, background_number);
    emit updateFontColor(clock_font_color);
    emit updateTimeGap(clock_gap);
    emit updateCharacter(character_name, character_costume,
                         character_pose, character_type);
}
