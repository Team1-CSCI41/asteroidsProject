#ifndef ASTEROID_H
#define ASTEROID_H

#include <QGraphicsItem>

class Asteroid: public QGraphicsItem
{
public:
  Asteroid( qreal, qreal );                          // constructor
  Asteroid();
  void     paint( QPainter*,
                  const QStyleOptionGraphicsItem*,
                  QWidget* );                       // implement virtual paint function for Ship
  QRectF   boundingRect() const
    { return QRectF(-6.5, -13, 13, 18); }           // implement virtual boundingRect
};

#endif // ASTEROID_H
