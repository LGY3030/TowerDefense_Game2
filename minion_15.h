#ifndef MINION_15_H
#define MINION_15_H
#include <QGraphicsPixmapItem>
#include<QTimer>
#include<QObject>
#include<minion_fire.h>
class minion_15 : public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    minion_15(QGraphicsItem* parent=0);
    float x_speed;
    float y_speed;

    QTimer * timer;
    minion_fire *minionfire;


public slots:
    void move();
    void bomb();

};
#endif // MINION_15_H
