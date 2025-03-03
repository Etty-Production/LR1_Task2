#include "rectangle.h"


//Создаем 4 точки в порядке, в котором они должны стоять на сцене, 1-я точка соединяеться с последней. И обновляем крвадрат взаимодействия
// : Shape(x, y) обозначает, что мы также вызываем конструктор у класса-родителя для осуществления базового функционала
Rectangle::Rectangle(int x, int y, int sideSize) : Shape(x, y) {

    this->sideSize = sideSize;

    PushPointBack(QPointF(-sideSize, -sideSize));
    PushPointBack(QPointF(sideSize, -sideSize));
    PushPointBack(QPointF(sideSize, sideSize));
    PushPointBack(QPointF(-sideSize, sideSize));

    UpdateBoundRect();
}

//Рисуем многоугольник через painter->drawPolygon и рисуем крвадрат взаимодействия painter->drawRect(boundingRect())
void Rectangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *wiget)
{
    painter->drawPolygon(GiveStartNode(), GiveKolNodes());

    painter->setPen(Qt::gray);
    painter->setPen(Qt::DotLine);
    painter->drawRect(boundingRect());
}
