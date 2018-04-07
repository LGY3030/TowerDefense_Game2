#ifndef MINION_12_H
#define MINION_12_H
#include <QGraphicsPixmapItem>
#include<QTimer>
#include<QObject>
#include<minion_fire.h>
class minion_12 : public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    minion_12(QGraphicsItem* parent=0);
    float x_speed;
    float y_speed;
    QTimer * timer;
    minion_fire *minionfire;


public slots:
    void move();
    void bomb();

};
#endif // MINION_12_H
