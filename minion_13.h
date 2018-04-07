#ifndef MINION_13_H
#define MINION_13_H
#include <QGraphicsPixmapItem>
#include<QTimer>
#include<QObject>
#include<minion_fire.h>
class minion_13 : public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    minion_13(QGraphicsItem* parent=0);
    float x_speed;
    float y_speed;
    QTimer * timer;
    minion_fire *minionfire;


public slots:
    void move();
    void bomb();

};
#endif // MINION_13_H
