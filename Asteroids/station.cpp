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
#include <QPainter>
#include <QtCore/qmath.h>
#include <iostream>

using namespace std;

#define PI 3.14159265

extern int   stationRotation = 90;
qreal sine[360], cosine[360];





/*************************************************************************************/
/******************* Represents a radio station in the simulation ********************/
/*************************************************************************************/

/************************************ constuctor *************************************/
Station::Station()
{
}

Station::Station( qreal x, qreal y ) : QGraphicsItem()
{
  // set Station pixmap and position
  setPos( x, y );
  setFlags( QGraphicsItem::ItemIgnoresTransformations );
            //QGraphicsItem::ItemIsMovable |
           // QGraphicsItem::ItemIsSelectable |
  int i;
  for(i=0; i <=359; i++)
  {
      sine[i]   = qSin(i * PI / 180);
      cosine[i] = qCos(i * PI / 180);
  }
}

/************************************** paintShip ****************************************/

void  Station::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setRenderHint( QPainter::Antialiasing );
  //---------------------------------------------------------------------------------------------------
  //Create Plane

    painter->setPen( QPen( Qt::green, 2 ) );
    painter->drawLine( +10,  +0,  +0,  -5 );
    painter->drawLine(  +0,  -5,  -10,  +0 );
    painter->drawLine( -10,  +0,  +0,  -20 );
    painter->drawLine( +0,  -20 ,  +10,  +0 );


}
