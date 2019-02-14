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

    QString background_number;

    QString character_name;
    QString character_costume;
    QString character_type;

signals:
    void updatePath(QString path);
    void updateBackground(QString numer);
    void updateCharacter(QString name, QString costume, QString type);
};

#endif // CONFIGWIDGET_H
