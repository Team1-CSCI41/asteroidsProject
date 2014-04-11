#include <QWidget>
#include <QtGui>
extern int stationRotation;
extern qreal stationMoveX, stationMoveY;

class KeyPress : public QWidget
{
    Q_OBJECT

public:
    KeyPress(QWidget *parent = 0);

protected:
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

private:
    QLabel *myLabelText;
};

