#ifndef CONTROLWINDOW_H
#define CONTROLWINDOW_H

#include <QMdiSubWindow>
#include "controlwidget.h"


class controlWindow: public QMdiSubWindow
{
    QMdiSubWindow * subWin;

public:
    controlWindow(QWidget *);
    ~controlWindow();
    controlWidget * mainW;
};

#endif // CONTROLWINDOW_H
