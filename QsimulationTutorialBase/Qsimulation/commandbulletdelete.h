#ifndef COMMANDBULLETDELETE_H
#define COMMANDBULLETDELETE_H

#include <QUndoCommand>
#include <QGraphicsScene>

/*************************************************************************************/
/*************** Undostack command for deleting a bullet from a scene ***************/
/*************************************************************************************/

class CommandBulletDelete : public QUndoCommand
{
public:
  CommandBulletDelete( QGraphicsScene* scene, Bullet* bullet )
  {
    m_scene   = scene;
    m_bullet = bullet;
    setText( QString("bullet delete %1,%2").arg(bullet->x()).arg(bullet->y()) );
  }

  virtual void undo()    { m_scene->addItem( m_bullet ); }

  virtual void redo()    { m_scene->removeItem( m_bullet ); }

private:
  QGraphicsScene*  m_scene;      // scene where bullet being deleted
  Bullet*         m_bullet;    // bullet being deleted
};

#endif  // CommandbulletDelete_H
