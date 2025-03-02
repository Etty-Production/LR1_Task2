#ifndef CASTOMGRAPHICSSCENE_H
#define CASTOMGRAPHICSSCENE_H

#include <QGraphicsItem>
#include <QGraphicsScene>

class CastomGraphicsScene : public QGraphicsScene
{
public:
    CastomGraphicsScene();
    QGraphicsItem* GiveSelectedItem();

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

private:
    QGraphicsItem *SelectedItem;

};

#endif // CASTOMGRAPHICSSCENE_H
