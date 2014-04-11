
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

const int WINDOW_WIDTH=600;
const int WINDOW_HEIGHT=600;

class Scene;
class QUndoStack;
class QUndoView;
class QPrinter;

#include <QMainWindow>

/*************************************************************************************/
/*********************** Main application window for QSimulate ***********************/
/*************************************************************************************/

class MainWindow : public QMainWindow
{
  Q_OBJECT
public:
  MainWindow();                       // constructor

public slots:
  void showMessage( QString );        // show message on status bar
  void showUndoStack();               // open up undo stack window
  void fileNew();                     // start new simulation
  bool fileSaveAs();                  // save simulation to file returning true if successful
  bool fileOpen();                    // load simulation file returning true if successful
  void filePrintPreview();            // display print preview dialog
  void filePrint();                   // display print dialog
  void print( QPrinter* );            // draw print page

protected:
  void closeEvent( QCloseEvent* );    // check if user really wants to exit

private:
  Scene*       m_scene;               // scene representing the simulated landscape
  QUndoStack*  m_undoStack;           // undo stack for undo & redo of commands
  QUndoView*   m_undoView;            // undo stack window to view undo & redo commands
};

#endif  // MAINWINDOW_H
