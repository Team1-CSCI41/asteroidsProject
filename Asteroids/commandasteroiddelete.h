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

#ifndef COMMANDasteroidDELETE_H
#define COMMANDasteroidDELETE_H

#include <QUndoCommand>
#include <QGraphicsScene>

/*************************************************************************************/
/*************** Undostack command for deleting a asteroid from a scene ***************/
/*************************************************************************************/

class CommandAsteroidDelete : public QUndoCommand
{
public:
  CommandAsteroidDelete( QGraphicsScene* scene, Asteroid* asteroid )
  {
    m_scene   = scene;
    m_asteroid = asteroid;
    setText( QString("asteroid delete %1,%2").arg(asteroid->x()).arg(asteroid->y()) );
  }

  virtual void undo()    { m_scene->addItem( m_asteroid ); }

  virtual void redo()    { m_scene->removeItem( m_asteroid ); }

private:
  QGraphicsScene*  m_scene;      // scene where asteroid being deleted
  Asteroid*         m_asteroid;    // asteroid being deleted
};

#endif  // CommandAsteroidDelete_H
