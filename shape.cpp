#include "shape.h"

//Конструктор класса. Запускается 1 раз при создании объекта класса
Shape::Shape(int x, int y) {
    //Делаем объект активным через встроенный метод setFlag. Читать: https://doc.qt.io/qt-6/qgraphicsitem.html#setFlag
    setFlag(QGraphicsItem::ItemIsMovable);
    //Инициализируем приватные переменные класса для работы с ними
    this->x = x;
    this->y = y;
    arrNodes = new QList<QPointF>;
}

//Далее приведены методы, позволяющие получить значение приватных переменных класса. Что они делают интуитивно понятно из названия
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
    return arrNodes->size();
}

void Shape::PushPointBack(QPointF point)
{
    arrNodes->push_back(point);
}

//Даный метод позволяет изменять размеры объекта при передвижении какой-либо из вершин.
//Так xL и yL хранят минимальные значения по X и по Y из всез вершин, которые составляют фигуру.
//А xR и yR - максимальные значения. После по этим 2-м точкам создается прямоугольник взаимодействия.

void Shape::UpdateBoundRect()
{
    //Обновляем все вершины для того, чтобы гарантированно захватить весь диапазон точек. Кому непонятно - ложитесь спать, вам завтра в садик
    xL = 10000; yL = 10000; xR = -10000; yR = -10000;
    //Проходимся по всем вершинам вектора с помощью указателя
    for(auto i = arrNodes->begin(); i != arrNodes->end(); i++){
        //auto не знает что это за класс, указатели на который мы зраним, поэтому преобразовываем указатель в указатель на QPointF и сохраняем его в переменную
        QPointF* point = static_cast<QPointF*>(i);
        //Запоминаем координаты переменной
        qreal pX = point->x();
        qreal pY = point->y();
        //Нахождение минимума и максимума
        xL = xL > pX ? pX : xL;
        xR = xR < pX ? pX : xR;
        yL = yL > pY ? pY : yL;
        yR = yR < pY ? pY : yR;
    }

}

//Создаем прямоугольник взаимодействия по 2-м точкам
QRectF Shape::boundingRect() const
{
    return QRectF(QPointF(xL, yL), QPointF(xR, yR));
}

//Переопределяем встроенное событие нажатия мыши по объекту. Пробегаем все вершины фигуры. Если клик был в радиусе 10 пикселей от вершины - считаем, что эта вершина захвачена пользователем.
void Shape::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    //Обозначаем изначально выбранную точку как нулевой указатель, чтобы не хранить мусор.
    selectedPoint = nullptr;
    //перехватываем позицию клика
    QPointF posClk = event->pos();
    //перебираем вершины через указатель
    for(auto i = arrNodes->begin(); i != arrNodes->end(); i++){
        //auto не знает что это за класс, указатели на который мы зраним, поэтому преобразовываем указатель в указатель на QPointF и сохраняем его в переменную
        QPointF* point = static_cast<QPointF*>(i);
        //Находим расстояние между точкой клика и вершиной с помощью объекта класса QLineF и его встроенного метода length(). Если условие выполнено - сохраняем новую выбранную вершину
        if(QLineF(posClk.x(), posClk.y(), point->x(), point->y()).length() < 10) selectedPoint = point;
    }
    //вывод ою удачном захвате в консоль
    if (selectedPoint != nullptr) qDebug() << selectedPoint->x() << ' ' << selectedPoint->y();
    //Передаем событие классу-родителю для реализации прочего функционала
    QGraphicsItem::mousePressEvent(event);
}


//Переопределяем встроенное событие перемещения мышью
void Shape::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    //Если вершина не выбрана, то передаем событие классу родителю и завершаем выполнение метода
    if(selectedPoint == nullptr){
        QGraphicsItem::mouseMoveEvent(event);
        return;
    };
    //Если же вершина выбрана, то перемешаем ее за курсором и НЕ передаем событие классу родителю, в противном случае будет двигаться не вершина, а вся фигура целиком.
    selectedPoint->setX(event->pos().x());
    selectedPoint->setY(event->pos().y());
    //После перемещения вершины необходимо обновить прямоугольник взаимодействия
    UpdateBoundRect();

    qDebug() << xL << ' ' << yL << ' ' << xR << ' ' << yR;
}

