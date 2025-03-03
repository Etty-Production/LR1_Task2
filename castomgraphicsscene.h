#ifndef CASTOMGRAPHICSSCENE_H
#define CASTOMGRAPHICSSCENE_H

//подключаем все необходимые для работы библиотеки
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
