#include"minion_1.h"

minion_1::minion_1(QGraphicsItem* parent)
{
    setPixmap(QPixmap(":/images/minion1_tank.png"));
    timer = new QTimer();
    connect(timer,SIGNAL(timeout()), this,SLOT(bomb()));
    timer->start(2000);
    x_speed=0.2;
    y_speed=0;

}

void minion_1::move()
{
    this->setPos(this->pos().x()+x_speed , this->pos().y()+y_speed);
}

void minion_1::bomb()
{
    minionfire=new minion_fire();
    minionfire->setPos(this->pos().x()+100,this->pos().y()+40);
    scene()->addItem(minionfire);


}

