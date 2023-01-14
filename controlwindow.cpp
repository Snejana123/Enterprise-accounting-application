#include "controlwindow.h"
#include <QCloseEvent>

controlWindow::controlWindow(QWidget * parent): subWin(new QMdiSubWindow(parent))
{
    setAttribute(Qt::WA_DeleteOnClose, true);
    mainW = new controlWidget(this);

    subWin->setWidget(mainW);
    mainW->show();
    subWin->adjustSize();
    subWin->setWindowTitle("Control window");
}


controlWindow::~controlWindow(){
    //close();
    delete mainW;
    delete subWin;
}

