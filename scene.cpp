#include "scene.h"
#include <iostream>

Scene::Scene()
{

    timer=new QTimer();
    timer->start(10);

    screenMode = 0;
    hero_pick=1;
    minion_pick1=1;
    minion_pick2=2;
    minion_pick3=3;
    minion_pick4=4;
    cursor = nullptr;
    choose=0;
    x=0;
    y=0;
    get=0;

}

void Scene::Init()
{

    btn_start = new btn();
    QPixmap start;
    start.load(":/images/btn_start.png");
    start = start.scaled(start.width()*1/2,start.height()*1/2,Qt::KeepAspectRatio);
    btn_start->setPixmap(start);
    btn_start->setPos(1250,500);
    addItem(btn_start);

    btn_choose_hero = new btn();
    QPixmap ch;
    ch.load(":/images/btn_hero.png");
    ch = ch.scaled((ch.width()*1)/2,(ch.height()*1)/2,Qt::KeepAspectRatio);
    btn_choose_hero->setPixmap(ch);
    btn_choose_hero->setPos(1250,600);
    addItem(btn_choose_hero);

    btn_choose_minion = new btn();
    QPixmap cm;
    cm.load(":/images/btn_minion.png");
    cm = cm.scaled((cm.width()*1)/2,(cm.height()*1)/2,Qt::KeepAspectRatio);
    btn_choose_minion->setPixmap(cm);
    btn_choose_minion->setPos(1250,700);
    addItem(btn_choose_minion);
}

void Scene::setCursor(QString filename)
{
    if (cursor){
            removeItem(cursor);
            delete cursor;
        }

        cursor = new QGraphicsPixmapItem();
        cursor->setPixmap(QPixmap(filename));
        this->addItem(cursor);

}



void Scene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{

    if (cursor){
           cursor->setPos(event->scenePos());
       }
}

