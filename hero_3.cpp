#include"hero_3.h"

hero_3::hero_3()
{
    setPixmap(QPixmap(":/images/hero3.png"));
}

void hero_3::move(int a, int b)
{
    x_speed=a;
    y_speed=b;
    this->setPos(this->pos().x()+x_speed , this->pos().y()+y_speed);
}
