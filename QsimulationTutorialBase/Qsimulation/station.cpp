

#include "station.h"

#include <QPainter>

/*************************************************************************************/
/******************* Represents a radio station in the simulation ********************/
/*************************************************************************************/

/************************************ constuctor *************************************/

Station::Station( qreal x, qreal y ) : QGraphicsItem()
{
  // set Station pixmap and position
  setPos( x, y );
  setFlags( QGraphicsItem::ItemIsMovable |
            QGraphicsItem::ItemIsSelectable |
            QGraphicsItem::ItemIgnoresTransformations );
}

/************************************** paint ****************************************/

void  Station::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
  // paint station symbol, must be smaller than bounding rectangle
  painter->setRenderHint( QPainter::Antialiasing );
  painter->setPen( QPen( Qt::green, 2 ) );

  painter->drawLine( +25,  -25,  0,  -25 );
  painter->drawLine( +25,  -25,  0,  0 );
  painter->drawLine( 0,  0,  0,  -25 );

  painter->drawLine( +25,  -25,  +50,  -25 );
  painter->drawLine( +50,  -25,  +50,  -75 );
  painter->drawLine( +50,  -75,  +100,  -75 );
  painter->drawLine(  +100,  -75,  +100,  -50 );
  painter->drawLine(  +100,  -50,  +112.5,  -37.5 );
  painter->drawLine(  +112.5,  -37.5,  +125,  -50 );
  painter->drawLine( +125,  -50,  +125,  -75 );
  painter->drawLine( +125,  -75,  +150,  -75 );
  painter->drawLine( +150,  -75,  +200,  -25 );
  painter->drawLine( +200,  -25,  +200,  -225 );
  painter->drawLine( +200,  -225,  +150,  -175 );
  painter->drawLine( +150,  -175,  +125,  -175 );
  painter->drawLine( +125,  -175,  +125,  -212.5 );
  painter->drawLine( +125,  -212.5,  +112.5,  -225 );
  painter->drawLine( +112.5,  -225,  +100,  -212.5 );
  painter->drawLine( +100,  -212.5,  +100,  -175 );
  painter->drawLine( +100,  -175,  +50,  -175 );
  painter->drawLine( +50,  -175,  +0,  -375 );
  painter->setPen( QPen( Qt::blue, 2 ) );
  painter->drawLine( +0,  -375,  +0,  -25 );

  painter->setPen( QPen( Qt::green, 2 ) );

  painter->drawLine( -25,  -25,  0,  -25 );
  painter->drawLine( -25,  -25,  0,  0 );
  painter->drawLine( 0,  0,  0,  -25 );

  painter->drawLine( -25,  -25,  -50,  -25 );
  painter->drawLine( -50,  -25,  -50,  -75 );
  painter->drawLine( -50,  -75,  -100,  -75 );
  painter->drawLine(  -100,  -75,  -100,  -50 );
  painter->drawLine(  -100,  -50,  -112.5,  -37.5 );
  painter->drawLine(  -112.5,  -37.5,  -125,  -50 );
  painter->drawLine( -125,  -50,  -125,  -75 );
  painter->drawLine( -125,  -75,  -150,  -75 );
  painter->drawLine( -150,  -75,  -200,  -25 );
  painter->drawLine( -200,  -25,  -200,  -225 );
  painter->drawLine( -200,  -225,  -150,  -175 );
  painter->drawLine( -150,  -175,  -125,  -175 );
  painter->drawLine( -125,  -175,  -125,  -212.5 );
  painter->drawLine( -125,  -212.5,  -112.5,  -225 );
  painter->drawLine( -112.5,  -225,  -100,  -212.5 );
  painter->drawLine( -100,  -212.5,  -100,  -175 );
  painter->drawLine( -100,  -175,  -50,  -175 );
  painter->drawLine( -50,  -175,  -0,  -375 );
  painter->setPen( QPen( Qt::blue, 2 ) );
  painter->drawLine( +0,  -375,  +0,  -25 );




}

void Station ::paintAsteroid(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
  // paint station symbol, must be smaller than bounding rectangle
  painter->setRenderHint( QPainter::Antialiasing );
  painter->setPen( QPen( Qt::black, 2 ) );
  painter->drawLine( -5, -11,  +5, -11 );
  painter->drawLine( -5, -11,  0,  -6 );
  painter->drawLine( +5, -11,  0,  -6 );
}

void Station ::paintBullet(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
  // paint station symbol, must be smaller than bounding rectangle
  painter->setRenderHint( QPainter::Antialiasing );
  painter->setPen( QPen( Qt::black, 2 ) );
  painter->drawLine( -5, -11,  +5, -11 );
  painter->drawLine( -5, -11,  0,  -6 );
  painter->drawLine( +5, -11,  0,  -6 );
}
