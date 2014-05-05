#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsItem>

class Bullet: public QGraphicsItem
{
public:
  Bullet( qreal, qreal, qreal, qreal );                          // constructor
  Bullet();
  void     paint( QPainter*,
                  const QStyleOptionGraphicsItem*,
                  QWidget* );                       // implement virtual paint function for Ship
  QRectF   boundingRect() const
    { return QRectF(-1, -12, 3, 13); }           // implement virtual boundingRect
  qreal getXpos(), getYpos(), getXmove(), getYmove(), getLifespan();
  void setXPos(qreal), setYPos(qreal)/*, advance(int)*/;
private:
  qreal xPos, yPos, xMove, yMove, lifespan;
};

#endif // BULLET_H

