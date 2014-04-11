
#ifndef COMMANDASTEROIDMOVE_H
#define COMMANDASTEROIDMOVE_H

#include "asteroid.h"

#include <QUndoCommand>

/*************************************************************************************/
/***************** Undostack command for moving a asteriod on a scene *****************/
/*************************************************************************************/

class CommandAsteroidMove : public QUndoCommand
{
public:
  CommandAsteroidMove( Asteroid* asteroid, qreal fromX, qreal fromY, qreal toX, qreal toY )
  {
    m_asteroid = asteroid;
    m_from    = QPointF( fromX, fromY );
    m_to      = QPointF( toX, toY );
    setText( QString("Asteroid move %1,%2 -> %3,%4").arg(fromX).arg(fromY).arg(toX).arg(toY) );
  }

  virtual void undo()    { m_asteroid->setPos( m_from ); }

  virtual void redo()    { m_asteroid->setPos( m_to ); }

private:
  Asteroid*   m_asteroid;       // asteriod being moved
  QPointF    m_from;          // original coords
  QPointF    m_to;            // new coords
};

#endif  // CommandAsteroidMove_H
