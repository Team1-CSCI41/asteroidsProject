/***************************************************************************
 *   Copyright (C) 2009 by Richard Crook                                   *
 *   richard@dazzle.plus.com                                               *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#include "station.h"
#include "scene.h"
#include <QPainter>
#include <QtCore/qmath.h>
#include <iostream>
#include "mainwindow.h"

using namespace std;

#define PI 3.14159265








/*************************************************************************************/
/******************* Represents a radio station in the simulation ********************/
/*************************************************************************************/

/************************************ constuctor *************************************/
Station::Station()
{

 //    stationRotation= 90;
}

Station::Station( qreal x, qreal y ) : QGraphicsItem()
{
  // set Station pixmap and position
  setPos( x, y );
  setFlags( QGraphicsItem::ItemIgnoresTransformations );
            //QGraphicsItem::ItemIsMovable |
           // QGraphicsItem::ItemIsSelectable |
 // stationRotation= 90;
    xMove=0;
    yMove=-.001;
    this->alive=true;
}

void Station::setXMove(qreal xM){
    xMove=xM;
}

void Station::setYMove(qreal yM){
    yMove=yM;
}

qreal Station::getXMove(){
    return xMove;
}

qreal Station::getYMove(){
    return yMove;
}

bool Station::getalive()
{
    return alive;
}

/************************************** advance ****************************************/

void Station::advance(int){

    qreal xDest = this->x() + xMove;
    qreal yDest = this->y() + yMove;

    if(xDest < 0)             xDest += WINDOW_WIDTH - 1;
    if(xDest > WINDOW_WIDTH)  xDest -= WINDOW_WIDTH;
    if(yDest < 15)             yDest += (WINDOW_HEIGHT - 50);
    if(yDest > WINDOW_HEIGHT-20) yDest -= (WINDOW_HEIGHT - 50);

    this->setPos( xDest, yDest );
}


/************************************** paintShip ****************************************/

void  Station::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setRenderHint( QPainter::Antialiasing );
  //---------------------------------------------------------------------------------------------------
  //Create Plane

    painter->setPen( QPen( Qt::white, 2 ) );
    painter->drawLine( +10*qCos((stationRotation-90)*PI/180),+10*qSin((stationRotation-90)*PI/180),  5*qCos((stationRotation+180)*PI/180),5*qSin((stationRotation+180)*PI/180) );
    painter->drawLine(  +5*qCos((stationRotation+180)*PI/180),5*qSin((stationRotation+180)*PI/180),  +10*qCos((stationRotation+90)*PI/180),+10*qSin((stationRotation+90)*PI/180));
    painter->drawLine( +10*qCos((stationRotation+90)*PI/180),+10*qSin((stationRotation+90)*PI/180),  +20*qCos((stationRotation+180)*PI/180),+20*qSin((stationRotation+180)*PI/180) );
    painter->drawLine( +20*qCos((stationRotation+180)*PI/180),+20*qSin((stationRotation+180)*PI/180),  +10*qCos((stationRotation-90)*PI/180),  +10*qSin((stationRotation-90)*PI/180) );

    painter->setPen( QPen( Qt::cyan, 2 ) );
    painter->drawRect( -21, -21, 42, 42);


}
