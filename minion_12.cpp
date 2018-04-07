#include"minion_12.h"

minion_12::minion_12(QGraphicsItem* parent)
{
    setPixmap(QPixmap(":/images/minion12_tank.png"));
    x_speed=0.2;
    y_speed=0;
    timer = new QTimer();
    connect(timer,SIGNAL(timeout()), this,SLOT(bomb()));
    timer->start(2000);
}

void minion_12::move()
{
    this->setPos(this->pos().x()+x_speed , this->pos().y()+y_speed);
}

void minion_12::bomb()
{
    minionfire=new minion_fire();
    minionfire->setPos(this->pos().x()+100,this->pos().y()+40);
    scene()->addItem(minionfire);

}
