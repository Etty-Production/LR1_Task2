#include "castomgraphicsscene.h"
#include <QGraphicsSceneMouseEvent>
#include <QDebug>

CastomGraphicsScene::CastomGraphicsScene() {}

QGraphicsItem *CastomGraphicsScene::GiveSelectedItem()
{
    return SelectedItem;
}

void CastomGraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    SelectedItem = nullptr;
    SelectedItem = itemAt(event->scenePos(), QTransform());
    qDebug() << (SelectedItem == nullptr);
    QGraphicsScene::mousePressEvent(event);
}
