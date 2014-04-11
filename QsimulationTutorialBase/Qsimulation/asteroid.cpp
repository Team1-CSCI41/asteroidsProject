#include "asteroid.h"

#include <QPainter>

Asteroid::Asteroid()
{
}

Asteroid::Asteroid( qreal x, qreal y ) : QGraphicsItem()
{
  // set Asteroid pixmap and position
  setPos( x, y );
  setFlags( QGraphicsItem::ItemIgnoresTransformations );
            //QGraphicsItem::ItemIsMovable |
           // QGraphicsItem::ItemIsSelectable |
}

void  Asteroid::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
  // paint Asteroid symbol, must be smaller than bounding rectangle
  painter->setRenderHint( QPainter::Antialiasing );
  painter->setPen( QPen( Qt::black, 2 ) );

  //painter->drawEllipse(0,0,20,20);
  painter->drawRect( -8,  -8,  12,   12 );

}
