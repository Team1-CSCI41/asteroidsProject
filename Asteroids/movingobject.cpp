#include "movingobject.h"

/*MovingObject::MovingObject(QObject *parent) :
    QObject(parent)
{

}*/
MovingObject::MovingObject( float a,float b,float c,float d)
{
    xPos = a;
    yPos = b;
    xMove = c;
    yMove = d;
}

void MovingObject::setXPosition(float a)
{
    xPos = a;
}

float MovingObject::getXPosition()
{
    return xPos;
}

void MovingObject::setXMove(float b)
{
    xMove = b;
}

float MovingObject::getXMove()
{
    return xMove;
}

void MovingObject::setYPosition(float c)
{
    yPos = c;
}

float MovingObject::getYPosition()
{
    return yPos;
}

void MovingObject::setYMove(float d)
{
    yMove = d;
}

float MovingObject::getYMove()
{
    return yMove;
}
