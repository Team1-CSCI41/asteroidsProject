#ifndef COMMANDBULLETADD_H
#define COMMANDBULLETADD_H

#include <QUndoCommand>
#include <QGraphicsScene>

/*************************************************************************************/
/***************** Undostack command for adding a Bullet to a scene *****************/
/*************************************************************************************/

class CommandBulletAdd : public QUndoCommand
{
public:
  CommandBulletAdd( QGraphicsScene* scene, qreal x, qreal y )
    {
      m_bullet = new Bullet( x, y );
      m_scene   = scene;
      setText( QString("Bullet add %1,%2").arg(x).arg(y) );
    }

  ~CommandBulletAdd()
    {
      // if Bullet not on scene then delete Bullet
      if ( !m_scene->items().contains( m_bullet ) )
        delete m_bullet;
    }

  virtual void undo()    { m_scene->removeItem( m_bullet ); }

  virtual void redo()    { m_scene->addItem( m_bullet ); }

private:
  Bullet*         m_bullet;    // Bullet being added
  QGraphicsScene*  m_scene;      // scene where Bullet being added
};

#endif  // COMMANDBulletADD_H
