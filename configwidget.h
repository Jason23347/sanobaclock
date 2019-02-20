#ifndef CONFIGWIDGET_H
#define CONFIGWIDGET_H

#include <QMenu>
#include <QSettings>

#include "characterform.h"

class ConfigWidget : public QMenu
{
    Q_OBJECT

public:
    explicit ConfigWidget(QWidget *parent);
    ~ConfigWidget();

    void boot();

protected:
    void mousePressEvent(QMouseEvent *mouse);

private:
    QSettings *settings;
    CharacterForm *characterForm;

    QString path;

    QString background_game;
    QString background_number;

    int clock_gap;
    QString clock_font_color;

    QString character_name;
    QString character_costume;
    QString character_pose;
    QString character_type;

signals:
    void updatePath(QString path);
    void updateFontColor(QString color);
    void updateBackground(QString game, QString number);
    void updateTimeGap(int gap);
    void updateCharacter(QString name, QString costume, QString pose, QString type);
};

#endif // CONFIGWIDGET_H
