#ifndef MINION_18_H
#define MINION_18_H
#include <QGraphicsPixmapItem>
#include<QTimer>
#include<QObject>
#include<minion_fire.h>
class minion_18 : public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    minion_18(QGraphicsItem* parent=0);
    float x_speed;
    float y_speed;

    QTimer * timer;
    minion_fire *minionfire;


public slots:
    void move();
    void bomb();

};
#endif // MINION_18_H
