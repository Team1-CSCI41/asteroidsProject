#ifndef STAR_H
#define STAR_H
#include <QGraphicsItem>

class Star: public QGraphicsItem
{
public:
    Star(qreal, qreal);
    void     paint( QPainter*,
                    const QStyleOptionGraphicsItem*,
                    QWidget* );                       // implement virtual paint function for Ship
    QRectF   boundingRect() const
      { return QRectF(-10,-10,20,20); }


    qreal           starX;
    qreal           starY;
};

#endif // STAR_H
