#ifndef CASHDESKSWINDOW_H
#define CASHDESKSWINDOW_H

#include <QMdiSubWindow>
#include<QHBoxLayout>
#include <QVBoxLayout>
#include <QWidget>
#include <QLabel>
#include <QFont>
#include <QVector>
#include <QPushButton>
#include <QObject>
#include "cashdeskhbox.h"
#include "cashwidget.h"


class cashDesksWindow : public QMdiSubWindow
{


public:
    cashDesksWindow(QWidget *);
    ~cashDesksWindow();
    cashWidget * mainW;

private:
    QMdiSubWindow* subWin;

};

#endif // CASHDESKSWINDOW_H
