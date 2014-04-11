#ifndef COMMANDAsteroidADD_H
#define COMMANDAsteroidADD_H

#include <QUndoCommand>
#include <QGraphicsScene>

/*************************************************************************************/
/***************** Undostack command for adding a Asteroid to a scene *****************/
/*************************************************************************************/

class CommandAsteroidAdd : public QUndoCommand
{
public:
  CommandAsteroidAdd( QGraphicsScene* scene, qreal x, qreal y )
    {
      m_asteroid = new Asteroid( x, y );
      m_scene   = scene;
      setText( QString("Asteroid add %1,%2").arg(x).arg(y) );
    }

  ~CommandAsteroidAdd()
    {
      // if Asteroid not on scene then delete Asteroid
      if ( !m_scene->items().contains( m_asteroid ) )
        delete m_asteroid;
    }

  virtual void undo()    { m_scene->removeItem( m_asteroid ); }

  virtual void redo()    { m_scene->addItem( m_asteroid ); }

private:
  Asteroid*         m_asteroid;    // Asteroid being added
  QGraphicsScene*  m_scene;      // scene where Asteroid being added
};

#endif  // COMMANDAsteroidADD_H
