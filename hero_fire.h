#ifndef HERO_FIRE_H
#define HERO_FIRE_H
#include <QGraphicsPixmapItem>
#include<QTimer>
#include<QObject>
#include<QGraphicsScene>
class hero_fire : public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    hero_fire(QGraphicsItem* parent=0);
    float x_speed;
    float y_speed;
    QTimer *timer;

public slots:
    void move();


};
#endif // HERO_FIRE_H
