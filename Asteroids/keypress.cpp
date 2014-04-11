#include <QApplication>
#include <QKeyEvent>
#include <QtCore/qmath.h>
#include "keypress.h"
#include "station.h"
#include "scene.h"

#define PI 3.14159265

KeyPress::KeyPress(QWidget *parent) :
    QWidget(parent)
{
}

void KeyPress::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
        case Qt::Key_A:
        {
            stationRotation += 5;
            if(stationRotation > 359) stationRotation -= 360;
        }

        case Qt::Key_D:
        {
            stationRotation += 5;
            if(stationRotation < 0) stationRotation += 360;
        }

        case Qt::Key_W:
        {
            stationMoveX += 2 * qCos(stationRotation * PI / 180);
            stationMoveY += 2 * qSin(stationRotation * PI / 180);
        }
    }
}

void KeyPress::keyReleaseEvent(QKeyEvent *event)
{
}
/*
    if(event->key() == Qt::Key_W)
    {
        myLabelText->setText("You Released Key Q");
    }
    else
    {
        myLabelText->setText("You Released Other Key");
    }
}
*/
