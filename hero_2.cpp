#include"hero_2.h"

hero_2::hero_2()
{
    setPixmap(QPixmap(":/images/hero2.png"));
}

void hero_2::move(int a, int b)
{
    x_speed=a;
    y_speed=b;
    this->setPos(this->pos().x()+x_speed , this->pos().y()+y_speed);
}
