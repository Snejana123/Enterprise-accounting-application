#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H

#include "settingswidget.h"
#include <QMdiSubWindow>

class settingsWindow : public QMdiSubWindow
{
    QMdiSubWindow * subWin;
public:
    settingsWidget * setWid;
    settingsWindow(QWidget *parent);
    ~settingsWindow();
};

#endif // SETTINGSWINDOW_H
