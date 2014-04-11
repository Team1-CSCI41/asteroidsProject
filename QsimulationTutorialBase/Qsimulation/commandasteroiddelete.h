
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
