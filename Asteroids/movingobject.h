#ifndef MOVINGOBJECT_H
#define MOVINGOBJECT_H

//#include <QObject>

class MovingObject //: public QObject
{
    Q_OBJECT
public:
    //explicit MovingObject(QObject *parent = 0);
    MovingObject (float, float, float, float);
    
//signals:

public slots:
    void setXPosition(float);
    float getXPosition();
    void setXMove(float);
    float getXMove();
    void setYPosition(float);
    float getYPosition();
    void setYMove(float);
    float getYMove();

private:
   float xPos;
   float xMove;
   float yPos;
   float yMove;
    
};

#endif // MOVINGOBJECT_H
