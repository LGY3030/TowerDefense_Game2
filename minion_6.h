#ifndef MINION_6_H
#define MINION_6_H
#include <QGraphicsPixmapItem>
#include<QTimer>
#include<QObject>
#include<minion_fire.h>
class minion_6 : public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    minion_6(QGraphicsItem* parent=0);
    float x_speed;
    float y_speed;
    QTimer * timer;
    minion_fire *minionfire;


public slots:
    void move();
    void bomb();

};
#endif // MINION_6_H