void Scene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(screenMode == 0)
    {

        if(event->scenePos().x() > btn_choose_hero->pos().x() && event->scenePos().x() <= btn_choose_hero->pos().x()+155)
        {

            if(event->scenePos().y() > btn_choose_hero->pos().y() && event->scenePos().y() <= btn_choose_hero->pos().y()+90)
            {

                cout<< "change get"<< endl;
                bgChange_hero();
                screenMode = 1;
            }
        }

        if(event->scenePos().x() > btn_choose_minion->pos().x() && event->scenePos().x() <= btn_choose_minion->pos().x()+156)
        {

            if(event->scenePos().y() > btn_choose_minion->pos().y() && event->scenePos().y() <= btn_choose_minion->pos().y()+93)
            {

                cout<< "change get"<< endl;
                bgChange_minion();
                screenMode = 2;
            }
        }

        if(event->scenePos().x() > btn_start->pos().x() && event->scenePos().x() <= btn_start->pos().x()+158)
        {

            if(event->scenePos().y() > btn_start->pos().y() && event->scenePos().y() <= btn_start->pos().y()+92)
            {

                cout<< "Button get"<< endl;
                bgChange_start();
                screenMode = 3;
            }
        }

    }

    else if(screenMode == 1)
    {

        if ((!cursor) && y==0){
        if(event->scenePos().x() > hero1->pos().x() && event->scenePos().x() <= hero1->pos().x()+150)
                {

                    if(event->scenePos().y() > hero1->pos().y() && event->scenePos().y() <= hero1->pos().y()+200)
                    {

                        setCursor(QString(":/images/hero1.png"));
                        choose=1;

                    }
                }
        if(event->scenePos().x() > hero2->pos().x() && event->scenePos().x() <= hero2->pos().x()+150)
                {

                    if(event->scenePos().y() > hero2->pos().y() && event->scenePos().y() <= hero2->pos().y()+200)
                    {

                        setCursor(QString(":/images/hero2.png"));
                        choose=2;

                    }
                }
        if(event->scenePos().x() > hero3->pos().x() && event->scenePos().x() <= hero3->pos().x()+150)
                {

                    if(event->scenePos().y() > hero3->pos().y() && event->scenePos().y() <= hero3->pos().y()+200)
                    {

                        setCursor(QString(":/images/hero3.png"));
                        choose=3;

                    }
                }
        }
        else if((cursor)&& y==0){


            if(event->scenePos().x() > 600 && event->scenePos().x() <= 800 && event->scenePos().y() > 600 && event->scenePos().y() <= 800)
            {

                     this->addItem(cursor);
                     cursor->setPos(650,600);
                     cursor = nullptr;
                     hero_pick=choose;
                     y=1;

            }
        }
        else if(y==1){
            if(event->scenePos().x() > btn_back->pos().x() && event->scenePos().x() <= btn_back->pos().x()+btn_small_w)
        {

            if(event->scenePos().y() > btn_back->pos().y() && event->scenePos().y() <= btn_back->pos().y()+btn_small_h)
            {

                bgRecover();
                screenMode = 0;
            }
        }
        }
    }

    else if(screenMode == 2)
    {

        if ((!cursor) && x==0){
        if(event->scenePos().x() > minion1->pos().x() && event->scenePos().x() <= minion1->pos().x()+130)
                {

                    if(event->scenePos().y() > minion1->pos().y() && event->scenePos().y() <= minion1->pos().y()+220)
                    {

                        setCursor(QString(":/images/minion1.png"));
                        choose=1;

                    }
                }
        if(event->scenePos().x() > minion2->pos().x() && event->scenePos().x() <= minion2->pos().x()+130)
                {

                    if(event->scenePos().y() > minion2->pos().y() && event->scenePos().y() <= minion2->pos().y()+220)
                    {

                        setCursor(QString(":/images/minion2.png"));
                        choose=2;

                    }
                }
        if(event->scenePos().x() > minion3->pos().x() && event->scenePos().x() <= minion3->pos().x()+130)
                {

                    if(event->scenePos().y() > minion3->pos().y() && event->scenePos().y() <= minion3->pos().y()+220)
                    {

                        setCursor(QString(":/images/minion3.png"));
                        choose=3;

                    }
                }
        if(event->scenePos().x() > minion4->pos().x() && event->scenePos().x() <= minion4->pos().x()+130)
                {

                    if(event->scenePos().y() > minion4->pos().y() && event->scenePos().y() <= minion4->pos().y()+220)
                    {

                        setCursor(QString(":/images/minion4.png"));
                        choose=4;

                    }
                }
        if(event->scenePos().x() > minion5->pos().x() && event->scenePos().x() <= minion5->pos().x()+130)
                {

                    if(event->scenePos().y() > minion5->pos().y() && event->scenePos().y() <= minion5->pos().y()+220)
                    {

                        setCursor(QString(":/images/minion5.png"));
                        choose=5;

                    }
                }
        if(event->scenePos().x() > minion6->pos().x() && event->scenePos().x() <= minion6->pos().x()+130)
                {

                    if(event->scenePos().y() > minion6->pos().y() && event->scenePos().y() <= minion6->pos().y()+220)
                    {

                        setCursor(QString(":/images/minion6.png"));
                        choose=6;


                    }
                }
        if(event->scenePos().x() > minion7->pos().x() && event->scenePos().x() <= minion7->pos().x()+130)
                {

                    if(event->scenePos().y() > minion7->pos().y() && event->scenePos().y() <= minion7->pos().y()+220)
                    {

                        setCursor(QString(":/images/minion7.png"));
                        choose=7;

                    }
                }
        if(event->scenePos().x() > minion8->pos().x() && event->scenePos().x() <= minion8->pos().x()+130)
                {

                    if(event->scenePos().y() > minion8->pos().y() && event->scenePos().y() <= minion8->pos().y()+220)
                    {

                        setCursor(QString(":/images/minion8.png"));
                        choose=8;

                    }
                }
        if(event->scenePos().x() > minion9->pos().x() && event->scenePos().x() <= minion9->pos().x()+130)
                {

                    if(event->scenePos().y() > minion9->pos().y() && event->scenePos().y() <= minion9->pos().y()+220)
                    {

                        setCursor(QString(":/images/minion9.png"));
                        choose=9;

                    }
                }
        if(event->scenePos().x() > minion10->pos().x() && event->scenePos().x() <= minion10->pos().x()+130)
                {

                    if(event->scenePos().y() > minion10->pos().y() && event->scenePos().y() <= minion10->pos().y()+220)
                    {

                        setCursor(QString(":/images/minion10.png"));
                        choose=10;

                    }
                }
        if(event->scenePos().x() > minion11->pos().x() && event->scenePos().x() <= minion11->pos().x()+130)
                {

                    if(event->scenePos().y() > minion11->pos().y() && event->scenePos().y() <= minion11->pos().y()+220)
                    {

                        setCursor(QString(":/images/minion11.png"));
                        choose=11;

                    }
                }
        if(event->scenePos().x() > minion12->pos().x() && event->scenePos().x() <= minion12->pos().x()+130)
                {

                    if(event->scenePos().y() > minion12->pos().y() && event->scenePos().y() <= minion12->pos().y()+220)
                    {

                        setCursor(QString(":/images/minion12.png"));
                        choose=12;

                    }
                }
        if(event->scenePos().x() > minion13->pos().x() && event->scenePos().x() <= minion13->pos().x()+130)
                {

                    if(event->scenePos().y() > minion13->pos().y() && event->scenePos().y() <= minion13->pos().y()+220)
                    {

                        setCursor(QString(":/images/minion13.png"));
                        choose=13;

                    }
                }
        if(event->scenePos().x() > minion14->pos().x() && event->scenePos().x() <= minion14->pos().x()+130)
                {

                    if(event->scenePos().y() > minion14->pos().y() && event->scenePos().y() <= minion14->pos().y()+220)
                    {

                        setCursor(QString(":/images/minion14.png"));
                        choose=14;

                    }
                }
        if(event->scenePos().x() > minion15->pos().x() && event->scenePos().x() <= minion15->pos().x()+130)
                {

                    if(event->scenePos().y() > minion15->pos().y() && event->scenePos().y() <= minion15->pos().y()+220)
                    {

                        setCursor(QString(":/images/minion15.png"));
                        choose=15;

                    }
                }
        if(event->scenePos().x() > minion16->pos().x() && event->scenePos().x() <= minion16->pos().x()+130)
                {

                    if(event->scenePos().y() > minion16->pos().y() && event->scenePos().y() <= minion16->pos().y()+220)
                    {

                        setCursor(QString(":/images/minion16.png"));
                        choose=16;

                    }
                }
        if(event->scenePos().x() > minion17->pos().x() && event->scenePos().x() <= minion17->pos().x()+130)
                {

                    if(event->scenePos().y() > minion17->pos().y() && event->scenePos().y() <= minion17->pos().y()+220)
                    {

                        setCursor(QString(":/images/minion17.png"));
                        choose=17;

                    }
                }
        if(event->scenePos().x() > minion18->pos().x() && event->scenePos().x() <= minion18->pos().x()+130)
                {

                    if(event->scenePos().y() > minion18->pos().y() && event->scenePos().y() <= minion18->pos().y()+220)
                    {

                        setCursor(QString(":/images/minion18.png"));
                        choose=18;

                    }
                }
        if(event->scenePos().x() > minion19->pos().x() && event->scenePos().x() <= minion19->pos().x()+130)
                {

                    if(event->scenePos().y() > minion19->pos().y() && event->scenePos().y() <= minion19->pos().y()+220)
                    {

                        setCursor(QString(":/images/minion19.png"));
                        choose=19;

                    }
                }
        if(event->scenePos().x() > minion20->pos().x() && event->scenePos().x() <= minion20->pos().x()+130)
                {

                    if(event->scenePos().y() > minion20->pos().y() && event->scenePos().y() <= minion20->pos().y()+220)
                    {

                        setCursor(QString(":/images/minion20.png"));
                        choose=20;

                    }
                }



        }
        else if((cursor)&& x==0){


            if(event->scenePos().x() > 280 && event->scenePos().x() <= 480 && event->scenePos().y() > 600 && event->scenePos().y() <= 800)
            {

                     this->addItem(cursor);
                     cursor->setPos(330,600);
                     cursor = nullptr;
                     minion_pick1=choose;

            }


            else if(event->scenePos().x() >530 && event->scenePos().x() <= 730 && event->scenePos().y() > 600 && event->scenePos().y() <= 800)
            {


                    this->addItem(cursor);
                    cursor->setPos(580,600);
                    cursor = nullptr;
                    minion_pick2=choose;

            }

            else if(event->scenePos().x() > 780 && event->scenePos().x() <= 980 && event->scenePos().y() > 600 && event->scenePos().y() <= 800)
            {


                    this->addItem(cursor);
                    cursor->setPos(830,600);
                    cursor = nullptr;
                    minion_pick3=choose;

            }

            else if(event->scenePos().x() > 1030 && event->scenePos().x() <= 1230 && event->scenePos().y() > 600 && event->scenePos().y() <= 800)
            {

                    this->addItem(cursor);
                    cursor->setPos(1080,600);
                    cursor = nullptr;
                    minion_pick4=choose;
                    x=1;



            }
            else{

                this->removeItem(cursor);
                cursor = nullptr;
            }

        }

        else if(x==1){
            if(event->scenePos().x() > btn_back->pos().x() && event->scenePos().x() <= btn_back->pos().x()+btn_small_w)
        {

            if(event->scenePos().y() > btn_back->pos().y() && event->scenePos().y() <= btn_back->pos().y()+btn_small_h)
            {

                bgRecover();
                screenMode = 0;
            }
        }
        }


    }

    else if(screenMode == 3)
    {

        if (!cursor){

        if(event->scenePos().x() > 350 && event->scenePos().x() <= 535)
                {

                    if(event->scenePos().y() > 718 && event->scenePos().y() <= 835)
                    {
                        get=1;
                        if(minion_pick1==1){
                            setCursor(QString(":/images/minion1.png"));
                        }
                        else if(minion_pick1==2){
                            setCursor(QString(":/images/minion2.png"));
                        }
                        else if(minion_pick1==3){
                            setCursor(QString(":/images/minion3.png"));
                        }
                        else if(minion_pick1==4){
                            setCursor(QString(":/images/minion4.png"));
                        }
                        else if(minion_pick1==5){
                            setCursor(QString(":/images/minion5.png"));
                        }
                        else if(minion_pick1==6){
                            setCursor(QString(":/images/minion6.png"));
                        }
                        else if(minion_pick1==7){
                            setCursor(QString(":/images/minion7.png"));
                        }
                        else if(minion_pick1==8){
                            setCursor(QString(":/images/minion8.png"));
                        }
                        else if(minion_pick1==9){
                            setCursor(QString(":/images/minion9.png"));
                        }
                        else if(minion_pick1==10){
                            setCursor(QString(":/images/minion10.png"));
                        }
                        else if(minion_pick1==11){
                            setCursor(QString(":/images/minion11.png"));
                        }
                        else if(minion_pick1==12){
                            setCursor(QString(":/images/minion12.png"));
                        }
                        else if(minion_pick1==13){
                            setCursor(QString(":/images/minion13.png"));
                        }
                        else if(minion_pick1==14){
                            setCursor(QString(":/images/minion14.png"));
                        }
                        else if(minion_pick1==15){
                            setCursor(QString(":/images/minion15.png"));
                        }
                        else if(minion_pick1==16){
                            setCursor(QString(":/images/minion16.png"));
                        }
                        else if(minion_pick1==17){
                            setCursor(QString(":/images/minion17.png"));
                        }
                        else if(minion_pick1==18){
                            setCursor(QString(":/images/minion18.png"));
                        }
                        else if(minion_pick1==19){
                            setCursor(QString(":/images/minion19.png"));
                        }
                        else {
                            setCursor(QString(":/images/minion20.png"));
                        }


                    }
                }


        if(event->scenePos().x() > 535 && event->scenePos().x() <= 725)
                {

                   if(event->scenePos().y() > 718 && event->scenePos().y() <= 835)
                    {
                       get=2;
                       if(minion_pick2==1){
                           setCursor(QString(":/images/minion1.png"));
                       }
                       else if(minion_pick2==2){
                           setCursor(QString(":/images/minion2.png"));
                       }
                       else if(minion_pick2==3){
                           setCursor(QString(":/images/minion3.png"));
                       }
                       else if(minion_pick2==4){
                           setCursor(QString(":/images/minion4.png"));
                       }
                       else if(minion_pick2==5){
                           setCursor(QString(":/images/minion5.png"));
                       }
                       else if(minion_pick2==6){
                           setCursor(QString(":/images/minion6.png"));
                       }
                       else if(minion_pick2==7){
                           setCursor(QString(":/images/minion7.png"));
                       }
                       else if(minion_pick2==8){
                           setCursor(QString(":/images/minion8.png"));
                       }
                       else if(minion_pick2==9){
                           setCursor(QString(":/images/minion9.png"));
                       }
                       else if(minion_pick2==10){
                           setCursor(QString(":/images/minion10.png"));
                       }
                       else if(minion_pick2==11){
                           setCursor(QString(":/images/minion11.png"));
                       }
                       else if(minion_pick2==12){
                           setCursor(QString(":/images/minion12.png"));
                       }
                       else if(minion_pick2==13){
                           setCursor(QString(":/images/minion13.png"));
                       }
                       else if(minion_pick2==14){
                           setCursor(QString(":/images/minion14.png"));
                       }
                       else if(minion_pick2==15){
                           setCursor(QString(":/images/minion15.png"));
                       }
                       else if(minion_pick2==16){
                           setCursor(QString(":/images/minion16.png"));
                       }
                       else if(minion_pick2==17){
                           setCursor(QString(":/images/minion17.png"));
                       }
                       else if(minion_pick2==18){
                           setCursor(QString(":/images/minion18.png"));
                       }
                       else if(minion_pick2==19){
                           setCursor(QString(":/images/minion19.png"));
                       }
                       else {
                           setCursor(QString(":/images/minion20.png"));
                       }

                    }
                }


        if(event->scenePos().x() > 725 && event->scenePos().x() <= 910)
                {

                    if(event->scenePos().y() > 718 && event->scenePos().y() <= 835)
                    {
                        get=3;
                        if(minion_pick3==1){
                            setCursor(QString(":/images/minion1.png"));
                        }
                        else if(minion_pick3==2){
                            setCursor(QString(":/images/minion2.png"));
                        }
                        else if(minion_pick3==3){
                            setCursor(QString(":/images/minion3.png"));
                        }
                        else if(minion_pick3==4){
                            setCursor(QString(":/images/minion4.png"));
                        }
                        else if(minion_pick3==5){
                            setCursor(QString(":/images/minion5.png"));
                        }
                        else if(minion_pick3==6){
                            setCursor(QString(":/images/minion6.png"));
                        }
                        else if(minion_pick3==7){
                            setCursor(QString(":/images/minion7.png"));
                        }
                        else if(minion_pick3==8){
                            setCursor(QString(":/images/minion8.png"));
                        }
                        else if(minion_pick3==9){
                            setCursor(QString(":/images/minion9.png"));
                        }
                        else if(minion_pick3==10){
                            setCursor(QString(":/images/minion10.png"));
                        }
                        else if(minion_pick3==11){
                            setCursor(QString(":/images/minion11.png"));
                        }
                        else if(minion_pick3==12){
                            setCursor(QString(":/images/minion12.png"));
                        }
                        else if(minion_pick3==13){
                            setCursor(QString(":/images/minion13.png"));
                        }
                        else if(minion_pick3==14){
                            setCursor(QString(":/images/minion14.png"));
                        }
                        else if(minion_pick3==15){
                            setCursor(QString(":/images/minion15.png"));
                        }
                        else if(minion_pick3==16){
                            setCursor(QString(":/images/minion16.png"));
                        }
                        else if(minion_pick3==17){
                            setCursor(QString(":/images/minion17.png"));
                        }
                        else if(minion_pick3==18){
                            setCursor(QString(":/images/minion18.png"));
                        }
                        else if(minion_pick3==19){
                            setCursor(QString(":/images/minion19.png"));
                        }
                        else {
                            setCursor(QString(":/images/minion20.png"));
                        }


                    }
                }


        if(event->scenePos().x() > 910 && event->scenePos().x() <= 1100)
                {

                   if(event->scenePos().y() > 718 && event->scenePos().y() <= 835)
                    {
                       get=4;
                       if(minion_pick4==1){
                           setCursor(QString(":/images/minion1.png"));
                       }
                       else if(minion_pick4==2){
                           setCursor(QString(":/images/minion2.png"));
                       }
                       else if(minion_pick4==3){
                           setCursor(QString(":/images/minion3.png"));
                       }
                       else if(minion_pick4==4){
                           setCursor(QString(":/images/minion4.png"));
                       }
                       else if(minion_pick4==5){
                           setCursor(QString(":/images/minion5.png"));
                       }
                       else if(minion_pick4==6){
                           setCursor(QString(":/images/minion6.png"));
                       }
                       else if(minion_pick4==7){
                           setCursor(QString(":/images/minion7.png"));
                       }
                       else if(minion_pick4==8){
                           setCursor(QString(":/images/minion8.png"));
                       }
                       else if(minion_pick4==9){
                           setCursor(QString(":/images/minion9.png"));
                       }
                       else if(minion_pick4==10){
                           setCursor(QString(":/images/minion10.png"));
                       }
                       else if(minion_pick4==11){
                           setCursor(QString(":/images/minion11.png"));
                       }
                       else if(minion_pick4==12){
                           setCursor(QString(":/images/minion12.png"));
                       }
                       else if(minion_pick4==13){
                           setCursor(QString(":/images/minion13.png"));
                       }
                       else if(minion_pick4==14){
                           setCursor(QString(":/images/minion14.png"));
                       }
                       else if(minion_pick4==15){
                           setCursor(QString(":/images/minion15.png"));
                       }
                       else if(minion_pick4==16){
                           setCursor(QString(":/images/minion16.png"));
                       }
                       else if(minion_pick4==17){
                           setCursor(QString(":/images/minion17.png"));
                       }
                       else if(minion_pick4==18){
                           setCursor(QString(":/images/minion18.png"));
                       }
                       else if(minion_pick4==19){
                           setCursor(QString(":/images/minion19.png"));
                       }
                       else {
                           setCursor(QString(":/images/minion20.png"));
                       }


                    }
                }


        }

        else{

                     if(get==1){
                         if(minion_pick1==1){
                             minion1_start = new minion_1();
                             this->addItem(minion1_start);
                             minion1_start->setPos(event->scenePos());
                             this->removeItem(cursor);
                             cursor = nullptr;

                             QObject::connect(timer,SIGNAL(timeout()), minion1_start,SLOT(move()));

                         }
                         else if(minion_pick1==2){
                             minion2_start = new minion_2();
                             this->addItem(minion2_start);
                             minion2_start->setPos(event->scenePos());
                             this->removeItem(cursor);
                             cursor = nullptr;
                             QObject::connect(timer,SIGNAL(timeout()), minion2_start,SLOT(move()));
                         }
                         else if(minion_pick1==3){
                             minion3_start = new minion_3();
                             this->addItem(minion3_start);
                             minion3_start->setPos(event->scenePos());
                             this->removeItem(cursor);
                             cursor = nullptr;
                             QObject::connect(timer,SIGNAL(timeout()), minion3_start,SLOT(move()));
                         }
                         else if(minion_pick1==4){
                             minion4_start = new minion_4();
                             this->addItem(minion4_start);
                             minion4_start->setPos(event->scenePos());
                             this->removeItem(cursor);
                             cursor = nullptr;
                             QObject::connect(timer,SIGNAL(timeout()), minion4_start,SLOT(move()));
                         }
                         else if(minion_pick1==5){
                             minion5_start = new minion_5();
                             this->addItem(minion5_start);
                             minion5_start->setPos(event->scenePos());
                             this->removeItem(cursor);
                             cursor = nullptr;
                             QObject::connect(timer,SIGNAL(timeout()), minion5_start,SLOT(move()));
                         }
                         else if(minion_pick1==6){
                             minion6_start = new minion_6();
                             this->addItem(minion6_start);
                             minion6_start->setPos(event->scenePos());
                             this->removeItem(cursor);
                             cursor = nullptr;
                             QObject::connect(timer,SIGNAL(timeout()), minion6_start,SLOT(move()));
                         }
                         else if(minion_pick1==7){
                             minion7_start = new minion_7();
                             this->addItem(minion7_start);
                             minion7_start->setPos(event->scenePos());
                             this->removeItem(cursor);
                             cursor = nullptr;
                             QObject::connect(timer,SIGNAL(timeout()), minion7_start,SLOT(move()));
                         }
                         else if(minion_pick1==8){
                             minion8_start = new minion_8();
                             this->addItem(minion8_start);
                             minion8_start->setPos(event->scenePos());
                             this->removeItem(cursor);
                             cursor = nullptr;
                             QObject::connect(timer,SIGNAL(timeout()), minion8_start,SLOT(move()));
                         }
                         else if(minion_pick1==9){
                             minion9_start = new minion_9();
                             this->addItem(minion9_start);
                             minion9_start->setPos(event->scenePos());
                             this->removeItem(cursor);
                             cursor = nullptr;
                             QObject::connect(timer,SIGNAL(timeout()), minion9_start,SLOT(move()));
                         }
                         else if(minion_pick1==10){
                             minion10_start = new minion_10();
                             this->addItem(minion10_start);
                             minion10_start->setPos(event->scenePos());
                             this->removeItem(cursor);
                             cursor = nullptr;
                             QObject::connect(timer,SIGNAL(timeout()), minion10_start,SLOT(move()));
                         }
                         else if(minion_pick1==11){
                             minion11_start = new minion_11();
                             this->addItem(minion11_start);
                             minion11_start->setPos(event->scenePos());
                             this->removeItem(cursor);
                             cursor = nullptr;
                             QObject::connect(timer,SIGNAL(timeout()), minion11_start,SLOT(move()));
                         }
                         else if(minion_pick1==12){
                             minion12_start = new minion_12();
                             this->addItem(minion12_start);
                             minion12_start->setPos(event->scenePos());
                             this->removeItem(cursor);
                             cursor = nullptr;
                             QObject::connect(timer,SIGNAL(timeout()), minion12_start,SLOT(move()));
                         }
                         else if(minion_pick1==13){
                             minion13_start = new minion_13();
                             this->addItem(minion13_start);
                             minion13_start->setPos(event->scenePos());
                             this->removeItem(cursor);
                             cursor = nullptr;
                             QObject::connect(timer,SIGNAL(timeout()), minion13_start,SLOT(move()));
                         }
                         else if(minion_pick1==14){
                             minion14_start = new minion_14();
                             this->addItem(minion14_start);
                             minion14_start->setPos(event->scenePos());
                             this->removeItem(cursor);
                             cursor = nullptr;
                             QObject::connect(timer,SIGNAL(timeout()), minion14_start,SLOT(move()));
                         }
                         else if(minion_pick1==15){
                             minion15_start = new minion_15();
                             this->addItem(minion15_start);
                             minion15_start->setPos(event->scenePos());
                             this->removeItem(cursor);
                             cursor = nullptr;
                             QObject::connect(timer,SIGNAL(timeout()), minion15_start,SLOT(move()));
                         }
                         else if(minion_pick1==16){
                             minion16_start = new minion_16();
                             this->addItem(minion16_start);
                             minion16_start->setPos(event->scenePos());
                             this->removeItem(cursor);
                             cursor = nullptr;
                             QObject::connect(timer,SIGNAL(timeout()), minion16_start,SLOT(move()));
                         }
                         else if(minion_pick1==17){
                             minion17_start = new minion_17();
                             this->addItem(minion17_start);
                             minion17_start->setPos(event->scenePos());
                             this->removeItem(cursor);
                             cursor = nullptr;
                             QObject::connect(timer,SIGNAL(timeout()), minion17_start,SLOT(move()));
                         }
                         else if(minion_pick1==18){
                             minion18_start = new minion_18();
                             this->addItem(minion18_start);
                             minion18_start->setPos(event->scenePos());
                             this->removeItem(cursor);
                             cursor = nullptr;
                             QObject::connect(timer,SIGNAL(timeout()), minion18_start,SLOT(move()));
                         }
                         else if(minion_pick1==19){
                             minion19_start = new minion_19();
                             this->addItem(minion19_start);
                             minion19_start->setPos(event->scenePos());
                             this->removeItem(cursor);
                             cursor = nullptr;
                             QObject::connect(timer,SIGNAL(timeout()), minion19_start,SLOT(move()));
                         }
                         else {
                             minion20_start = new minion_20();
                             this->addItem(minion20_start);
                             minion20_start->setPos(event->scenePos());
                             this->removeItem(cursor);
                             cursor = nullptr;
                             QObject::connect(timer,SIGNAL(timeout()), minion20_start,SLOT(move()));
                         }

                     }

                     if(get==2){
                         if(minion_pick2==1){
                             minion1_start = new minion_1();
                             this->addItem(minion1_start);
                             minion1_start->setPos(event->scenePos());
                             this->removeItem(cursor);
                             cursor = nullptr;
                             QObject::connect(timer,SIGNAL(timeout()), minion1_start,SLOT(move()));
                         }
                         else if(minion_pick2==2){
                             minion2_start = new minion_2();
                             this->addItem(minion2_start);
                             minion2_start->setPos(event->scenePos());
                             this->removeItem(cursor);
                             cursor = nullptr;
                             QObject::connect(timer,SIGNAL(timeout()), minion2_start,SLOT(move()));
                         }
                         else if(minion_pick2==3){
                             minion3_start = new minion_3();
                             this->addItem(minion3_start);
                             minion3_start->setPos(event->scenePos());
                             this->removeItem(cursor);
                             cursor = nullptr;
                             QObject::connect(timer,SIGNAL(timeout()), minion3_start,SLOT(move()));
                         }
                         else if(minion_pick2==4){
                             minion4_start = new minion_4();
                             this->addItem(minion4_start);
                             minion4_start->setPos(event->scenePos());
                             this->removeItem(cursor);
                             cursor = nullptr;
                             QObject::connect(timer,SIGNAL(timeout()), minion4_start,SLOT(move()));
                         }
                         else if(minion_pick2==5){
                             minion5_start = new minion_5();
                             this->addItem(minion5_start);
                             minion5_start->setPos(event->scenePos());
                             this->removeItem(cursor);
                             cursor = nullptr;
                             QObject::connect(timer,SIGNAL(timeout()), minion5_start,SLOT(move()));
                         }
                         else if(minion_pick2==6){
                             minion6_start = new minion_6();
                             this->addItem(minion6_start);
                             minion6_start->setPos(event->scenePos());
                             this->removeItem(cursor);
                             cursor = nullptr;
                             QObject::connect(timer,SIGNAL(timeout()), minion6_start,SLOT(move()));
                         }
                         else if(minion_pick2==7){
                             minion7_start = new minion_7();
                             this->addItem(minion7_start);
                             minion7_start->setPos(event->scenePos());
                             this->removeItem(cursor);
                             cursor = nullptr;
                             QObject::connect(timer,SIGNAL(timeout()), minion7_start,SLOT(move()));
                         }
                         else if(minion_pick2==8){
                             minion8_start = new minion_8();
                             this->addItem(minion8_start);
                             minion8_start->setPos(event->scenePos());
                             this->removeItem(cursor);
                             cursor = nullptr;
                             QObject::connect(timer,SIGNAL(timeout()), minion8_start,SLOT(move()));
                         }
                         else if(minion_pick2==9){
                             minion9_start = new minion_9();
                             this->addItem(minion9_start);
                             minion9_start->setPos(event->scenePos());
                             this->removeItem(cursor);
                             cursor = nullptr;
                             QObject::connect(timer,SIGNAL(timeout()), minion9_start,SLOT(move()));
                         }
                         else if(minion_pick2==10){
                             minion10_start = new minion_10();
                             this->addItem(minion10_start);
                             minion10_start->setPos(event->scenePos());
                             this->removeItem(cursor);
                             cursor = nullptr;
                             QObject::connect(timer,SIGNAL(timeout()), minion10_start,SLOT(move()));
                         }
                         else if(minion_pick2==11){
                             minion11_start = new minion_11();
                             this->addItem(minion11_start);
                             minion11_start->setPos(event->scenePos());
                             this->removeItem(cursor);
                             cursor = nullptr;
                             QObject::connect(timer,SIGNAL(timeout()), minion11_start,SLOT(move()));
                         }
                         else if(minion_pick2==12){
                             minion12_start = new minion_12();
                             this->addItem(minion12_start);
                             minion12_start->setPos(event->scenePos());
                             this->removeItem(cursor);
                             cursor = nullptr;
                             QObject::connect(timer,SIGNAL(timeout()), minion12_start,SLOT(move()));
                         }
                         else if(minion_pick2==13){
                             minion13_start = new minion_13();
                             this->addItem(minion13_start);
                             minion13_start->setPos(event->scenePos());
                             this->removeItem(cursor);
                             cursor = nullptr;
                             QObject::connect(timer,SIGNAL(timeout()), minion13_start,SLOT(move()));
                         }
                         else if(minion_pick2==14){
                             minion14_start = new minion_14();
                             this->addItem(minion14_start);
                             minion14_start->setPos(event->scenePos());
                             this->removeItem(cursor);
                             cursor = nullptr;
                             QObject::connect(timer,SIGNAL(timeout()), minion14_start,SLOT(move()));
                         }
                         else if(minion_pick2==15){
                             minion15_start = new minion_15();
                             this->addItem(minion15_start);
                             minion15_start->setPos(event->scenePos());
                             this->removeItem(cursor);
                             cursor = nullptr;
                             QObject::connect(timer,SIGNAL(timeout()), minion15_start,SLOT(move()));
                         }
                         else if(minion_pick2==16){
                             minion16_start = new minion_16();
                             this->addItem(minion16_start);
                             minion16_start->setPos(event->scenePos());
                             this->removeItem(cursor);
                             cursor = nullptr;
                             QObject::connect(timer,SIGNAL(timeout()), minion16_start,SLOT(move()));
                         }
                         else if(minion_pick2==17){
                             minion17_start = new minion_17();
                             this->addItem(minion17_start);
                             minion17_start->setPos(event->scenePos());
                             this->removeItem(cursor);
                             cursor = nullptr;
                             QObject::connect(timer,SIGNAL(timeout()), minion17_start,SLOT(move()));
                         }
                         else if(minion_pick2==18){
                             minion18_start = new minion_18();
                             this->addItem(minion18_start);
                             minion18_start->setPos(event->scenePos());
                             this->removeItem(cursor);
                             cursor = nullptr;
                             QObject::connect(timer,SIGNAL(timeout()), minion18_start,SLOT(move()));
                         }
                         else if(minion_pick2==19){
                             minion19_start = new minion_19();
                             this->addItem(minion19_start);
                             minion19_start->setPos(event->scenePos());
                             this->removeItem(cursor);
                             cursor = nullptr;
                             QObject::connect(timer,SIGNAL(timeout()), minion19_start,SLOT(move()));
                         }
                         else {
                             minion20_start = new minion_20();
                             this->addItem(minion20_start);
                             minion20_start->setPos(event->scenePos());
                             this->removeItem(cursor);
                             cursor = nullptr;
                             QObject::connect(timer,SIGNAL(timeout()), minion20_start,SLOT(move()));
                         }

                     }

                     if(get==3){
                         if(minion_pick3==1){
                             minion1_start = new minion_1();
                             this->addItem(minion1_start);
                             minion1_start->setPos(event->scenePos());
                             this->removeItem(cursor);
                             cursor = nullptr;
                             QObject::connect(timer,SIGNAL(timeout()), minion1_start,SLOT(move()));
                         }
                         else if(minion_pick3==2){
                             minion2_start = new minion_2();
                             this->addItem(minion2_start);
                             minion2_start->setPos(event->scenePos());
                             this->removeItem(cursor);
                             cursor = nullptr;
                             QObject::connect(timer,SIGNAL(timeout()), minion2_start,SLOT(move()));
                         }
                         else if(minion_pick3==3){
                             minion3_start = new minion_3();
                             this->addItem(minion3_start);
                             minion3_start->setPos(event->scenePos());
                             this->removeItem(cursor);
                             cursor = nullptr;
                             QObject::connect(timer,SIGNAL(timeout()), minion3_start,SLOT(move()));
                         }
                         else if(minion_pick3==4){
                             minion4_start = new minion_4();
                             this->addItem(minion4_start);
                             minion4_start->setPos(event->scenePos());
                             this->removeItem(cursor);
                             cursor = nullptr;
                             QObject::connect(timer,SIGNAL(timeout()), minion4_start,SLOT(move()));
                         }
                         else if(minion_pick3==5){
                             minion5_start = new minion_5();
                             this->addItem(minion5_start);
                             minion5_start->setPos(event->scenePos());
                             this->removeItem(cursor);
                             cursor = nullptr;
                             QObject::connect(timer,SIGNAL(timeout()), minion5_start,SLOT(move()));
                         }
                         else if(minion_pick3==6){
                             minion6_start = new minion_6();
                             this->addItem(minion6_start);
                             minion6_start->setPos(event->scenePos());
                             this->removeItem(cursor);
                             cursor = nullptr;
                             QObject::connect(timer,SIGNAL(timeout()), minion6_start,SLOT(move()));
                         }
                         else if(minion_pick3==7){
                             minion7_start = new minion_7();
                             this->addItem(minion7_start);
                             minion7_start->setPos(event->scenePos());
                             this->removeItem(cursor);
                             cursor = nullptr;
                             QObject::connect(timer,SIGNAL(timeout()), minion7_start,SLOT(move()));
                         }
                         else if(minion_pick3==8){
                             minion8_start = new minion_8();
                             this->addItem(minion8_start);
                             minion8_start->setPos(event->scenePos());
                             this->removeItem(cursor);
                             cursor = nullptr;
                             QObject::connect(timer,SIGNAL(timeout()), minion8_start,SLOT(move()));
                         }
                         else if(minion_pick3==9){
                             minion9_start = new minion_9();
                             this->addItem(minion9_start);
                             minion9_start->setPos(event->scenePos());
                             this->removeItem(cursor);
                             cursor = nullptr;
                             QObject::connect(timer,SIGNAL(timeout()), minion9_start,SLOT(move()));
                         }
                         else if(minion_pick3==10){
                             minion10_start = new minion_10();
                             this->addItem(minion10_start);
                             minion10_start->setPos(event->scenePos());
                             this->removeItem(cursor);
                             cursor = nullptr;
                             QObject::connect(timer,SIGNAL(timeout()), minion10_start,SLOT(move()));
                         }
                         else if(minion_pick3==11){
                             minion11_start = new minion_11();
                             this->addItem(minion11_start);
                             minion11_start->setPos(event->scenePos());
                             this->removeItem(cursor);
                             cursor = nullptr;
                             QObject::connect(timer,SIGNAL(timeout()), minion11_start,SLOT(move()));
                         }
                         else if(minion_pick3==12){
                             minion12_start = new minion_12();
                             this->addItem(minion12_start);
                             minion12_start->setPos(event->scenePos());
                             this->removeItem(cursor);
                             cursor = nullptr;
                             QObject::connect(timer,SIGNAL(timeout()), minion12_start,SLOT(move()));
                         }
                         else if(minion_pick3==13){
                             minion13_start = new minion_13();
                             this->addItem(minion13_start);
                             minion13_start->setPos(event->scenePos());
                             this->removeItem(cursor);
                             cursor = nullptr;
                             QObject::connect(timer,SIGNAL(timeout()), minion13_start,SLOT(move()));
                         }
                         else if(minion_pick3==14){
                             minion14_start = new minion_14();
                             this->addItem(minion14_start);
                             minion14_start->setPos(event->scenePos());
                             this->removeItem(cursor);
                             cursor = nullptr;
                             QObject::connect(timer,SIGNAL(timeout()), minion14_start,SLOT(move()));
                         }
                         else if(minion_pick3==15){
                             minion15_start = new minion_15();
                             this->addItem(minion15_start);
                             minion15_start->setPos(event->scenePos());
                             this->removeItem(cursor);
                             cursor = nullptr;
                             QObject::connect(timer,SIGNAL(timeout()), minion15_start,SLOT(move()));
                         }
                         else if(minion_pick3==16){
                             minion16_start = new minion_16();
                             this->addItem(minion16_start);
                             minion16_start->setPos(event->scenePos());
                             this->removeItem(cursor);
                             cursor = nullptr;
                             QObject::connect(timer,SIGNAL(timeout()), minion16_start,SLOT(move()));
                         }
                         else if(minion_pick3==17){
                             minion17_start = new minion_17();
                             this->addItem(minion17_start);
                             minion17_start->setPos(event->scenePos());
                             this->removeItem(cursor);
                             cursor = nullptr;
                             QObject::connect(timer,SIGNAL(timeout()), minion17_start,SLOT(move()));
                         }
                         else if(minion_pick3==18){
                             minion18_start = new minion_18();
                             this->addItem(minion18_start);
                             minion18_start->setPos(event->scenePos());
                             this->removeItem(cursor);
                             cursor = nullptr;
                             QObject::connect(timer,SIGNAL(timeout()), minion18_start,SLOT(move()));
                         }
                         else if(minion_pick3==19){
                             minion19_start = new minion_19();
                             this->addItem(minion19_start);
                             minion19_start->setPos(event->scenePos());
                             this->removeItem(cursor);
                             cursor = nullptr;
                             QObject::connect(timer,SIGNAL(timeout()), minion19_start,SLOT(move()));
                         }
                         else {
                             minion20_start = new minion_20();
                             this->addItem(minion20_start);
                             minion20_start->setPos(event->scenePos());
                             this->removeItem(cursor);
                             cursor = nullptr;
                             QObject::connect(timer,SIGNAL(timeout()), minion20_start,SLOT(move()));
                         }

                     }

                     if(get==4){
                         if(minion_pick4==1){
                             minion1_start = new minion_1();
                             this->addItem(minion1_start);
                             minion1_start->setPos(event->scenePos());
                             this->removeItem(cursor);
                             cursor = nullptr;
                             QObject::connect(timer,SIGNAL(timeout()), minion1_start,SLOT(move()));
                         }
                         else if(minion_pick4==2){
                             minion2_start = new minion_2();
                             this->addItem(minion2_start);
                             minion2_start->setPos(event->scenePos());
                             this->removeItem(cursor);
                             cursor = nullptr;
                             QObject::connect(timer,SIGNAL(timeout()), minion2_start,SLOT(move()));
                         }
                         else if(minion_pick4==3){
                             minion3_start = new minion_3();
                             this->addItem(minion3_start);
                             minion3_start->setPos(event->scenePos());
                             this->removeItem(cursor);
                             cursor = nullptr;
                             QObject::connect(timer,SIGNAL(timeout()), minion3_start,SLOT(move()));
                         }
                         else if(minion_pick4==4){
                             minion4_start = new minion_4();
                             this->addItem(minion4_start);
                             minion4_start->setPos(event->scenePos());
                             this->removeItem(cursor);
                             cursor = nullptr;
                             QObject::connect(timer,SIGNAL(timeout()), minion4_start,SLOT(move()));
                         }
                         else if(minion_pick4==5){
                             minion5_start = new minion_5();
                             this->addItem(minion5_start);
                             minion5_start->setPos(event->scenePos());
                             this->removeItem(cursor);
                             cursor = nullptr;
                             QObject::connect(timer,SIGNAL(timeout()), minion5_start,SLOT(move()));
                         }
                         else if(minion_pick4==6){
                             minion6_start = new minion_6();
                             this->addItem(minion6_start);
                             minion6_start->setPos(event->scenePos());
                             this->removeItem(cursor);
                             cursor = nullptr;
                             QObject::connect(timer,SIGNAL(timeout()), minion6_start,SLOT(move()));
                         }
                         else if(minion_pick4==7){
                             minion7_start = new minion_7();
                             this->addItem(minion7_start);
                             minion7_start->setPos(event->scenePos());
                             this->removeItem(cursor);
                             cursor = nullptr;
                             QObject::connect(timer,SIGNAL(timeout()), minion7_start,SLOT(move()));
                         }
                         else if(minion_pick4==8){
                             minion8_start = new minion_8();
                             this->addItem(minion8_start);
                             minion8_start->setPos(event->scenePos());
                             this->removeItem(cursor);
                             cursor = nullptr;
                             QObject::connect(timer,SIGNAL(timeout()), minion8_start,SLOT(move()));
                         }
                         else if(minion_pick4==9){
                             minion9_start = new minion_9();
                             this->addItem(minion9_start);
                             minion9_start->setPos(event->scenePos());
                             this->removeItem(cursor);
                             cursor = nullptr;
                             QObject::connect(timer,SIGNAL(timeout()), minion9_start,SLOT(move()));
                         }
                         else if(minion_pick4==10){
                             minion10_start = new minion_10();
                             this->addItem(minion10_start);
                             minion10_start->setPos(event->scenePos());
                             this->removeItem(cursor);
                             cursor = nullptr;
                             QObject::connect(timer,SIGNAL(timeout()), minion10_start,SLOT(move()));
                         }
                         else if(minion_pick4==11){
                             minion11_start = new minion_11();
                             this->addItem(minion11_start);
                             minion11_start->setPos(event->scenePos());
                             this->removeItem(cursor);
                             cursor = nullptr;
                             QObject::connect(timer,SIGNAL(timeout()), minion11_start,SLOT(move()));
                         }
                         else if(minion_pick4==12){
                             minion12_start = new minion_12();
                             this->addItem(minion12_start);
                             minion12_start->setPos(event->scenePos());
                             this->removeItem(cursor);
                             cursor = nullptr;
                             QObject::connect(timer,SIGNAL(timeout()), minion12_start,SLOT(move()));
                         }
                         else if(minion_pick4==13){
                             minion13_start = new minion_13();
                             this->addItem(minion13_start);
                             minion13_start->setPos(event->scenePos());
                             this->removeItem(cursor);
                             cursor = nullptr;
                             QObject::connect(timer,SIGNAL(timeout()), minion13_start,SLOT(move()));
                         }
                         else if(minion_pick4==14){
                             minion14_start = new minion_14();
                             this->addItem(minion14_start);
                             minion14_start->setPos(event->scenePos());
                             this->removeItem(cursor);
                             cursor = nullptr;
                             QObject::connect(timer,SIGNAL(timeout()), minion14_start,SLOT(move()));
                         }
                         else if(minion_pick4==15){
                             minion15_start = new minion_15();
                             this->addItem(minion15_start);
                             minion15_start->setPos(event->scenePos());
                             this->removeItem(cursor);
                             cursor = nullptr;
                             QObject::connect(timer,SIGNAL(timeout()), minion15_start,SLOT(move()));
                         }
                         else if(minion_pick4==16){
                             minion16_start = new minion_16();
                             this->addItem(minion16_start);
                             minion16_start->setPos(event->scenePos());
                             this->removeItem(cursor);
                             cursor = nullptr;
                             QObject::connect(timer,SIGNAL(timeout()), minion16_start,SLOT(move()));
                         }
                         else if(minion_pick4==17){
                             minion17_start = new minion_17();
                             this->addItem(minion17_start);
                             minion17_start->setPos(event->scenePos());
                             this->removeItem(cursor);
                             cursor = nullptr;
                             QObject::connect(timer,SIGNAL(timeout()), minion17_start,SLOT(move()));
                         }
                         else if(minion_pick4==18){
                             minion18_start = new minion_18();
                             this->addItem(minion18_start);
                             minion18_start->setPos(event->scenePos());
                             this->removeItem(cursor);
                             cursor = nullptr;
                             QObject::connect(timer,SIGNAL(timeout()), minion18_start,SLOT(move()));
                         }
                         else if(minion_pick4==19){
                             minion19_start = new minion_19();
                             this->addItem(minion19_start);
                             minion19_start->setPos(event->scenePos());
                             this->removeItem(cursor);
                             cursor = nullptr;
                             QObject::connect(timer,SIGNAL(timeout()), minion19_start,SLOT(move()));
                         }
                         else {
                             minion20_start = new minion_20();
                             this->addItem(minion20_start);
                             minion20_start->setPos(event->scenePos());
                             this->removeItem(cursor);
                             cursor = nullptr;
                             QObject::connect(timer,SIGNAL(timeout()), minion20_start,SLOT(move()));
                         }

                     }





            }
        }





    cout << "btn start x: " << btn_start->pos().x()<< " btn start y: " << btn_start->pos().y() << endl;
    cout << "Now event x: " << event->scenePos().x()<< " event y: " << event->scenePos().y() << endl;
    cout<< minion_pick1<<endl;
}








