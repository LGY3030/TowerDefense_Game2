#ifndef MY_TOWER_H
#define MY_TOWER_H
#include <QGraphicsPixmapItem>
#include<QTimer>
#include<QObject>
class my_tower :  public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    my_tower();

public slots:
    void fire();

};
#endif // MY_TOWER_H
