#ifndef MINION_5_H
#define MINION_5_H
#include <QGraphicsPixmapItem>
#include<QTimer>
#include<QObject>
#include<minion_fire.h>
class minion_5 : public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    minion_5(QGraphicsItem* parent=0);
    float x_speed;
    float y_speed;
    QTimer * timer;
    minion_fire *minionfire;


public slots:
    void move();
    void bomb();

};
#endif // MINION_5_H
