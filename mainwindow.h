#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QApplication>
#include <QMainWindow>
#include <QMdiArea>
#include <QStatusBar>

//#include <QSessionManager>

#include "cashdeskswindow.h"
#include "controlwindow.h"
#include "settingswindow.h"




class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();
    ~MainWindow();

public slots:
    void backgroundTheme(QGradient);
    void lemonGateSlot();
    void fruitBlendSlot();
    void plumPlateSlot();
    void perfectWhiteSlot();
    void equalModeSlot();
    void queueLengthModeSlot();

private:
    QMdiArea * mdiArea;
    cashDesksWindow * cashSubW;
    controlWindow * controlSubW;
    settingsWindow * settSubW;
    void createActions();
    void createStatusBar();
    QStatusBar * statBar;
private slots:
    void aboutSlot();
    void settingsSlot();
    void cashDesksSlot();
    void controlWindSlot();
    void repaintSl();
};
#endif // MAINWINDOW_H
