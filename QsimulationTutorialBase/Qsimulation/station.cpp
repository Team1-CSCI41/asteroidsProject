

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
  // paint station symbol, must be smaller than bounding rectangle ////////////////////////////////////////////// MUST BE SMALLER THAN BOUNDING RECTANGLE!!!!!!?????
  painter->setRenderHint( QPainter::Antialiasing );
  painter->setPen( QPen( Qt::green, 2 ) );

  painter->drawLine( +3.125,  -3.125,  0,  -3.125 );
  painter->drawLine( +3.125,  -3.125,  0,  0 );
  painter->drawLine( 0,  0,  0,  -3.125 );

  painter->drawLine( +3.125,  -3.125,  +6.25,  -3.125 );
  painter->drawLine( +6.25,  -3.125,  +6.25,  -9.375 );
  painter->drawLine( +6.25,  -9.375,  +12.5,  -9.375 );
  painter->drawLine(  +12.5,  -9.375,  +12.5,  -6.25 );
  painter->drawLine(  +12.5,  -6.25,  +14.0625,  -4.6875 );
  painter->drawLine(  +14.0625,  -4.6875,  +15.625,  -6.25);
  painter->drawLine( +15.625,  -6.25,  +15.625,  -9.375 );
  painter->drawLine( +15.625,  -9.375,  +18.75,  -9.375 );
  painter->drawLine( +18.75,  -9.375,  +25,  -3.125);
  painter->drawLine( +25,  -3.125,  +25,  -28.125);
  painter->drawLine( +25,  -28.125,  +18.75,  -21.875);
  painter->drawLine( +18.75,  -21.875,  +15.625,  -21.875);
  painter->drawLine( +15.625,  -21.875,  +15.625,  -26.5625);
  painter->drawLine( +15.625,  -26.5625,  +14.0625,  -28.125 );
  painter->drawLine( +14.0625,  -28.125,  +12.5,  -26.5625);
  painter->drawLine( +12.5,  -26.5625,  +12.5,  -21.875 );
  painter->drawLine( +12.5,  -21.875,  +6.25,  -21.875);
  painter->drawLine( +6.25,  -21.875,  +0,  -46.875 );
  painter->setPen( QPen( Qt::blue, 2 ) );
  painter->drawLine( +0,  -46.875,  +0,  -3.125);

  painter->setPen( QPen( Qt::green, 2 ) );

  painter->drawLine( -3.125,  -3.125,  0,  -3.125 );
  painter->drawLine( -3.125,  -3.125,  0,  0 );
  painter->drawLine( -0,  0,  0,  -3.125 );

  painter->drawLine( -3.125,  -3.125,  -6.25,  -3.125 );
  painter->drawLine( -6.25,  -3.125,  -6.25,  -9.375 );
  painter->drawLine( -6.25,  -9.375,  -12.5,  -9.375 );
  painter->drawLine(  -12.5,  -9.375,  -12.5,  -6.25 );
  painter->drawLine(  -12.5,  -6.25,  -14.0625,  -4.6875 );
  painter->drawLine(  -14.0625,  -4.6875,  -15.625,  -6.25);
  painter->drawLine( -15.625,  -6.25,  -15.625,  -9.375 );
  painter->drawLine( -15.625,  -9.375,  -18.75,  -9.375 );
  painter->drawLine( -18.75,  -9.375,  -25,  -3.125);
  painter->drawLine( -25,  -3.125,  -25,  -28.125);
  painter->drawLine( -25,  -28.125,  -18.75,  -21.875);
  painter->drawLine( -18.75,  -21.875,  -15.625,  -21.875);
  painter->drawLine( -15.625,  -21.875,  -15.625,  -26.5625);
  painter->drawLine( -15.625,  -26.5625, -14.0625,  -28.125 );
  painter->drawLine( -14.0625,  -28.125,  -12.5,  -26.5625);
  painter->drawLine( -12.5,  -26.5625,  -12.5,  -21.875 );
  painter->drawLine( -12.5,  -21.875,  -6.25,  -21.875);
  painter->drawLine( -6.25,  -21.875,  -0,  -46.875 );
  painter->setPen( QPen( Qt::blue, 2 ) );
  painter->drawLine( +0,  -46.875,  +0,  -3.125);

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