void Scene::bgChange_minion()
{

    QImage bg;
    bg.load(":/images/bg_choose.jpg");
    this->setBackgroundBrush(bg);

    this->removeItem(btn_start);
    this->removeItem(btn_choose_hero);
    this->removeItem(btn_choose_minion);




    minion1 = new minion();
    QPixmap m1;
    m1.load(":/images/minion1.png");
    minion1->setPixmap(m1);
    minion1->setPos(10,80);
    addItem(minion1);

    minion2 = new minion();
    QPixmap m2;
    m2.load(":/images/minion2.png");
    minion2->setPixmap(m2);
    minion2->setPos(160,80);
    addItem(minion2);

    minion3 = new minion();
    QPixmap m3;
    m3.load(":/images/minion3.png");
    minion3->setPixmap(m3);
    minion3->setPos(310,80);
    addItem(minion3);

    minion4 = new minion();
    QPixmap m4;
    m4.load(":/images/minion4.png");
    minion4->setPixmap(m4);
    minion4->setPos(460,80);
    addItem(minion4);

    minion5 = new minion();
    QPixmap m5;
    m5.load(":/images/minion5.png");
    minion5->setPixmap(m5);
    minion5->setPos(610,80);
    addItem(minion5);

    minion6 = new minion();
    QPixmap m6;
    m6.load(":/images/minion6.png");
    minion6->setPixmap(m6);
    minion6->setPos(760,90);
    addItem(minion6);

    minion7 = new minion();
    QPixmap m7;
    m7.load(":/images/minion7.png");
    minion7->setPixmap(m7);
    minion7->setPos(910,80);
    addItem(minion7);

    minion8 = new minion();
    QPixmap m8;
    m8.load(":/images/minion8.png");
    minion8->setPixmap(m8);
    minion8->setPos(1060,75);
    addItem(minion8);

    minion9 = new minion();
    QPixmap m9;
    m9.load(":/images/minion9.png");
    minion9->setPixmap(m9);
    minion9->setPos(1210,95);
    addItem(minion9);

    minion10 = new minion();
    QPixmap m10;
    m10.load(":/images/minion10.png");
    minion10->setPixmap(m10);
    minion10->setPos(1360,80);
    addItem(minion10);

    minion11 = new minion();
    QPixmap m11;
    m11.load(":/images/minion11.png");
    minion11->setPixmap(m11);
    minion11->setPos(10,350);
    addItem(minion11);

    minion12 = new minion();
    QPixmap m12;
    m12.load(":/images/minion12.png");
    minion12->setPixmap(m12);
    minion12->setPos(160,370);
    addItem(minion12);

    minion13 = new minion();
    QPixmap m13;
    m13.load(":/images/minion13.png");
    minion13->setPixmap(m13);
    minion13->setPos(310,350);
    addItem(minion13);

    minion14 = new minion();
    QPixmap m14;
    m14.load(":/images/minion14.png");
    minion14->setPixmap(m14);
    minion14->setPos(460,335);
    addItem(minion14);

    minion15 = new minion();
    QPixmap m15;
    m15.load(":/images/minion15.png");
    minion15->setPixmap(m15);
    minion15->setPos(610,350);
    addItem(minion15);

    minion16 = new minion();
    QPixmap m16;
    m16.load(":/images/minion16.png");
    minion16->setPixmap(m16);
    minion16->setPos(760,370);
    addItem(minion16);

    minion17 = new minion();
    QPixmap m17;
    m17.load(":/images/minion17.png");
    minion17->setPixmap(m17);
    minion17->setPos(910,360);
    addItem(minion17);

    minion18 = new minion();
    QPixmap m18;
    m18.load(":/images/minion18.png");
    minion18->setPixmap(m18);
    minion18->setPos(1060,360);
    addItem(minion18);

    minion19 = new minion();
    QPixmap m19;
    m19.load(":/images/minion19.png");
    minion19->setPixmap(m19);
    minion19->setPos(1210,360);
    addItem(minion19);

    minion20 = new minion();
    QPixmap m20;
    m20.load(":/images/minion20.png");
    minion20->setPixmap(m20);
    minion20->setPos(1360,350);
    addItem(minion20);

    minion_pick1_rect = new QGraphicsRectItem();
    minion_pick1_rect->setRect(280,600,200,200);
    minion_pick1_rect->setPen((QPen(Qt::red, 4, Qt::SolidLine)));
    addItem(minion_pick1_rect);

    minion_pick2_rect = new QGraphicsRectItem();
    minion_pick2_rect->setRect(530,600,200,200);
    minion_pick2_rect->setPen((QPen(Qt::red, 4, Qt::SolidLine)));
    addItem(minion_pick2_rect);

    minion_pick3_rect = new QGraphicsRectItem();
    minion_pick3_rect->setRect(780,600,200,200);
    minion_pick3_rect->setPen((QPen(Qt::red, 4, Qt::SolidLine)));
    addItem(minion_pick3_rect);

    minion_pick4_rect = new QGraphicsRectItem();
    minion_pick4_rect->setRect(1030,600,200,200);
    minion_pick4_rect->setPen((QPen(Qt::red, 4, Qt::SolidLine)));
    addItem(minion_pick4_rect);


    btn_back = new btn();
    QPixmap bk;
    bk.load(":/images/btn_back.png");
    btn_small_w = bk.width()*1/3;
    btn_small_h = bk.height()*1/3;
    bk = bk.scaled(btn_small_w , btn_small_h ,Qt::KeepAspectRatio);
    btn_back->setPixmap(bk);
    btn_back->setPos(3,3);
    addItem(btn_back);
}

