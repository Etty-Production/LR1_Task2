#include "rectangle.h"

Rectangle::Rectangle(int x, int y, int sideSize) : Shape(x, y) {
    this->sideSize = sideSize;

    PushPointBack(QPointF(-sideSize, -sideSize));

    PushPointBack(QPointF(sideSize, -sideSize));
    PushPointBack(QPointF(sideSize, sideSize));
    PushPointBack(QPointF(-sideSize, sideSize));

    UpdateBoundRect();

}

void Rectangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *wiget)
{
    painter->drawPolygon(GiveStartNode(), 4);

    painter->setPen(Qt::gray);
    painter->setPen(Qt::DotLine);
    painter->drawRect(boundingRect());
    update();
}
