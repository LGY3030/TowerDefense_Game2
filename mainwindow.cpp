#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new Scene();
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setMouseTracking(true);
    scene->setSceneRect(0,0,1500,900);
    setFixedSize(1500,900);
    settingBg();
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->show();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::settingBg()
{
    QImage bg;
    bg.load(":/images/bg_init.jpg");


    scene->setBackgroundBrush(bg);
    scene->Init();
}
