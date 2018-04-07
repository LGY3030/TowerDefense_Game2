#ifndef ENEMY_TOWER_FIRE_H
#define ENEMY_TOWER_FIRE_H
#include <QGraphicsPixmapItem>
#include<QTimer>
#include<QObject>
#include<QGraphicsScene>
#include"minion_1.h"
#include"minion_2.h"
#include"minion_3.h"
#include"minion_4.h"
#include"minion_5.h"
#include"minion_6.h"
#include"minion_7.h"
#include"minion_8.h"
#include"minion_9.h"
#include"minion_10.h"
#include"minion_11.h"
#include"minion_12.h"
#include"minion_13.h"
#include"minion_14.h"
#include"minion_15.h"
#include"minion_16.h"
#include"minion_17.h"
#include"minion_18.h"
#include"minion_19.h"
#include"minion_20.h"
#include"hero_1.h"
#include"hero_2.h"
#include"hero_3.h"
#include"my_tower.h"
class enemy_tower_fire : public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    enemy_tower_fire(QGraphicsItem* parent=0);
    float x_speed;
    float y_speed;
    QTimer *timer;


public slots:
    void move();



};
#endif // ENEMY_TOWER_FIRE_H
