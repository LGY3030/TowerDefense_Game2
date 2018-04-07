#include"minion_2.h"

minion_2::minion_2(QGraphicsItem *parent)
{
    setPixmap(QPixmap(":/images/minion2_tank.png"));
    x_speed=0.2;
    y_speed=0;
    timer = new QTimer();
    connect(timer,SIGNAL(timeout()), this,SLOT(bomb()));
    timer->start(2000);
}

void minion_2::move()
{
    this->setPos(this->pos().x()+x_speed , this->pos().y()+y_speed);
}

void minion_2::bomb()
{
    minionfire=new minion_fire();
    minionfire->setPos(this->pos().x()+100,this->pos().y()+40);
    scene()->addItem(minionfire);

}
