#ifndef SCENE_H
#define SCENE_H

class QGraphicsSceneMouseEvent;
class QGraphicsSceneContextMenuEvent;
class QUndoStack;
class QXmlStreamWriter;
class QXmlStreamReader;
class Station;

#include <QGraphicsScene>

/*************************************************************************************/
/******************** Scene representing the simulated landscape *********************/
/*************************************************************************************/

class Scene : public QGraphicsScene
{
  Q_OBJECT
public:
  Scene( QUndoStack* );                       // constructor
  void  writeStream( QXmlStreamWriter* );     // write scene data to xml stream
  void  readStream( QXmlStreamReader* );      // read scene data from xml stream

signals:
  void  message( QString );                   // info text message signal

public slots:
  void  selectStations();                     // records selected stations & positions

protected:
  void  mousePressEvent( QGraphicsSceneMouseEvent* );        // receive mouse press events
  void  mouseReleaseEvent( QGraphicsSceneMouseEvent* );      // receive mouse release events
  void  contextMenuEvent( QGraphicsSceneContextMenuEvent* ); // receive context menu events

private:
  typedef QPair<Station*,QPointF>     StationPos;
  QList<StationPos>   m_stations;             // currently selected stations & start positions
  QUndoStack*         m_undoStack;            // undo stack for undo & redo of commands
};

#endif  // SCENE_H
