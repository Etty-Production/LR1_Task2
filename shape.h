#ifndef SHAPE_H
#define SHAPE_H

#include <QGraphicsItem>
#include <QPainter>
#include <QVector>
#include <QLineF>
#include <QGraphicsSceneMouseEvent>

class Shape : public QGraphicsItem
{
public:
    Shape(int x, int y);
    int GiveX();
    int GiveY();
    QPointF* GiveStartNode();
    int GiveKolNodes();
    void PushPointBack(QPointF point);
    void UpdateBoundRect();

protected:
    QRectF boundingRect() const override;

    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;

private:
    int x, y;
    QVector<QPointF>* arrNodes;
    QPointF* selectedPoint;
    qreal xL, yL, xR, yR;

};

#endif // SHAPE_H
