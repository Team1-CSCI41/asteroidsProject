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

#ifndef SCENE_H
#define SCENE_H

class QGraphicsSceneMouseEvent;
class QGraphicsSceneContextMenuEvent;
class QUndoStack;
class QXmlStreamWriter;
class QXmlStreamReader;
class Station;
class Bullet;
class Asteroid;

#include <QGraphicsScene>
#include <QtGui>


extern int stationRotation;

/*************************************************************************************/
/******************** Scene representing the simulated landscape *********************/
/*************************************************************************************/

class Scene : public QGraphicsScene
{
  Q_OBJECT
public:
  Scene(  );                       // constructor
  void  writeStream( QXmlStreamWriter* );     // write scene data to xml stream
  void  readStream( QXmlStreamReader* );      // read scene data from xml stream
  qreal stationMoveX, stationMoveY;           // movement variables for ship
  // A function that generates the asteroids/creates asteroid list
  void generateAsteroids();
  void generateBullets();
  bool alive;



signals:
  void  message( QString );                   // info text message signal

public slots:
  void  selectStations();                     // records selected stations & positions
  void  manageObjects();                      // moves objects by updating their positions
  void collisionDetection(); // COLLISION DETECTION. DUH!

protected:
  void  mousePressEvent( QGraphicsSceneMouseEvent* );        // receive mouse press events
  void  mouseReleaseEvent( QGraphicsSceneMouseEvent* );      // receive mouse release events
  void  contextMenuEvent( QGraphicsSceneContextMenuEvent* ); // receive context menu events

  void  keyPressEvent(QKeyEvent *event);

  Station*  station;
  Bullet*  bullet;
  Asteroid*  asteroid;

  QString livesString;
  QLabel *livesLabel;
  QLabel *gameOverLabel;




private:
  typedef QPair<Station*,QPointF>     StationPos;
  QList<StationPos>   m_stations;             // currently selected stations & start positions
  // Random comment.
  QUndoStack*         m_undoStack;            // undo stack for undo & redo of commands
};

#endif  // SCENE_H
