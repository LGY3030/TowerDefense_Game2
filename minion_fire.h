#ifndef MINION_FIRE_H
#define MINION_FIRE_H
#include <QGraphicsPixmapItem>
#include<QTimer>
#include<QObject>
#include<QGraphicsScene>
#include<QLabel>
class minion_fire : public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    minion_fire(QGraphicsItem* parent=0);
    void gameover();
    float x_speed;
    float y_speed;
    QTimer *timer;
    QLabel *label;

public slots:
    void move();



};
#endif // MINION_FIRE_H
