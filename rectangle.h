#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"
//: public Shape обозначает, что мы наследуем от этого класса его публичные методы
class Rectangle : public Shape
{
public:
    Rectangle(int x, int y, int sideSize);

protected:

void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *wiget = nullptr) override;

private:
    int sideSize;
};

#endif // RECTANGLE_H
