#ifndef COMMANDBULLETMOVE_H
#define COMMANDBULLETMOVE_H

#include "bullet.h"

#include <QUndoCommand>

/*************************************************************************************/
/***************** Undostack command for moving a asteriod on a scene *****************/
/*************************************************************************************/

class CommandBulletMove : public QUndoCommand
{
public:
  CommandBulletMove( Bullet* bullet, qreal fromX, qreal fromY, qreal toX, qreal toY )
  {
    m_bullet = bullet;
    m_from    = QPointF( fromX, fromY );
    m_to      = QPointF( toX, toY );
    setText( QString("Bullet move %1,%2 -> %3,%4").arg(fromX).arg(fromY).arg(toX).arg(toY) );
  }

  virtual void undo()    { m_bullet->setPos( m_from ); }

  virtual void redo()    { m_bullet->setPos( m_to ); }

private:
  Bullet*   m_bullet;       // asteriod being moved
  QPointF    m_from;          // original coords
  QPointF    m_to;            // new coords
};

#endif  // CommandbulletMove_H
