#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setSceneRect(-ui->graphicsView->width() / 2, -ui->graphicsView->height() / 2, ui->graphicsView->width(), ui->graphicsView->height());
    view = new CastomGraphicsScene();
    ui->graphicsView->setScene(view);

    view->addItem(new Rectangle(0, 0, 20));

    timer = new QTimer();
    connect(timer, &QTimer::timeout, this, &MainWindow::UpdateScene);
    timer->start(10);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::UpdateScene()
{
    view->update();
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    if (view->GiveSelectedItem() != nullptr) view->GiveSelectedItem()->setRotation(value * 3.6);
}


void MainWindow::on_horizontalSlider_2_valueChanged(int value)
{
    if (view->GiveSelectedItem() != nullptr) view->GiveSelectedItem()->setScale(value * 0.02);
}

