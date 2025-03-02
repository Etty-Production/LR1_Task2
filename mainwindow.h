#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QTimer>
#include "castomgraphicsscene.h"
#include "rectangle.h"
#include "shape.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void UpdateScene();

private slots:
    void on_horizontalSlider_valueChanged(int value);

    void on_horizontalSlider_2_valueChanged(int value);

private:
    Ui::MainWindow *ui;
    CastomGraphicsScene* view;
    QTimer *timer;

};
#endif // MAINWINDOW_H