void Scene::bgChange_hero()
{

    QImage bg;
    bg.load(":/images/bg_choose.jpg");
    this->setBackgroundBrush(bg);

    this->removeItem(btn_start);
    this->removeItem(btn_choose_hero);
    this->removeItem(btn_choose_minion);

    hero1 = new hero();
    QPixmap h1;
    h1.load(":/images/hero1.png");
    hero1->setPixmap(h1);
    hero1->setPos(350,200);
    addItem(hero1);

    hero2 = new hero();
    QPixmap h2;
    h2.load(":/images/hero2.png");
    hero2->setPixmap(h2);
    hero2->setPos(650,200);
    addItem(hero2);

    hero3 = new hero();
    QPixmap h3;
    h3.load(":/images/hero3.png");
    hero3->setPixmap(h3);
    hero3->setPos(950,200);
    addItem(hero3);

    hero_pick_rect = new QGraphicsRectItem();
    hero_pick_rect->setRect(600,600,200,200);
    hero_pick_rect->setPen((QPen(Qt::red, 4, Qt::SolidLine)));
    addItem(hero_pick_rect);

    btn_back = new btn();
    QPixmap bk;
    bk.load(":/images/btn_back.png");
    btn_small_w = bk.width()*1/3;
    btn_small_h = bk.height()*1/3;
    bk = bk.scaled(btn_small_w , btn_small_h ,Qt::KeepAspectRatio);
    btn_back->setPixmap(bk);
    btn_back->setPos(3,3);
    addItem(btn_back);
}

