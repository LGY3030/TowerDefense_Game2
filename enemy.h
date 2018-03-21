#ifndef ENEMY_H
#define ENEMY_H
#include<QGraphicsPixmapItem>

class enemy : public QGraphicsPixmapItem
{
public:
    enemy(QGraphicsItem *parent=0);
    void move();


    int x_speed;
    int y_speed;


};
#endif // ENEMY_H
