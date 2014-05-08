#ifndef ASTEROID_H
#define ASTEROID_H

#include <QGraphicsItem>

class Asteroid: public QGraphicsItem
{
public:
  Asteroid( qreal, qreal ); // constructor
  Asteroid( qreal, qreal, qreal, qreal, qreal);
  Asteroid();
  void     paint( QPainter*,
                  const QStyleOptionGraphicsItem*,
                  QWidget* );                       // implement virtual paint function for Ship
  QRectF   boundingRect() const
    { return QRectF(-9*size,  -9*size,  18*size,   18*size); }           // implement virtual boundingRect
  qreal getXPos(), getYPos(), getXMove(),getYMove(), getSize();
  void setXPos(qreal), setYPos(qreal),  setSize(qreal), advance(int), setXMove(double), setYMove(double) ;
private:
  qreal xPos, yPos, xMove, yMove, size;
};

#endif // ASTEROID_H
