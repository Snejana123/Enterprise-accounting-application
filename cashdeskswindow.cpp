#include "cashdeskswindow.h"
#include <QCloseEvent>


cashDesksWindow::cashDesksWindow(QWidget *parent):subWin(new QMdiSubWindow(parent))
{
    setAttribute(Qt::WA_DeleteOnClose, true);
    mainW = new cashWidget(this);
    mainW->addCashDesk();
    subWin->setWidget(mainW);
    mainW->show();
    subWin->adjustSize();
    subWin->setWindowTitle("Cash desks");
}




cashDesksWindow::~cashDesksWindow()
{
    //close();
    delete mainW;
    delete subWin;
}



