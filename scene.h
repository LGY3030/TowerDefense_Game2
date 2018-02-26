#ifndef SCENE_H
#define SCENE_H
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include<QWidget>
#include<QKeyEvent>
#include<QMouseEvent>
#include<QTimer>
#include"btn.h"
#include"my_tower.h"
#include"enemy_tower.h"
#include"hero.h"
#include"minion.h"
#include"rectangle.h"
#include"minion_1.h"
#include"minion_2.h"
#include"minion_3.h"
#include"minion_4.h"
#include"minion_5.h"
#include"minion_6.h"
#include"minion_7.h"
#include"minion_8.h"
#include"minion_9.h"
#include"minion_10.h"
#include"minion_11.h"
#include"minion_12.h"
#include"minion_13.h"
#include"minion_14.h"
#include"minion_15.h"
#include"minion_16.h"
#include"minion_17.h"
#include"minion_18.h"
#include"minion_19.h"
#include"minion_20.h"
#include"hero_1.h"
#include"hero_2.h"
#include"hero_3.h"
#include"hero_fire.h"
#include"minion_fire.h"
#include"enemy_tower_fire.h"




class Scene : public QGraphicsScene,public QWidget,public QGraphicsPixmapItem


{



public:

    Scene();
    void Init();
    void setCursor(QString filename);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void bgChange_minion();
    void bgChange_hero();
    void bgRecover();
    void bgChange_start();
    void keyPressEvent(QKeyEvent *event);
    void gameover();



    hero_fire * herofire;
    minion_fire * minionfire;
    enemy_tower_fire *enemytowerfire;
    QGraphicsPixmapItem * cursor;
    QGraphicsPixmapItem * pic;
    QTimer * timer;
    btn *btn_start;
    btn *btn_choose_minion;
    btn *btn_choose_hero;
    btn *btn_pause;
    btn *btn_conti;
    btn *btn_back;
    hero *hero1;
    hero *hero2;
    hero *hero3;
    minion *minion1;
    minion *minion2;
    minion *minion3;
    minion *minion4;
    minion *minion5;
    minion *minion6;
    minion *minion7;
    minion *minion8;
    minion *minion9;
    minion *minion10;
    minion *minion11;
    minion *minion12;
    minion *minion13;
    minion *minion14;
    minion *minion15;
    minion *minion16;
    minion *minion17;
    minion *minion18;
    minion *minion19;
    minion *minion20;
    hero_1 *hero1_start;
    hero_2 *hero2_start;
    hero_3 *hero3_start;
    minion_1 *minion1_start;
    minion_2 *minion2_start;
    minion_3 *minion3_start;
    minion_4 *minion4_start;
    minion_5 *minion5_start;
    minion_6 *minion6_start;
    minion_7 *minion7_start;
    minion_8 *minion8_start;
    minion_9 *minion9_start;
    minion_10 *minion10_start;
    minion_11 *minion11_start;
    minion_12 *minion12_start;
    minion_13 *minion13_start;
    minion_14 *minion14_start;
    minion_15 *minion15_start;
    minion_16 *minion16_start;
    minion_17 *minion17_start;
    minion_18 *minion18_start;
    minion_19 *minion19_start;
    minion_20 *minion20_start;
    QGraphicsRectItem * hero_pick_rect;
    QGraphicsRectItem * minion_pick1_rect;
    QGraphicsRectItem * minion_pick2_rect;
    QGraphicsRectItem * minion_pick3_rect;
    QGraphicsRectItem * minion_pick4_rect;


    my_tower *my_tower_start;
    enemy_tower *enemy_tower_start;
    int get;
    int btn_w;
    int btn_h;
    int btn_small_w;
    int btn_small_h;
    int screenMode;
    int hero_pick;
    int minion_pick1;
    int minion_pick2;
    int minion_pick3;
    int minion_pick4;
    int choose;
    int x,y;



};

#endif // SCENE_H
