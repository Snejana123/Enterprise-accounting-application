#include "settingswindow.h"
#include <QCloseEvent>

settingsWindow::settingsWindow(QWidget * parent): subWin(new QMdiSubWindow(parent))
{
    setAttribute(Qt::WA_DeleteOnClose, true);
    setWid = new settingsWidget(this);
    subWin->setWidget(setWid);
    setWid->show();
    subWin->adjustSize();
    subWin->setWindowTitle("Settings");
}

settingsWindow::~settingsWindow(){
    //close();
    delete setWid;
    delete subWin;
}



