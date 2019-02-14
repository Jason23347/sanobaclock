#include "characterform.h"
#include "ui_characterform.h"

CharacterForm::CharacterForm(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CharacterForm)
{
    ui->setupUi(this);
}

CharacterForm::~CharacterForm()
{
    delete ui;
}
