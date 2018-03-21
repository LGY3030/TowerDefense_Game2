#ifndef ENEMY_TOWER_H
#define ENEMY_TOWER_H
#include<QTimer>
#include<QObject>
#include <QGraphicsPixmapItem>
#include"enemy_tower_fire.h"
#include<QGraphicsScene>
#include<stdlib.h>
#include<QLabel>

class enemy_tower : public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    enemy_tower();
    float x_speed;
    float y_speed;
    QTimer *timer;
    enemy_tower_fire * enemytowerfire;
    int randomnum;
    int health=1000;
    QLabel *label;


public slots:
    void move();
    void bomb();

};
#endif // ENEMY_TOWER_H
