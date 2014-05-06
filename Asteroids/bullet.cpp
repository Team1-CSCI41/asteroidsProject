#include "bullet.h"

#include "scene.h"

#include "mainwindow.h"

#include <QPainter>










qreal Bullet::getXMove()
{
    return xMove;
}

qreal Bullet::getYMove()
{
    return yMove;
}

qreal Bullet::getLifespan()
{
    return lifespan;
}


qreal Bullet::getXPos()
{
    return xPos;
}

qreal Bullet::getYPos()
{
    return this->scenePos().y();
}

Bullet::Bullet( qreal x, qreal y, qreal xm, qreal ym ) : QGraphicsItem()
{
  // set Bullet pixmap and position
  setPos( x, y );
  setFlags( QGraphicsItem::ItemIgnoresTransformations );
            //QGraphicsItem::ItemIsMovable |
           // QGraphicsItem::ItemIsSelectable |
  xMove=xm;
  yMove=ym;

  xPos = x;
  yPos = y;

  lifespan = 50;

}


void Bullet::setXPos(qreal x)
{
    xPos = x;
}

void Bullet::setYPos(qreal y)
{
    yPos = y;
}

Bullet::Bullet()
{
}

void  Bullet::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    // paint station symbol, must be smaller than bounding rectangle
    painter->setRenderHint( QPainter::Antialiasing );
    painter->setPen( QPen( Qt::white, 2 ) );
    painter->drawLine( 0,  0,  0,  -10 );
}


void Bullet::advance(int)
{
    qreal xDest = this->scenePos().x() + xMove;
    qreal yDest = this->scenePos().y() + yMove;

    //If bullet moves off screen, wrap to other side
    if(xDest < 0)             xDest +=  WINDOW_WIDTH   -  1;
    if(xDest > WINDOW_WIDTH ) xDest -=  WINDOW_WIDTH       ;
    if(yDest < 15)            yDest += (WINDOW_HEIGHT - 15);
    if(yDest > WINDOW_HEIGHT) yDest -= (WINDOW_HEIGHT - 15);

    this->setPos(xDest, yDest);

    xPos = xDest;
    yPos = yDest;

    lifespan--;

}

