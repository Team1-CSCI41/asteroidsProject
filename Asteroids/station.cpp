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


qreal shipCoord[21] = { +0, +3.125, -3.125, -4.6875, +6.25,
                        -6.25, -9.375, +12.5, -12.5, +14.0625,
                        -14.0625, +15.625, -15.625, +18.75, -18.75,
                        -21.875,  +25, -25, -26.5625, -28.125,
                        -46.875 };


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
    /*painter->setPen( QPen( Qt::red, 2 ) );
    painter->drawLine( shipCoord[0],  shipCoord[6],  shipCoord[1],  shipCoord[12]);
    painter->drawLine( shipCoord[1],  shipCoord[12],  shipCoord[0],  shipCoord[15]);
    painter->drawLine( shipCoord[0],  shipCoord[6],  shipCoord[2],  shipCoord[12]);
    painter->drawLine( shipCoord[2],  shipCoord[12],  shipCoord[0],  shipCoord[15]);
*/
  //Right Half
    painter->setPen( QPen( Qt::white, 2 ) );
    painter->drawLine( shipCoord[1],  shipCoord[2],  shipCoord[0],  shipCoord[2] );
    painter->drawLine( shipCoord[1],  shipCoord[2],  shipCoord[0],  shipCoord[0] );
    painter->drawLine( shipCoord[0],  shipCoord[0],  shipCoord[0],  shipCoord[2] );
    painter->drawLine( shipCoord[1],  shipCoord[2],  shipCoord[4],  shipCoord[2] );
    painter->drawLine( shipCoord[4],  shipCoord[2],  shipCoord[4],  shipCoord[6] );
    painter->drawLine( shipCoord[4],  shipCoord[6],  shipCoord[7],  shipCoord[6] );
    painter->drawLine(  shipCoord[7],  shipCoord[6],  shipCoord[7],  shipCoord[5] );
    painter->drawLine(  shipCoord[7],  shipCoord[5],  shipCoord[9],  shipCoord[3] );
    painter->drawLine(  shipCoord[9],  shipCoord[3],  shipCoord[11],  shipCoord[5]);
    painter->drawLine( shipCoord[11],  shipCoord[5],  shipCoord[11],  shipCoord[6] );
    painter->drawLine( shipCoord[11],  shipCoord[6],  shipCoord[13],  shipCoord[6] );
    painter->drawLine( shipCoord[13],  shipCoord[6],  shipCoord[16],  shipCoord[2]);
    painter->drawLine( shipCoord[16],  shipCoord[2],  shipCoord[16],  shipCoord[19]);
    painter->drawLine( shipCoord[16],  shipCoord[19],  shipCoord[13],  shipCoord[15]);
    painter->drawLine( shipCoord[13],  shipCoord[15],  shipCoord[11],  shipCoord[15]);
    painter->drawLine( shipCoord[11],  shipCoord[15],  shipCoord[11],  shipCoord[18]);
    painter->drawLine( shipCoord[11],  shipCoord[18],  shipCoord[9],  shipCoord[19] );
    painter->drawLine( shipCoord[9],  shipCoord[19],  shipCoord[7],  shipCoord[18]);
    painter->drawLine( shipCoord[7],  shipCoord[18],  shipCoord[7],  shipCoord[15] );
    painter->drawLine( shipCoord[7],  shipCoord[15],  shipCoord[4],  shipCoord[15]);
    painter->drawLine( shipCoord[4],  shipCoord[15],  shipCoord[0],  shipCoord[20] );

  //Left half
    painter->drawLine( shipCoord[2],  shipCoord[2],  shipCoord[0],  shipCoord[2] );
    painter->drawLine( shipCoord[2],  shipCoord[2],  shipCoord[0],  shipCoord[0] );
    painter->drawLine( shipCoord[0],  shipCoord[0],  shipCoord[0],  shipCoord[2] );
    painter->drawLine( shipCoord[2],  shipCoord[2],  shipCoord[5],  shipCoord[2] );
    painter->drawLine( shipCoord[5],  shipCoord[2],  shipCoord[5],  shipCoord[6] );
    painter->drawLine( shipCoord[5],  shipCoord[6],  shipCoord[8],  shipCoord[6] );
    painter->drawLine(  shipCoord[8],  shipCoord[6],  shipCoord[8],  shipCoord[5] );
    painter->drawLine(  shipCoord[8],  shipCoord[5],  shipCoord[10],  shipCoord[3] );
    painter->drawLine(  shipCoord[10],  shipCoord[3],  shipCoord[12],  shipCoord[5]);
    painter->drawLine( shipCoord[12],  shipCoord[5],  shipCoord[12],  shipCoord[6] );
    painter->drawLine( shipCoord[12],  shipCoord[6],  shipCoord[14],  shipCoord[6] );
    painter->drawLine( shipCoord[14],  shipCoord[6],  shipCoord[17],  shipCoord[2]);
    painter->drawLine( shipCoord[17],  shipCoord[2],  shipCoord[17],  shipCoord[19]);
    painter->drawLine( shipCoord[17],  shipCoord[19],  shipCoord[14],  shipCoord[15]);
    painter->drawLine( shipCoord[14],  shipCoord[15],  shipCoord[12],  shipCoord[15]);
    painter->drawLine( shipCoord[12],  shipCoord[15],  shipCoord[12],  shipCoord[18]);
    painter->drawLine( shipCoord[12],  shipCoord[18], shipCoord[10],  shipCoord[19] );
    painter->drawLine( shipCoord[10],  shipCoord[19],  shipCoord[8],  shipCoord[18]);
    painter->drawLine( shipCoord[8],  shipCoord[18],  shipCoord[8],  shipCoord[15] );
    painter->drawLine( shipCoord[8],  shipCoord[15],  shipCoord[5],  shipCoord[15]);
    painter->drawLine( shipCoord[5],  shipCoord[15],  shipCoord[0],  shipCoord[20] );


}