void Scene::bgChange_start()
{
    QImage bg;
    bg.load(":/images/bg_start.jpg");
    this->setBackgroundBrush(bg);

    this->removeItem(btn_start);
    this->removeItem(btn_choose_hero);
    this->removeItem(btn_choose_minion);



    my_tower_start = new my_tower();
    my_tower_start->setPos(-300,20);
    this->addItem(my_tower_start);

    enemy_tower_start = new enemy_tower();
    enemy_tower_start->setPos(1300,20);
    this->addItem(enemy_tower_start);
    QObject::connect(timer,SIGNAL(timeout()), enemy_tower_start,SLOT(move()));



    if(hero_pick==1){
        hero1_start=new hero_1();
        hero1_start->setPos(300,400);
        addItem(hero1_start);

    }
    else if(hero_pick==2){
         hero2_start=new hero_2();
         hero2_start->setPos(300,400);
         addItem(hero2_start);
    }
    else{
         hero3_start=new hero_3();
         hero3_start->setPos(300,400);
         addItem(hero3_start);
    }


    if(minion_pick1==1){
        minion1 = new minion();
        QPixmap m1;
        m1.load(":/images/minion1.png");
        m1 = m1.scaled(m1.width()*3/5 , m1.height()*3/5 ,Qt::KeepAspectRatio);
        minion1->setPixmap(m1);
        minion1->setPos(400,718);
        addItem(minion1);


    }
    else if(minion_pick1==2){
        minion2 = new minion();
        QPixmap m2;
        m2.load(":/images/minion2.png");
        m2 = m2.scaled(m2.width()*3/5 , m2.height()*3/5 ,Qt::KeepAspectRatio);
        minion2->setPixmap(m2);
        minion2->setPos(400,718);
        addItem(minion2);
    }
    else if(minion_pick1==3){
        minion3 = new minion();
        QPixmap m3;
        m3.load(":/images/minion3.png");
        m3 = m3.scaled(m3.width()*3/5 , m3.height()*3/5 ,Qt::KeepAspectRatio);
        minion3->setPixmap(m3);
        minion3->setPos(400,718);
        addItem(minion3);
    }
    else if(minion_pick1==4){
        minion4 = new minion();
        QPixmap m4;
        m4.load(":/images/minion4.png");
        m4 = m4.scaled(m4.width()*3/5 , m4.height()*3/5 ,Qt::KeepAspectRatio);
        minion4->setPixmap(m4);
        minion4->setPos(400,718);
        addItem(minion4);
    }
    else if(minion_pick1==5){
        minion5 = new minion();
        QPixmap m5;
        m5.load(":/images/minion5.png");
        m5 = m5.scaled(m5.width()*3/5 , m5.height()*3/5 ,Qt::KeepAspectRatio);
        minion5->setPixmap(m5);
        minion5->setPos(400,718);
        addItem(minion5);
    }
    else if(minion_pick1==6){
        minion6 = new minion();
        QPixmap m6;
        m6.load(":/images/minion6.png");
        m6 = m6.scaled(m6.width()*3/5 , m6.height()*3/5 ,Qt::KeepAspectRatio);
        minion6->setPixmap(m6);
        minion6->setPos(400,718);
        addItem(minion6);
    }
    else if(minion_pick1==7){
        minion7 = new minion();
        QPixmap m7;
        m7.load(":/images/minion7.png");
        m7 = m7.scaled(m7.width()*3/5 , m7.height()*3/5 ,Qt::KeepAspectRatio);
        minion7->setPixmap(m7);
        minion7->setPos(400,718);
        addItem(minion7);
    }
    else if(minion_pick1==8){
        minion8 = new minion();
        QPixmap m8;
        m8.load(":/images/minion8.png");
        m8 = m8.scaled(m8.width()*3/5 , m8.height()*3/5 ,Qt::KeepAspectRatio);
        minion8->setPixmap(m8);
        minion8->setPos(400,718);
        addItem(minion8);
    }
    else if(minion_pick1==9){
        minion9 = new minion();
        QPixmap m9;
        m9.load(":/images/minion9.png");
        m9 = m9.scaled(m9.width()*3/5 , m9.height()*3/5 ,Qt::KeepAspectRatio);
        minion9->setPixmap(m9);
        minion9->setPos(400,718);
        addItem(minion9);
    }
    else if(minion_pick1==10){
        minion10 = new minion();
        QPixmap m10;
        m10.load(":/images/minion10.png");
        m10 = m10.scaled(m10.width()*3/5 , m10.height()*3/5 ,Qt::KeepAspectRatio);
        minion10->setPixmap(m10);
        minion10->setPos(400,718);
        addItem(minion10);
    }
    else if(minion_pick1==11){
        minion11 = new minion();
        QPixmap m11;
        m11.load(":/images/minion11.png");
        m11 = m11.scaled(m11.width()*3/5 , m11.height()*3/5 ,Qt::KeepAspectRatio);
        minion11->setPixmap(m11);
        minion11->setPos(400,718);
        addItem(minion11);
    }
    else if(minion_pick1==12){
        minion12 = new minion();
        QPixmap m12;
        m12.load(":/images/minion12.png");
        m12 = m12.scaled(m12.width()*3/5 , m12.height()*3/5 ,Qt::KeepAspectRatio);
        minion12->setPixmap(m12);
        minion12->setPos(400,718);
        addItem(minion12);
    }
    else if(minion_pick1==13){
        minion13 = new minion();
        QPixmap m13;
        m13.load(":/images/minion13.png");
        m13 = m13.scaled(m13.width()*3/5 , m13.height()*3/5 ,Qt::KeepAspectRatio);
        minion13->setPixmap(m13);
        minion13->setPos(400,718);
        addItem(minion13);
    }
    else if(minion_pick1==14){
        minion14 = new minion();
        QPixmap m14;
        m14.load(":/images/minion14.png");
        m14 = m14.scaled(m14.width()*3/5 , m14.height()*3/5 ,Qt::KeepAspectRatio);
        minion14->setPixmap(m14);
        minion14->setPos(400,718);
        addItem(minion14);
    }
    else if(minion_pick1==15){
        minion15 = new minion();
        QPixmap m15;
        m15.load(":/images/minion15.png");
        m15 = m15.scaled(m15.width()*3/5 , m15.height()*3/5 ,Qt::KeepAspectRatio);
        minion15->setPixmap(m15);
        minion15->setPos(400,718);
        addItem(minion15);
    }
    else  if(minion_pick1==16){
        minion16 = new minion();
        QPixmap m16;
        m16.load(":/images/minion16.png");
        m16 = m16.scaled(m16.width()*3/5 , m16.height()*3/5 ,Qt::KeepAspectRatio);
        minion16->setPixmap(m16);
        minion16->setPos(400,718);
        addItem(minion16);
    }
    else if(minion_pick1==17){
        minion17 = new minion();
        QPixmap m17;
        m17.load(":/images/minion17.png");
        m17 = m17.scaled(m17.width()*3/5 , m17.height()*3/5 ,Qt::KeepAspectRatio);
        minion17->setPixmap(m17);
        minion17->setPos(400,718);
        addItem(minion17);
    }
    else if(minion_pick1==18){
        minion18 = new minion();
        QPixmap m18;
        m18.load(":/images/minion18.png");
        m18 = m18.scaled(m18.width()*3/5 , m18.height()*3/5 ,Qt::KeepAspectRatio);
        minion18->setPixmap(m18);
        minion18->setPos(400,718);
        addItem(minion18);
    }
    else  if(minion_pick1==19){
        minion19 = new minion();
        QPixmap m19;
        m19.load(":/images/minion19.png");
        m19 = m19.scaled(m19.width()*3/5 , m19.height()*3/5 ,Qt::KeepAspectRatio);
        minion19->setPixmap(m19);
        minion19->setPos(400,718);
        addItem(minion19);
    }
    else{
        minion20 = new minion();
        QPixmap m20;
        m20.load(":/images/minion20.png");
        m20 = m20.scaled(m20.width()*3/5 , m20.height()*3/5 ,Qt::KeepAspectRatio);
        minion20->setPixmap(m20);
        minion20->setPos(400,718);
        addItem(minion20);
    }

    if(minion_pick2==1){
        minion1 = new minion();
        QPixmap m1;
        m1.load(":/images/minion1.png");
        m1 = m1.scaled(m1.width()*3/5 , m1.height()*3/5 ,Qt::KeepAspectRatio);
        minion1->setPixmap(m1);
        minion1->setPos(600,718);
        addItem(minion1);
    }
    else if(minion_pick2==2){
        minion2 = new minion();
        QPixmap m2;
        m2.load(":/images/minion2.png");
        m2 = m2.scaled(m2.width()*3/5 , m2.height()*3/5 ,Qt::KeepAspectRatio);
        minion2->setPixmap(m2);
        minion2->setPos(600,718);
        addItem(minion2);
    }
    else if(minion_pick2==3){
        minion3 = new minion();
        QPixmap m3;
        m3.load(":/images/minion3.png");
        m3 = m3.scaled(m3.width()*3/5 , m3.height()*3/5 ,Qt::KeepAspectRatio);
        minion3->setPixmap(m3);
        minion3->setPos(600,718);
        addItem(minion3);
    }
    else if(minion_pick2==4){
        minion4 = new minion();
        QPixmap m4;
        m4.load(":/images/minion4.png");
        m4 = m4.scaled(m4.width()*3/5 , m4.height()*3/5 ,Qt::KeepAspectRatio);
        minion4->setPixmap(m4);
        minion4->setPos(600,718);
        addItem(minion4);
    }
    else if(minion_pick2==5){
        minion5 = new minion();
        QPixmap m5;
        m5.load(":/images/minion5.png");
        m5 = m5.scaled(m5.width()*3/5 , m5.height()*3/5 ,Qt::KeepAspectRatio);
        minion5->setPixmap(m5);
        minion5->setPos(600,718);
        addItem(minion5);
    }
    else if(minion_pick2==6){
        minion6 = new minion();
        QPixmap m6;
        m6.load(":/images/minion6.png");
        m6 = m6.scaled(m6.width()*3/5 , m6.height()*3/5 ,Qt::KeepAspectRatio);
        minion6->setPixmap(m6);
        minion6->setPos(600,718);
        addItem(minion6);
    }
    else if(minion_pick2==7){
        minion7 = new minion();
        QPixmap m7;
        m7.load(":/images/minion7.png");
        m7 = m7.scaled(m7.width()*3/5 , m7.height()*3/5 ,Qt::KeepAspectRatio);
        minion7->setPixmap(m7);
        minion7->setPos(600,718);
        addItem(minion7);
    }
    else if(minion_pick2==8){
        minion8 = new minion();
        QPixmap m8;
        m8.load(":/images/minion8.png");
        m8 = m8.scaled(m8.width()*3/5 , m8.height()*3/5 ,Qt::KeepAspectRatio);
        minion8->setPixmap(m8);
        minion8->setPos(600,718);
        addItem(minion8);
    }
    else if(minion_pick2==9){
        minion9 = new minion();
        QPixmap m9;
        m9.load(":/images/minion9.png");
        m9 = m9.scaled(m9.width()*3/5 , m9.height()*3/5 ,Qt::KeepAspectRatio);
        minion9->setPixmap(m9);
        minion9->setPos(600,718);
        addItem(minion9);
    }
    else if(minion_pick2==10){
        minion10 = new minion();
        QPixmap m10;
        m10.load(":/images/minion10.png");
        m10 = m10.scaled(m10.width()*3/5 , m10.height()*3/5 ,Qt::KeepAspectRatio);
        minion10->setPixmap(m10);
        minion10->setPos(600,718);
        addItem(minion10);
    }
    else if(minion_pick2==11){
        minion11 = new minion();
        QPixmap m11;
        m11.load(":/images/minion11.png");
        m11 = m11.scaled(m11.width()*3/5 , m11.height()*3/5 ,Qt::KeepAspectRatio);
        minion11->setPixmap(m11);
        minion11->setPos(600,718);
        addItem(minion11);
    }
    else if(minion_pick2==12){
        minion12 = new minion();
        QPixmap m12;
        m12.load(":/images/minion12.png");
        m12 = m12.scaled(m12.width()*3/5 , m12.height()*3/5 ,Qt::KeepAspectRatio);
        minion12->setPixmap(m12);
        minion12->setPos(600,718);
        addItem(minion12);
    }
    else if(minion_pick2==13){
        minion13 = new minion();
        QPixmap m13;
        m13.load(":/images/minion13.png");
        m13 = m13.scaled(m13.width()*3/5 , m13.height()*3/5 ,Qt::KeepAspectRatio);
        minion13->setPixmap(m13);
        minion13->setPos(600,718);
        addItem(minion13);
    }
    else if(minion_pick2==14){
        minion14 = new minion();
        QPixmap m14;
        m14.load(":/images/minion14.png");
        m14 = m14.scaled(m14.width()*3/5 , m14.height()*3/5 ,Qt::KeepAspectRatio);
        minion14->setPixmap(m14);
        minion14->setPos(600,718);
        addItem(minion14);
    }
    else if(minion_pick2==15){
        minion15 = new minion();
        QPixmap m15;
        m15.load(":/images/minion15.png");
        m15 = m15.scaled(m15.width()*3/5 , m15.height()*3/5 ,Qt::KeepAspectRatio);
        minion15->setPixmap(m15);
        minion15->setPos(600,718);
        addItem(minion15);
    }
    else  if(minion_pick2==16){
        minion16 = new minion();
        QPixmap m16;
        m16.load(":/images/minion16.png");
        m16 = m16.scaled(m16.width()*3/5 , m16.height()*3/5 ,Qt::KeepAspectRatio);
        minion16->setPixmap(m16);
        minion16->setPos(600,718);
        addItem(minion16);
    }
    else if(minion_pick2==17){
        minion17 = new minion();
        QPixmap m17;
        m17.load(":/images/minion17.png");
        m17 = m17.scaled(m17.width()*3/5 , m17.height()*3/5 ,Qt::KeepAspectRatio);
        minion17->setPixmap(m17);
        minion17->setPos(600,718);
        addItem(minion17);
    }
    else if(minion_pick2==18){
        minion18 = new minion();
        QPixmap m18;
        m18.load(":/images/minion18.png");
        m18 = m18.scaled(m18.width()*3/5 , m18.height()*3/5 ,Qt::KeepAspectRatio);
        minion18->setPixmap(m18);
        minion18->setPos(600,718);
        addItem(minion18);
    }
    else  if(minion_pick2==19){
        minion19 = new minion();
        QPixmap m19;
        m19.load(":/images/minion19.png");
        m19 = m19.scaled(m19.width()*3/5 , m19.height()*3/5 ,Qt::KeepAspectRatio);
        minion19->setPixmap(m19);
        minion19->setPos(600,718);
        addItem(minion19);
    }
    else{
        minion20 = new minion();
        QPixmap m20;
        m20.load(":/images/minion20.png");
        m20 = m20.scaled(m20.width()*3/5 , m20.height()*3/5 ,Qt::KeepAspectRatio);
        minion20->setPixmap(m20);
        minion20->setPos(600,718);
        addItem(minion20);
    }

    if(minion_pick3==1){
        minion1 = new minion();
        QPixmap m1;
        m1.load(":/images/minion1.png");
        m1 = m1.scaled(m1.width()*3/5 , m1.height()*3/5 ,Qt::KeepAspectRatio);
        minion1->setPixmap(m1);
        minion1->setPos(800,718);
        addItem(minion1);
    }
    else if(minion_pick3==2){
        minion2 = new minion();
        QPixmap m2;
        m2.load(":/images/minion2.png");
        m2 = m2.scaled(m2.width()*3/5 , m2.height()*3/5 ,Qt::KeepAspectRatio);
        minion2->setPixmap(m2);
        minion2->setPos(800,718);
        addItem(minion2);
    }
    else if(minion_pick3==3){
        minion3 = new minion();
        QPixmap m3;
        m3.load(":/images/minion3.png");
        m3 = m3.scaled(m3.width()*3/5 , m3.height()*3/5 ,Qt::KeepAspectRatio);
        minion3->setPixmap(m3);
        minion3->setPos(800,718);
        addItem(minion3);
    }
    else if(minion_pick3==4){
        minion4 = new minion();
        QPixmap m4;
        m4.load(":/images/minion4.png");
        m4 = m4.scaled(m4.width()*3/5 , m4.height()*3/5 ,Qt::KeepAspectRatio);
        minion4->setPixmap(m4);
        minion4->setPos(800,718);
        addItem(minion4);
    }
    else if(minion_pick3==5){
        minion5 = new minion();
        QPixmap m5;
        m5.load(":/images/minion5.png");
        m5 = m5.scaled(m5.width()*3/5 , m5.height()*3/5 ,Qt::KeepAspectRatio);
        minion5->setPixmap(m5);
        minion5->setPos(800,718);
        addItem(minion5);
    }
    else if(minion_pick3==6){
        minion6 = new minion();
        QPixmap m6;
        m6.load(":/images/minion6.png");
        m6 = m6.scaled(m6.width()*3/5 , m6.height()*3/5 ,Qt::KeepAspectRatio);
        minion6->setPixmap(m6);
        minion6->setPos(800,718);
        addItem(minion6);
    }
    else if(minion_pick3==7){
        minion7 = new minion();
        QPixmap m7;
        m7.load(":/images/minion7.png");
        m7 = m7.scaled(m7.width()*3/5 , m7.height()*3/5 ,Qt::KeepAspectRatio);
        minion7->setPixmap(m7);
        minion7->setPos(800,718);
        addItem(minion7);
    }
    else if(minion_pick3==8){
        minion8 = new minion();
        QPixmap m8;
        m8.load(":/images/minion8.png");
        m8 = m8.scaled(m8.width()*3/5 , m8.height()*3/5 ,Qt::KeepAspectRatio);
        minion8->setPixmap(m8);
        minion8->setPos(800,718);
        addItem(minion8);
    }
    else if(minion_pick3==9){
        minion9 = new minion();
        QPixmap m9;
        m9.load(":/images/minion9.png");
        m9 = m9.scaled(m9.width()*3/5 , m9.height()*3/5 ,Qt::KeepAspectRatio);
        minion9->setPixmap(m9);
        minion9->setPos(800,718);
        addItem(minion9);
    }
    else if(minion_pick3==10){
        minion10 = new minion();
        QPixmap m10;
        m10.load(":/images/minion10.png");
        m10 = m10.scaled(m10.width()*3/5 , m10.height()*3/5 ,Qt::KeepAspectRatio);
        minion10->setPixmap(m10);
        minion10->setPos(800,718);
        addItem(minion10);
    }
    else if(minion_pick3==11){
        minion11 = new minion();
        QPixmap m11;
        m11.load(":/images/minion11.png");
        m11 = m11.scaled(m11.width()*3/5 , m11.height()*3/5 ,Qt::KeepAspectRatio);
        minion11->setPixmap(m11);
        minion11->setPos(800,718);
        addItem(minion11);
    }
    else if(minion_pick3==12){
        minion12 = new minion();
        QPixmap m12;
        m12.load(":/images/minion12.png");
        m12 = m12.scaled(m12.width()*3/5 , m12.height()*3/5 ,Qt::KeepAspectRatio);
        minion12->setPixmap(m12);
        minion12->setPos(800,718);
        addItem(minion12);
    }
    else if(minion_pick3==13){
        minion13 = new minion();
        QPixmap m13;
        m13.load(":/images/minion13.png");
        m13 = m13.scaled(m13.width()*3/5 , m13.height()*3/5 ,Qt::KeepAspectRatio);
        minion13->setPixmap(m13);
        minion13->setPos(800,718);
        addItem(minion13);
    }
    else if(minion_pick3==14){
        minion14 = new minion();
        QPixmap m14;
        m14.load(":/images/minion14.png");
        m14 = m14.scaled(m14.width()*3/5 , m14.height()*3/5 ,Qt::KeepAspectRatio);
        minion14->setPixmap(m14);
        minion14->setPos(800,718);
        addItem(minion14);
    }
    else if(minion_pick3==15){
        minion15 = new minion();
        QPixmap m15;
        m15.load(":/images/minion15.png");
        m15 = m15.scaled(m15.width()*3/5 , m15.height()*3/5 ,Qt::KeepAspectRatio);
        minion15->setPixmap(m15);
        minion15->setPos(800,718);
        addItem(minion15);
    }
    else  if(minion_pick3==16){
        minion16 = new minion();
        QPixmap m16;
        m16.load(":/images/minion16.png");
        m16 = m16.scaled(m16.width()*3/5 , m16.height()*3/5 ,Qt::KeepAspectRatio);
        minion16->setPixmap(m16);
        minion16->setPos(800,718);
        addItem(minion16);
    }
    else if(minion_pick3==17){
        minion17 = new minion();
        QPixmap m17;
        m17.load(":/images/minion17.png");
        m17 = m17.scaled(m17.width()*3/5 , m17.height()*3/5 ,Qt::KeepAspectRatio);
        minion17->setPixmap(m17);
        minion17->setPos(800,718);
        addItem(minion17);
    }
    else if(minion_pick3==18){
        minion18 = new minion();
        QPixmap m18;
        m18.load(":/images/minion18.png");
        m18 = m18.scaled(m18.width()*3/5 , m18.height()*3/5 ,Qt::KeepAspectRatio);
        minion18->setPixmap(m18);
        minion18->setPos(800,718);
        addItem(minion18);
    }
    else  if(minion_pick3==19){
        minion19 = new minion();
        QPixmap m19;
        m19.load(":/images/minion19.png");
        m19 = m19.scaled(m19.width()*3/5 , m19.height()*3/5 ,Qt::KeepAspectRatio);
        minion19->setPixmap(m19);
        minion19->setPos(800,718);
        addItem(minion19);
    }
    else{
        minion20 = new minion();
        QPixmap m20;
        m20.load(":/images/minion20.png");
        m20 = m20.scaled(m20.width()*3/5 , m20.height()*3/5 ,Qt::KeepAspectRatio);
        minion20->setPixmap(m20);
        minion20->setPos(800,718);
        addItem(minion20);
    }


    if(minion_pick4==1){
        minion1 = new minion();
        QPixmap m1;
        m1.load(":/images/minion1.png");
        m1 = m1.scaled(m1.width()*3/5 , m1.height()*3/5 ,Qt::KeepAspectRatio);
        minion1->setPixmap(m1);
        minion1->setPos(1000,718);
        addItem(minion1);
    }
    else if(minion_pick4==2){
        minion2 = new minion();
        QPixmap m2;
        m2.load(":/images/minion2.png");
        m2 = m2.scaled(m2.width()*3/5 , m2.height()*3/5 ,Qt::KeepAspectRatio);
        minion2->setPixmap(m2);
        minion2->setPos(1000,718);
        addItem(minion2);
    }
    else if(minion_pick4==3){
        minion3 = new minion();
        QPixmap m3;
        m3.load(":/images/minion3.png");
        m3 = m3.scaled(m3.width()*3/5 , m3.height()*3/5 ,Qt::KeepAspectRatio);
        minion3->setPixmap(m3);
        minion3->setPos(1000,718);
        addItem(minion3);
    }
    else if(minion_pick4==4){
        minion4 = new minion();
        QPixmap m4;
        m4.load(":/images/minion4.png");
        m4 = m4.scaled(m4.width()*3/5 , m4.height()*3/5 ,Qt::KeepAspectRatio);
        minion4->setPixmap(m4);
        minion4->setPos(1000,718);
        addItem(minion4);
    }
    else if(minion_pick4==5){
        minion5 = new minion();
        QPixmap m5;
        m5.load(":/images/minion5.png");
        m5 = m5.scaled(m5.width()*3/5 , m5.height()*3/5 ,Qt::KeepAspectRatio);
        minion5->setPixmap(m5);
        minion5->setPos(1000,718);
        addItem(minion5);
    }
    else if(minion_pick4==6){
        minion6 = new minion();
        QPixmap m6;
        m6.load(":/images/minion6.png");
        m6 = m6.scaled(m6.width()*3/5 , m6.height()*3/5 ,Qt::KeepAspectRatio);
        minion6->setPixmap(m6);
        minion6->setPos(1000,718);
        addItem(minion6);
    }
    else if(minion_pick4==7){
        minion7 = new minion();
        QPixmap m7;
        m7.load(":/images/minion7.png");
        m7 = m7.scaled(m7.width()*3/5 , m7.height()*3/5 ,Qt::KeepAspectRatio);
        minion7->setPixmap(m7);
        minion7->setPos(1000,718);
        addItem(minion7);
    }
    else if(minion_pick4==8){
        minion8 = new minion();
        QPixmap m8;
        m8.load(":/images/minion8.png");
        m8 = m8.scaled(m8.width()*3/5 , m8.height()*3/5 ,Qt::KeepAspectRatio);
        minion8->setPixmap(m8);
        minion8->setPos(1000,718);
        addItem(minion8);
    }
    else if(minion_pick4==9){
        minion9 = new minion();
        QPixmap m9;
        m9.load(":/images/minion9.png");
        m9 = m9.scaled(m9.width()*3/5 , m9.height()*3/5 ,Qt::KeepAspectRatio);
        minion9->setPixmap(m9);
        minion9->setPos(1000,718);
        addItem(minion9);
    }
    else if(minion_pick4==10){
        minion10 = new minion();
        QPixmap m10;
        m10.load(":/images/minion10.png");
        m10 = m10.scaled(m10.width()*3/5 , m10.height()*3/5 ,Qt::KeepAspectRatio);
        minion10->setPixmap(m10);
        minion10->setPos(1000,718);
        addItem(minion10);
    }
    else if(minion_pick4==11){
        minion11 = new minion();
        QPixmap m11;
        m11.load(":/images/minion11.png");
        m11 = m11.scaled(m11.width()*3/5 , m11.height()*3/5 ,Qt::KeepAspectRatio);
        minion11->setPixmap(m11);
        minion11->setPos(1000,718);
        addItem(minion11);
    }
    else if(minion_pick4==12){
        minion12 = new minion();
        QPixmap m12;
        m12.load(":/images/minion12.png");
        m12 = m12.scaled(m12.width()*3/5 , m12.height()*3/5 ,Qt::KeepAspectRatio);
        minion12->setPixmap(m12);
        minion12->setPos(1000,718);
        addItem(minion12);
    }
    else if(minion_pick4==13){
        minion13 = new minion();
        QPixmap m13;
        m13.load(":/images/minion13.png");
        m13 = m13.scaled(m13.width()*3/5 , m13.height()*3/5 ,Qt::KeepAspectRatio);
        minion13->setPixmap(m13);
        minion13->setPos(1000,718);
        addItem(minion13);
    }
    else if(minion_pick4==14){
        minion14 = new minion();
        QPixmap m14;
        m14.load(":/images/minion14.png");
        m14 = m14.scaled(m14.width()*3/5 , m14.height()*3/5 ,Qt::KeepAspectRatio);
        minion14->setPixmap(m14);
        minion14->setPos(1000,718);
        addItem(minion14);
    }
    else if(minion_pick4==15){
        minion15 = new minion();
        QPixmap m15;
        m15.load(":/images/minion15.png");
        m15 = m15.scaled(m15.width()*3/5 , m15.height()*3/5 ,Qt::KeepAspectRatio);
        minion15->setPixmap(m15);
        minion15->setPos(1000,718);
        addItem(minion15);
    }
    else  if(minion_pick4==16){
        minion16 = new minion();
        QPixmap m16;
        m16.load(":/images/minion16.png");
        m16 = m16.scaled(m16.width()*3/5 , m16.height()*3/5 ,Qt::KeepAspectRatio);
        minion16->setPixmap(m16);
        minion16->setPos(1000,718);
        addItem(minion16);
    }
    else if(minion_pick4==17){
        minion17 = new minion();
        QPixmap m17;
        m17.load(":/images/minion17.png");
        m17 = m17.scaled(m17.width()*3/5 , m17.height()*3/5 ,Qt::KeepAspectRatio);
        minion17->setPixmap(m17);
        minion17->setPos(1000,718);
        addItem(minion17);
    }
    else if(minion_pick4==18){
        minion18 = new minion();
        QPixmap m18;
        m18.load(":/images/minion18.png");
        m18 = m18.scaled(m18.width()*3/5 , m18.height()*3/5 ,Qt::KeepAspectRatio);
        minion18->setPixmap(m18);
        minion18->setPos(1000,718);
        addItem(minion18);
    }
    else  if(minion_pick4==19){
        minion19 = new minion();
        QPixmap m19;
        m19.load(":/images/minion19.png");
        m19 = m19.scaled(m19.width()*3/5 , m19.height()*3/5 ,Qt::KeepAspectRatio);
        minion19->setPixmap(m19);
        minion19->setPos(1000,718);
        addItem(minion19);
    }
    else{
        minion20 = new minion();
        QPixmap m20;
        m20.load(":/images/minion20.png");
        m20 = m20.scaled(m20.width()*3/5 , m20.height()*3/5 ,Qt::KeepAspectRatio);
        minion20->setPixmap(m20);
        minion20->setPos(1000,718);
        addItem(minion20);
    }
    btn_back = new btn();
    QPixmap bk;
    bk.load(":/images/btn_back.png");
    btn_small_w = bk.width()*1/3;
    btn_small_h = bk.height()*1/3;
    bk = bk.scaled(btn_small_w , btn_small_h ,Qt::KeepAspectRatio);
    btn_back->setPixmap(bk);
    btn_back->setPos(3,3);
    addItem(btn_back);

}

