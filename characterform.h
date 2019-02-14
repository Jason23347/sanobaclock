#ifndef CHARACTERFORM_H
#define CHARACTERFORM_H

#include <QMainWindow>

namespace Ui {
class CharacterForm;
}

class CharacterForm : public QMainWindow
{
    Q_OBJECT

public:
    explicit CharacterForm(QWidget *parent = nullptr);
    ~CharacterForm();

private:
    Ui::CharacterForm *ui;
};

#endif // CHARACTERFORM_H
