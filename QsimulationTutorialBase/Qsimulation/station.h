
#ifndef STATION_H
#define STATION_H

#include <QGraphicsItem>

/*************************************************************************************/
/******************* Represents a radio station in the simulation ********************/
/*************************************************************************************/

class Station : public QGraphicsItem
{
public:
  Station( qreal, qreal );                          // constructor
  Station();
  void     paint( QPainter*,
                  const QStyleOptionGraphicsItem*,
                  QWidget* );                       // implement virtual paint function for Ship
  QRectF   boundingRect() const
    { return QRectF(-6.5, -13, 13, 18); }           // implement virtual boundingRect
    //{ return QRectF(-6.5, -16.5, 13, 18); }           // implement virtual boundingRect
  int stationRotation;
private:
  qreal xPos;
  qreal yPos;
  qreal xMove;
  qreal yMove;

};

#endif  // STATION_H
