#include"enemy_tower_fire.h"
enemy_tower_fire::enemy_tower_fire(QGraphicsItem *parent)
{
    setPixmap(QPixmap(":/images/enemy_tower_fire.png"));
    x_speed=0;
    y_speed=-5;
    timer=new QTimer(this);
    connect(timer,SIGNAL(timeout()), this,SLOT(move()));
    timer->start(200);


}

void enemy_tower_fire::move()
{


    this->setPos(this->pos().x()+x_speed , this->pos().y()+y_speed);
    y_speed+=1;
    if(y_speed==0){
        scene()->removeItem(this);
        delete this;
    }

        QList<QGraphicsItem *> colliding_items = collidingItems();
        for (int i = 0, n = colliding_items.size(); i < n; ++i){
            if (typeid(*(colliding_items[i])) == typeid(minion_1)){

                scene()->removeItem(colliding_items[i]);
                delete colliding_items[i];
                return;
            }
            else if (typeid(*(colliding_items[i])) == typeid(minion_2)){

                scene()->removeItem(colliding_items[i]);
                delete colliding_items[i];
                return;
            }
            else if (typeid(*(colliding_items[i])) == typeid(minion_3)){

                scene()->removeItem(colliding_items[i]);
                delete colliding_items[i];
                return;
            }
            else if (typeid(*(colliding_items[i])) == typeid(minion_4)){

                scene()->removeItem(colliding_items[i]);
                delete colliding_items[i];
                return;
            }
            else if (typeid(*(colliding_items[i])) == typeid(minion_5)){

                scene()->removeItem(colliding_items[i]);
                delete colliding_items[i];
                return;
            }
            else if (typeid(*(colliding_items[i])) == typeid(minion_6)){

                scene()->removeItem(colliding_items[i]);
                delete colliding_items[i];
                return;
            }
            else if (typeid(*(colliding_items[i])) == typeid(minion_7)){

                scene()->removeItem(colliding_items[i]);
                delete colliding_items[i];
                return;
            }
            else if (typeid(*(colliding_items[i])) == typeid(minion_8)){

                scene()->removeItem(colliding_items[i]);
                delete colliding_items[i];
                return;
            }
            else if (typeid(*(colliding_items[i])) == typeid(minion_9)){

                scene()->removeItem(colliding_items[i]);
                delete colliding_items[i];
                return;
            }
            else if (typeid(*(colliding_items[i])) == typeid(minion_10)){

                scene()->removeItem(colliding_items[i]);
                delete colliding_items[i];
                return;
            }
            else if (typeid(*(colliding_items[i])) == typeid(minion_11)){

                scene()->removeItem(colliding_items[i]);
                delete colliding_items[i];
                return;
            }
            else if (typeid(*(colliding_items[i])) == typeid(minion_12)){

                scene()->removeItem(colliding_items[i]);
                delete colliding_items[i];
                return;
            }
            else if (typeid(*(colliding_items[i])) == typeid(minion_13)){

                scene()->removeItem(colliding_items[i]);
                delete colliding_items[i];
                return;
            }
            else if (typeid(*(colliding_items[i])) == typeid(minion_14)){

                scene()->removeItem(colliding_items[i]);
                delete colliding_items[i];
                return;
            }

            else if (typeid(*(colliding_items[i])) == typeid(minion_15)){

                scene()->removeItem(colliding_items[i]);
                delete colliding_items[i];
                return;
            }
            else if (typeid(*(colliding_items[i])) == typeid(minion_16)){

                scene()->removeItem(colliding_items[i]);
                delete colliding_items[i];
                return;
            }
            else if (typeid(*(colliding_items[i])) == typeid(minion_17)){

                scene()->removeItem(colliding_items[i]);
                delete colliding_items[i];
                return;
            }
            else if (typeid(*(colliding_items[i])) == typeid(minion_18)){

                scene()->removeItem(colliding_items[i]);
                delete colliding_items[i];
                return;
            }
            else if (typeid(*(colliding_items[i])) == typeid(minion_19)){

                scene()->removeItem(colliding_items[i]);
                delete colliding_items[i];
                return;
            }
            else if (typeid(*(colliding_items[i])) == typeid(minion_20)){

                scene()->removeItem(colliding_items[i]);
                delete colliding_items[i];
                return;
            }
            else if (typeid(*(colliding_items[i])) == typeid(hero_1)){

                hero_1 * hero1 = dynamic_cast<hero_1 *>(colliding_items[i]);
                hero1->health=hero1->health-1;
                if(hero1->health<=0){
                scene()->removeItem(hero1);
                delete hero1;
                 }

               }
            else if (typeid(*(colliding_items[i])) == typeid(hero_2)){

                hero_2 * hero2 = dynamic_cast<hero_2 *>(colliding_items[i]);
                hero2->health=hero2->health-1;
                if(hero2->health<=0){
                scene()->removeItem(hero2);
                delete hero2;
                 }

               }
            else if (typeid(*(colliding_items[i])) == typeid(hero_3)){

                hero_3 * hero3 = dynamic_cast<hero_3 *>(colliding_items[i]);
                hero3->health=hero3->health-1;
                if(hero3->health<=0){
                scene()->removeItem(hero3);
                delete hero3;
                 }

               }
            else if (typeid(*(colliding_items[i])) == typeid(my_tower)){

                scene()->removeItem(colliding_items[i]);
                delete colliding_items[i];
                return;
                 }




        }


}
