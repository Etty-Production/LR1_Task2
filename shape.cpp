#include "shape.h"


Shape::Shape(int x, int y) {
    setFlag(QGraphicsItem::ItemIsMovable);
    this->x = x;
    this->y = y;
    arrNodes = new QList<QPointF>;
}

int Shape::GiveX()
{
    return this->x;
}

int Shape::GiveY()
{
    return this->y;
}

QPointF *Shape::GiveStartNode()
{
    return arrNodes->begin();
}

int Shape::GiveKolNodes()
{
    arrNodes->size();
}

void Shape::PushPointBack(QPointF point)
{
    arrNodes->push_back(point);
}

void Shape::UpdateBoundRect()
{
    xL = 10000; yL = 10000; xR = -10000; yR = -10000;
    for(auto i = arrNodes->begin(); i != arrNodes->end(); i++){
        QPointF* point = static_cast<QPointF*>(i);
        qreal pX = point->x();
        qreal pY = point->y();
        xL = xL > pX ? pX : xL;
        xR = xR < pX ? pX : xR;
        yL = yL > pY ? pY : yL;
        yR = yR < pY ? pY : yR;
    }

}


QRectF Shape::boundingRect() const
{
    return QRectF(QPointF(xL, yL), QPointF(xR, yR));
}

void Shape::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    selectedPoint = nullptr;
    QPointF posClk = event->pos();
    for(auto i = arrNodes->begin(); i != arrNodes->end(); i++){
        QPointF* point = static_cast<QPointF*>(i);
        if(QLineF(posClk.x(), posClk.y(), point->x(), point->y()).length() < 10) selectedPoint = point;
    }
    if (selectedPoint != nullptr) qDebug() << selectedPoint->x() << ' ' << selectedPoint->y();
    QGraphicsItem::mousePressEvent(event);
}

void Shape::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if(selectedPoint == nullptr){
        QGraphicsItem::mouseMoveEvent(event);
        return;
    };
    selectedPoint->setX(event->pos().x());
    selectedPoint->setY(event->pos().y());

    UpdateBoundRect();

    qDebug() << xL << ' ' << yL << ' ' << xR << ' ' << yR;
}

