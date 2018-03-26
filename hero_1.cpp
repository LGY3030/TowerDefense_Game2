#include"hero_1.h"
#include<iostream>
#include"enemy_tower_fire.h"
hero_1::hero_1()
{
    setPixmap(QPixmap(":/images/hero1.png"));

}

void hero_1::move(int a,int b)
{
    x_speed=a;
    y_speed=b;
    this->setPos(this->pos().x()+x_speed , this->pos().y()+y_speed);


}



