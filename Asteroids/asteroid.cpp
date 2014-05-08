#include "asteroid.h"
#include <iostream>
#include "mainwindow.h"
#include <QPainter>

using namespace std;



Asteroid::Asteroid( qreal x, qreal y ) : QGraphicsItem()
{
  // set Asteroid pixmap and position
  setPos( x, y );
  setFlags( QGraphicsItem::ItemIgnoresTransformations );
            //QGraphicsItem::ItemIsMovable |
           // QGraphicsItem::ItemIsSelectable |
}

Asteroid::Asteroid( qreal x, qreal y, qreal xm, qreal ym, qreal s ) : QGraphicsItem()
{
  // set Asteroid pixmap and position
  setPos( x, y );
  setFlags( QGraphicsItem::ItemIgnoresTransformations );


  xPos = x; yPos = y; xMove = xm; yMove = ym; size = s;
}

Asteroid::Asteroid()
{
}






void Asteroid::setXPos(qreal xp){
    xPos = xp;
}

void Asteroid::setYPos(qreal yp){
    yPos = yp;
}

void Asteroid:: setSize(qreal siz){
    size = siz;
}

void Asteroid::setXMove(qreal xM){
    xMove=xM;
}

void Asteroid::setYMove(qreal yM){
    yMove=yM;
}

qreal Asteroid::getXMove(){
    return xMove;
}

qreal Asteroid::getYMove(){
    return yMove;
}

qreal Asteroid::getXPos(){
    return this->scenePos().x();
}

qreal Asteroid::getYPos(){
    return this->scenePos().y();
}

qreal Asteroid::getSize(){
    return size;

}




void  Asteroid::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    // paint Asteroid symbol, must be smaller than bounding rectangle
    painter->setRenderHint( QPainter::Antialiasing );
    painter->setPen( QPen( Qt::white, 2 ) );


    painter->drawRect( -8*size,  -8*size,  16*size,   16*size );
    painter->setPen( QPen( Qt::cyan, 2 ) );
    painter->drawRect(-9*size,  -9*size,  18*size,   18*size);

}


void Asteroid::advance(int){
    qreal xDest = this->scenePos().x() + xMove;
    qreal yDest = this->scenePos().y() + yMove;



    if(xDest < 0)             xDest += WINDOW_WIDTH - 1;
    if(xDest > WINDOW_WIDTH)  xDest -= WINDOW_WIDTH;
    if(yDest < 15)             yDest += (WINDOW_HEIGHT - 50);
    if(yDest > WINDOW_HEIGHT-20) yDest -= (WINDOW_HEIGHT - 50);

    this->setPos( xDest, yDest );

    xPos = xDest;
    yPos = yDest;
}
