#ifndef HERO_1_H
#define HERO_1_H
#include <QGraphicsPixmapItem>
#include<QKeyEvent>

class hero_1 : public QGraphicsPixmapItem
{
public:
    int x_speed;
    int y_speed;
    int health=20;

    hero_1();

    void move(int a,int b);


};
#endif // HERO_1_H
