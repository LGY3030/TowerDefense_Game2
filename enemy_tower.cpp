#include"enemy_tower.h"
#include"iostream"
#include<stdlib.h>
#include"minion_fire.h"
#include"hero_fire.h"
enemy_tower::enemy_tower()
{
    setPixmap(QPixmap(":/images/enemy_tower_new.png"));
    x_speed=-0.02;
    y_speed=0;

    timer = new QTimer();
    connect(timer,SIGNAL(timeout()), this,SLOT(bomb()));
    timer->start(3000);
    label = new QLabel();
    label->setText("You Win !!");
    label->setGeometry(700,500,500,500);
    label->setAlignment(Qt::AlignCenter);

}

void enemy_tower::move()
{
    this->setPos(this->pos().x()+x_speed , this->pos().y()+y_speed);
    QList<QGraphicsItem *> colliding_items = collidingItems();
        for (int i = 0, n = colliding_items.size(); i < n; ++i){
            if (typeid(*(colliding_items[i])) == typeid(minion_fire)){


                health=health-5;
                scene()->removeItem(colliding_items[i]);
                delete colliding_items[i];
                if(health<=0){
                scene()->removeItem(this);
                delete this;
                 label->show();

                 }
            }

            else if (typeid(*(colliding_items[i])) == typeid(hero_fire)){


                    health=health-10;
                    scene()->removeItem(colliding_items[i]);
                    delete colliding_items[i];
                    if(health<=0){
                    scene()->removeItem(this);
                    delete this;
                    label->show();
                     }


                 }


        }
}

void enemy_tower::bomb()
{
    randomnum=rand()%350;
    enemytowerfire=new enemy_tower_fire();
    enemytowerfire->setPos(this->pos().x()-300-randomnum,this->pos().y()+randomnum);
    scene()->addItem(enemytowerfire);

}
