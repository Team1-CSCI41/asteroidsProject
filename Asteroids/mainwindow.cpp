
#include "mainwindow.h"
#include "scene.h"
#include <QPainter>
#include <QMenuBar>
#include <QStatusBar>
#include <QGraphicsView>
#include <QUndoStack>
#include <QUndoView>
#include <QFileDialog>
#include <QXmlStreamWriter>
#include <QXmlStreamReader>
#include <QDateTime>
#include <QPrinter>
#include <QPrintPreviewDialog>
#include <QPrintDialog>
#include <QCloseEvent>
#include <QMessageBox>
#include <QToolBar>

/*************************************************************************************/
/*********************** Main application window for QSimulate ***********************/
/*************************************************************************************/

/************************************ constuctor *************************************/

MainWindow::MainWindow() : QMainWindow()
{

  //CSS codes...
  this->setStyleSheet("background-color:black;");
  //


  QMenu*  fileMenu = menuBar()->addMenu( "&File" );
  menuBar()->setStyleSheet("background-color:white");

  QAction *newAction = fileMenu->addAction("&New Game", this, SLOT(fileNew()));
  fileMenu->addAction( "&Quit",             this, SLOT(close()) );


  //newAction->setShortcut( QKeySequence::New );


  // create undo stack and associated menu actions
  m_undoStack = new QUndoStack( this );
  m_undoView  = 0;
  //viewMenu->addAction( "Undo stack", this, SLOT(showUndoStack()) );
  QAction* undoAction = m_undoStack->createUndoAction( this );
  QAction* redoAction = m_undoStack->createRedoAction( this );
  undoAction->setShortcut( QKeySequence::Undo );
  redoAction->setShortcut( QKeySequence::Redo );

  // create toolbar, set icon size, and add actions
  QStyle*     style   = this->style();
  QSize       size    = style->standardIcon(QStyle::SP_DesktopIcon).actualSize( QSize(99,99) );


  // create scene and central widget view of scene
  m_scene               = new Scene();
  QGraphicsView*   view = new QGraphicsView( m_scene );
  view->setAlignment( Qt::AlignLeft | Qt::AlignTop );
  view->setFrameStyle( 0 );
  setCentralWidget( view );

  // connect message signal from scene to showMessage slot
  connect( m_scene, SIGNAL(message(QString)), this, SLOT(showMessage(QString)) );

  // add status bar message
  statusBar()->showMessage("You are now being attacked by flying rocks. Don't die if you can help it.");

  //sets window size by default
  setFixedSize(WINDOW_WIDTH, WINDOW_HEIGHT);



}

void MainWindow::fileNew()
{
    Scene *newScene= new Scene();

    QGraphicsView *view= dynamic_cast<QGraphicsView*>(centralWidget());
    view->setScene(newScene);
    delete m_scene;
    m_scene = newScene;
    view->setAlignment(Qt::AlignLeft | Qt::AlignRight);
    view->setFrameStyle(0);
    setCentralWidget(view);
}

/************************************ showMessage ************************************/

void  MainWindow::showMessage( QString msg )
{
  // display message on main window status bar
  //statusBar()->showMessage( msg );
}

/*********************************** showUndoStack ***********************************/

void  MainWindow::showUndoStack()
{

}

/************************************ fileSaveAs *************************************/

bool  MainWindow::fileSaveAs()
{

}

/************************************* fileOpen **************************************/

bool  MainWindow::fileOpen()
{
  // get user to select filename and location
  QString filename = QFileDialog::getOpenFileName();
  if ( filename.isEmpty() ) return false;

  // open the file and check we can read from it
  QFile file( filename );
  if ( !file.open( QIODevice::ReadOnly ) )
  {
    showMessage( QString("Failed to open '%1'").arg(filename) );
    return false;
  }

  // open an xml stream reader and load simulation data
  QXmlStreamReader  stream( &file );
  Scene*            newScene = new Scene();
  while ( !stream.atEnd() )
  {
    stream.readNext();
    if ( stream.isStartElement() )
    {
      if ( stream.name() == "qsimulate" )
        newScene->readStream( &stream );
      else
        stream.raiseError( QString("Unrecognised element '%1'").arg(stream.name().toString()) );
    }
  }

  // check if error occured
  if ( stream.hasError() )
  {
    file.close();
    showMessage( QString("Failed to load '%1' (%2)").arg(filename).arg(stream.errorString()) );
    delete newScene;
    return false;
  }

  // close file, display new scene, delete old scene, and display useful message
  file.close();
  m_undoStack->clear();
  QGraphicsView*   view = dynamic_cast<QGraphicsView*>( centralWidget() );
  view->setScene( newScene );
  delete m_scene;
  m_scene = newScene;
  showMessage( QString("Loaded '%1'").arg(filename) );
  return true;
}

/********************************* filePrintPreview **********************************/

void  MainWindow::filePrintPreview()
{

}

/************************************ filePrint **************************************/

void  MainWindow::filePrint()
{

}

/*************************************** print ***************************************/

void  MainWindow::print( QPrinter* printer )
{

}

/************************************** fileNew **************************************/



/************************************ closeEvent *************************************/

void  MainWindow::closeEvent( QCloseEvent* event )
{
  // if no stations (only default top-left scene anchor) exists then accept close event
  if ( m_scene->items().count() <= 1 )
  {
    event->accept();
    return;
  }

}
