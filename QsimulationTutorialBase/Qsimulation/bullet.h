#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsItem>

class Bullet: public QGraphicsItem
{
public:
  Bullet( qreal, qreal );                          // constructor
  Bullet();
  void     paint( QPainter*,
                  const QStyleOptionGraphicsItem*,
                  QWidget* );                       // implement virtual paint function for Ship
  QRectF   boundingRect() const
    { return QRectF(-6.5, -13, 13, 18); }           // implement virtual boundingRect
};

#endif // BULLET_H
