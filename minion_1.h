#ifndef MINION_1_H
#define MINION_1_H

#include <QGraphicsPixmapItem>
#include<QTimer>
#include<minion_fire.h>


class minion_1 :public QObject, public QGraphicsPixmapItem
{
Q_OBJECT
public:

    minion_1(QGraphicsItem *parent=0);
    float x_speed;
    float y_speed;
    QTimer * timer;
    minion_fire *minionfire;


public slots:
    void move();
    void bomb();

};
#endif // MINION_1_H
