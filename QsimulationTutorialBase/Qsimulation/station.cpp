
#include "station.h"
#include <QPainter>
#include <QtCore/qmath.h>

#define PI 3.14159265

int   stationRotation = 90;
qreal sine[360], cosine[360];

/*************************************************************************************/
/******************* Represents a radio station in the simulation ********************/
/*************************************************************************************/

/************************************ constuctor *************************************/
Station::Station()
{
}

Station::Station( qreal x, qreal y ) : QGraphicsItem()
{
  // set Station pixmap and position
  setPos( x, y );
  setFlags( QGraphicsItem::ItemIgnoresTransformations );
            //QGraphicsItem::ItemIsMovable |
           // QGraphicsItem::ItemIsSelectable |
  int i;
  for(i=0; i <=359; i++)
  {
      sine[i]   = qSin(i * PI / 180);
      cosine[i] = qCos(i * PI / 180);
  }
}

/************************************** paintShip ****************************************/

/************************************** paint ****************************************/

void  Station::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setRenderHint( QPainter::Antialiasing );
  //---------------------------------------------------------------------------------------------------
  //Create Plane
    painter->setPen( QPen( Qt::blue, 2 ) );
    painter->drawLine( +0,  -9.375,  +3.125,  -15.625);
    painter->drawLine( +3.125,  -15.625,  +0,  -21.875);
    painter->drawLine( +0,  -9.375,  -3.125,  -15.625);
    painter->drawLine( -3.125,  -15.625,  +0,  -21.875);

  //Right Half
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
  //Left half
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

}

