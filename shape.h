#ifndef SHAPE_H
#define SHAPE_H
//подключаем все необходимые для работы библиотеки
#include <QGraphicsItem>
#include <QPainter>
#include <QVector>
#include <QLineF>
#include <QGraphicsSceneMouseEvent>

class Shape : public QGraphicsItem
{
    //QGraphicsItem имеет 2 обязательных к переопределению функции:
    //QRectF boundingRect() const override;
    //И void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *wiget = nullptr) override;
    //Первая функция задает прямоугольник взаимодействия: область, при клике на которую будет считаться, что пользователь взаимодействует с объектом
    //Вторая функция говорит, что нужно отрисовать на сцене
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
    //Эти 2 функции являются функциями вызова перезаписи метода, из-за этого у них указана настройка override; Не все методы можно переопределить, ЧИТАЙТЕ ДОКУ ГОЛУБЦЫ
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;

//Приватные переменные - к ним имеет доступ только объект данного класса, но не имеют доступа классы-наследники
private:
    int x, y;
    QVector<QPointF>* arrNodes;
    QPointF* selectedPoint;
    qreal xL, yL, xR, yR;

};

#endif // SHAPE_H
