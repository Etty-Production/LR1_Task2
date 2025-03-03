#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //Настраиваем то, как будет отображаться QGraphicsView. Убираем полосы прокрутки и ставим область отрисовки
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setSceneRect(-ui->graphicsView->width() / 2, -ui->graphicsView->height() / 2, ui->graphicsView->width(), ui->graphicsView->height());
    //Создаем в куче объект класса CastomGraphicsScene и сохраняем в приватный указатель ссылку на него
    view = new CastomGraphicsScene();
    //Задаем UI-объекту graphicsView отбработчика отрисовки, созданного ранее (view)
    ui->graphicsView->setScene(view);

    //Создаем в куче объект класса Rectangle и передаем указатель на него сцене для отображения
    view->addItem(new Rectangle(0, 0, 20));

    //Создаем в куче объект класса таймер и сохраняем ссылку на него в приватной переменной класса
    timer = new QTimer();
    //Соединяем событие объекта класса таймер и функции UpdateScene, объявленной в классе MainWindow/ читать здесь: https://doc.qt.io/qt-6/qobject.html#connect-1
    connect(timer, &QTimer::timeout, this, &MainWindow::UpdateScene);
    //Запускаем тайер. Событие будет срабатывать каждые 10 миллисекунд
    timer->start(10);
}

//Деструктор. Его имеет каждый класс. Оставляем как есть
MainWindow::~MainWindow()
{
    delete ui;
}

//Функция, которую мы соединяли с таймером. Перересовывает всю сцену, чтобы убрать артефакты
void MainWindow::UpdateScene()
{
    view->update();
}

//Каждый раз, когда двигаем слайдер спрашиваем, выбран ли пользователем объект, в случае, если выбран, поворачиваем его через встроенный метод. Читать: https://doc.qt.io/qt-6/qgraphicsitem.html#setRotation
void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    if (view->GiveSelectedItem() != nullptr) view->GiveSelectedItem()->setRotation(value * 3.6);
}

//Каждый раз, когда двигаем слайдер спрашиваем, выбран ли пользователем объект, в случае, если выбран, изменяем его размер через встроенный метод. Читать: https://doc.qt.io/qt-6/qgraphicsitem.html#setScale
void MainWindow::on_horizontalSlider_2_valueChanged(int value)
{
    if (view->GiveSelectedItem() != nullptr) view->GiveSelectedItem()->setScale(value * 0.02);
}

