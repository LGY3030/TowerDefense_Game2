#ifndef HERO_3_H
#define HERO_3_H
#include <QGraphicsPixmapItem>

class hero_3 : public QGraphicsPixmapItem
{
public:
    int x_speed;
    int y_speed;
    int health=500;
    hero_3();

    void move(int a,int b);


};
#endif // HERO_3_H
