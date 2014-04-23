#include "bullet.h"

#include <QPainter>

Bullet::Bullet()
{
}

Bullet::Bullet( qreal x, qreal y ) : QGraphicsItem()
{
  // set Bullet pixmap and position
  setPos( x, y );
  setFlags( QGraphicsItem::ItemIgnoresTransformations );
            //QGraphicsItem::ItemIsMovable |
           // QGraphicsItem::ItemIsSelectable |
}

void  Bullet::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    // paint station symbol, must be smaller than bounding rectangle
    painter->setRenderHint( QPainter::Antialiasing );
    painter->setPen( QPen( Qt::white, 2 ) );
    painter->drawLine( 0,  0,  0,  -10 );
}
