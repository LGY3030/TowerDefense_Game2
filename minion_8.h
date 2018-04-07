#ifndef MINION_8_H
#define MINION_8_H
#include <QGraphicsPixmapItem>
#include<QTimer>
#include<QObject>
#include<minion_fire.h>
class minion_8 : public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    minion_8(QGraphicsItem* parent=0);
    float x_speed;
    float y_speed;
    QTimer * timer;
    minion_fire *minionfire;


public slots:
    void move();
    void bomb();

};
#endif // MINION_8_H
