
#include "enemy.h"
#include <QTimer>
#include <QGraphicsScene>

#include <stdlib.h>

extern Game * game;

Enemy::Enemy()
{
    // set random position
    int random_number = rand()%700;
    setPos(random_number, 0);

    setRect(0, 0, 100, 100);

    // connect
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

            timer->start(50);
}

void Enemy::move()
{
    // move enemy down
    setPos(x(), y()+5);
    if (pos().y() > 600)
    {
        // decrease the health
        game->health->decrease();

        scene()->removeItem(this);
        delete this;
    }
}
