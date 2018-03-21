#include"enemy.h"

enemy::enemy(QGraphicsItem* parent)
{
    setPixmap(QPixmap(":/images/enemy.png"));
    x_speed=10;
    y_speed=0;
}

void enemy::move()
{
    this->setPos(this->pos().x()+x_speed , this->pos().y()+y_speed);
}