void Scene::keyPressEvent(QKeyEvent *event)
{

       if(hero_pick==1){
        if (event->key() == Qt::Key_A){
                hero1_start->move(-15,0);
            }
        else if (event->key() == Qt::Key_D){
               hero1_start-> move(15,0);
            }
        else if (event->key() == Qt::Key_W){
                hero1_start->move(0,-15);
            }
        else if (event->key() == Qt::Key_S){
                hero1_start->move(0,15);
            }
        else if (event->key() == Qt::Key_Space){
                herofire=new hero_fire();
                herofire->setPos(hero1_start->pos().x()+100,hero1_start->pos().y()+50);
                addItem(herofire);


            }
      }


       else if(hero_pick==2){
        if (event->key() == Qt::Key_A){
                hero2_start->move(-15,0);
            }
        else if (event->key() == Qt::Key_D){
               hero2_start-> move(15,0);
            }
        else if (event->key() == Qt::Key_W){
                hero2_start->move(0,-15);
            }
        else if (event->key() == Qt::Key_S){
                hero2_start->move(0,15);
            }
        else if (event->key() == Qt::Key_Space){
                herofire=new hero_fire();
                herofire->setPos(hero2_start->pos().x()+100,hero2_start->pos().y()+50);
                addItem(herofire);


            }
      }
       if(hero_pick==3){
        if (event->key() == Qt::Key_A){
                hero3_start->move(-15,0);
            }
        else if (event->key() == Qt::Key_D){
               hero3_start-> move(15,0);
            }
        else if (event->key() == Qt::Key_W){
                hero3_start->move(0,-15);
            }
        else if (event->key() == Qt::Key_S){
                hero3_start->move(0,15);
            }
        else if (event->key() == Qt::Key_Space){
                herofire=new hero_fire();
                herofire->setPos(hero3_start->pos().x()+100,hero3_start->pos().y()+50);
                addItem(herofire);


            }
       }
}

void Scene::gameover()
{
    this->clear();
    QImage bg;
    bg.load(":/images/bg_init.jpg");
    this->setBackgroundBrush(bg);

}



void Scene::bgRecover()
{

    this->clear();

    addItem(btn_start);
    addItem(btn_choose_hero);
    addItem(btn_choose_minion);
    QImage bg;
    bg.load(":/images/bg_init.jpg");

    this->setBackgroundBrush(bg);
}

