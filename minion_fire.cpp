#include"minion_fire.h"
#include"enemy_tower.h"

minion_fire::minion_fire(QGraphicsItem *parent)
{
    setPixmap(QPixmap(":/images/minion_fire.png"));
    x_speed=5;
    y_speed=0;
    timer=new QTimer(this);
    connect(timer,SIGNAL(timeout()), this,SLOT(move()));
    timer->start(10);
}

void minion_fire::move()
{
    this->setPos(this->pos().x()+x_speed , this->pos().y()+y_speed);
    if(pos().x() > 1500){
        scene()->removeItem(this);
        delete this;
    }


}
