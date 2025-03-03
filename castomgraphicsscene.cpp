#include "castomgraphicsscene.h"
#include <QGraphicsSceneMouseEvent>
#include <QDebug>

CastomGraphicsScene::CastomGraphicsScene() {}

//Метод создан для передачи указателя на приватный элемент класса. Чтобы в случае, когда в другом классе есть такая-же переменная не было неопределенного поведения. А еще это считаеться хорошим тоном
QGraphicsItem *CastomGraphicsScene::GiveSelectedItem()
{
    return SelectedItem;
}

//Перехватываем объект на сцене по позиции клика через встроенный метод itemAt класса QGraphicsScene
void CastomGraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    SelectedItem = nullptr;
    SelectedItem = itemAt(event->scenePos(), QTransform());
    qDebug() << (SelectedItem == nullptr);
    //Передаем событие обратно в класс-родитель для выполнения штатного функционала
    QGraphicsScene::mousePressEvent(event);
}
