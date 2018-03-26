#ifndef HERO_2_H
#define HERO_2_H
#include <QGraphicsPixmapItem>

class hero_2 : public QGraphicsPixmapItem
{
public:
    int x_speed;
    int y_speed;
    int health=10;
    hero_2();

    void move(int a,int b);


};
#endif // HERO_2_H
