#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // bindings
    ui->clock->bind(ui->dateLabel,
                    ui->weekLabel, ui->timeLabel);

    // path config binding
    connect(ui->menuconfig, &ConfigWidget::updatePath,
            ui->backgroundLabel, &BackgroundImageWidget::updatePrefix);
    connect(ui->menuconfig, &ConfigWidget::updatePath,
            ui->characterLabel, &CharacterImageWidget::updatePrefix);
    connect(ui->menuconfig, &ConfigWidget::updatePath,
            ui->clock, &ClockWidget::updatePrefix);
    connect(ui->menuconfig, &ConfigWidget::updateCharacter,
            ui->clock, &ClockWidget::updateCharacter);

    // background config binding
    connect(ui->menuconfig, &ConfigWidget::updateBackground,
            ui->backgroundLabel, &BackgroundImageWidget::updateImage);

    // clock config binding
    connect(ui->menuconfig, &ConfigWidget::updateFontColor,
            ui->clock, &ClockWidget::updateFontColor);
    connect(ui->menuconfig, &ConfigWidget::updateTimeGap,
            ui->clock, &ClockWidget::updateTimeGap);

    // character config binding
    connect(ui->menuconfig, &ConfigWidget::updateCharacter,
            ui->characterLabel, &CharacterImageWidget::updateImage);

    qDebug() << "Appilcation started to boot.";
    // boot config
    ui->menuconfig->boot();

    // boot image
    ui->backgroundLabel->boot();
    ui->characterLabel->boot();

    // boot clock
    ui->clock->rendor();
    ui->clock->report();

    qDebug() << "Appilcation boot ended.";
}

MainWindow::~MainWindow()
{
    delete ui;
}
