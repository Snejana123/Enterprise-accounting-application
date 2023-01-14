#include "mainwindow.h"
#include <QMenuBar>
#include <QSize>


MainWindow::MainWindow()
{
    setAttribute(Qt::WA_DeleteOnClose, true);
    const QIcon accDep = QIcon::fromTheme("Accounts department", QIcon(":/images/appIcon.png"));
    setWindowIcon(accDep);
    setWindowTitle("Accounts department");
    createStatusBar();
    createActions();

    mdiArea = new QMdiArea(this);
    mdiArea->setAttribute(Qt::WA_DeleteOnClose, true);
    mdiArea -> setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    mdiArea -> setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    mdiArea->setMinimumSize(700, 500);
    mdiArea->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    QGradient test(QGradient::LemonGate);
    test.setCoordinateMode(QGradient::StretchToDeviceMode);
    mdiArea->setBackground(test);
    mdiArea->setAutoFillBackground(true);
    setCentralWidget(mdiArea);

    cashSubW = new cashDesksWindow (mdiArea);
    cashSubW->setAttribute(Qt::WA_DeleteOnClose, true);
    cashSubW->show();

    controlSubW = new controlWindow (mdiArea);
    controlSubW->setAttribute(Qt::WA_DeleteOnClose, true);
    controlSubW ->show();

    settSubW  = new settingsWindow(mdiArea);
    settSubW->setAttribute(Qt::WA_DeleteOnClose, true);
    settSubW -> show();
    settSubW->activateWindow();


    connect(controlSubW->mainW, SIGNAL(getOutSig(int)), cashSubW->mainW, SLOT(getOutOfTheQueue(int)));
    connect(controlSubW->mainW, SIGNAL(takeTheQueue()), cashSubW->mainW, SLOT(addClient()));
    connect(controlSubW->mainW, SIGNAL(openDeskS(int)), cashSubW->mainW, SLOT(openCashDesk(int)));
    connect(controlSubW->mainW, SIGNAL(closeDeskS(int)), cashSubW->mainW, SLOT(closeCashDesk(int)));

    connect(controlSubW->mainW, SIGNAL(moveSig()), cashSubW->mainW, SLOT(repaintSl()) );

    connect(settSubW->setWid, SIGNAL(lemonGateSig()), this, SLOT(lemonGateSlot()));
    connect(settSubW->setWid, SIGNAL(fruitBlendSig()), this, SLOT(fruitBlendSlot()));
    connect(settSubW->setWid, SIGNAL(plumPlateSig()), this, SLOT(plumPlateSlot()));
    connect(settSubW->setWid, SIGNAL(perfectWhiteSig()), this, SLOT(perfectWhiteSlot()));
    connect(settSubW->setWid, SIGNAL(equalModeSig()), this, SLOT(equalModeSlot()));
    connect(settSubW->setWid, SIGNAL(queueLengthModeSig()), this, SLOT(queueLengthModeSlot()));
}


void MainWindow::repaintSl(){
    mdiArea->update();
    mdiArea->repaint();
}


void MainWindow::createStatusBar()
{
    statBar = new QStatusBar(this);
    setStatusBar(statBar);
    statBar->showMessage(tr("Ready"));
}


void MainWindow::createActions()
{

    QMenu *fileMenu = menuBar()->addMenu(tr("&File"));

    QAction *settAct = new QAction(tr("Settings"), this);
    settAct->setShortcut(tr("CTRL+SHIFT+S"));
    settAct->setStatusTip(tr("Show applicaion settings"));
    connect(settAct, &QAction::triggered, this, &MainWindow::settingsSlot);
    fileMenu->addAction(settAct);

    const QIcon exitIcon = QIcon::fromTheme("application-exit");
    QAction *exitAct = fileMenu->addAction(exitIcon, tr("&Exit"), qApp, &QApplication::quit);
    exitAct->setShortcuts(QKeySequence::Quit);
    exitAct->setStatusTip(tr("Exit the application"));
    fileMenu->addAction(exitAct);


    QMenu *viewMenu =  menuBar()->addMenu(tr("&View"));
    QAction *cashDesksQtAct = new QAction(tr("New cash desks"), this);
    cashDesksQtAct->setShortcut(tr("CTRL+D"));
    cashDesksQtAct->setStatusTip(tr("Delete current cash desk box and show new"));
    connect(cashDesksQtAct, &QAction::triggered, this, &MainWindow::cashDesksSlot);
    viewMenu->addAction(cashDesksQtAct);

    QAction * controlWindAct = new QAction(tr("Control window"), this);
    controlWindAct->setShortcut(tr("CTRL+SHIFT+W"));
    controlWindAct->setStatusTip(tr("Show control window"));
    connect(controlWindAct, &QAction::triggered, this, &MainWindow::controlWindSlot);
    viewMenu -> addAction(controlWindAct);



    QMenu *helpMenu =  menuBar()->addMenu(tr("&Help"));
    QAction *aboutQtAct = helpMenu->addAction(tr("About &Qt"), qApp, &QApplication::aboutQt);
    aboutQtAct->setShortcut(tr("CTRL+A"));
    aboutQtAct->setStatusTip(tr("Show the Qt library's About box"));
    helpMenu->addAction(aboutQtAct);

    QAction * aboutApp = new QAction(tr("About application"), this);
    aboutApp->setShortcut(tr("CTRL+SHIFT+A"));
    aboutApp->setStatusTip(tr("About application box"));
    connect(aboutApp, &QAction::triggered, this, &MainWindow::aboutSlot);
    helpMenu->addAction(aboutApp);



}


void MainWindow::aboutSlot(){
    QMessageBox::information(this, "About application", "Course work. Student: Leonova Amelia");
}


void MainWindow::cashDesksSlot(){
    disconnect(controlSubW->mainW, SIGNAL(getOutSig(int)), cashSubW->mainW, SLOT(getOutOfTheQueue(int)));
    disconnect(controlSubW->mainW, SIGNAL(takeTheQueue()), cashSubW->mainW, SLOT(addClient()));
    disconnect(controlSubW->mainW, SIGNAL(openDeskS(int)), cashSubW->mainW, SLOT(openCashDesk(int)));
    disconnect(controlSubW->mainW, SIGNAL(closeDeskS(int)), cashSubW->mainW, SLOT(closeCashDesk(int)));
    cashSubW->close();
    delete cashSubW;
    cashSubW = new cashDesksWindow (mdiArea);
    cashSubW->setAttribute(Qt::WA_DeleteOnClose, true);
    cashSubW -> show();
    cashSubW->activateWindow();
    connect(controlSubW->mainW, SIGNAL(getOutSig(int)), cashSubW->mainW, SLOT(getOutOfTheQueue(int)));
    connect(controlSubW->mainW, SIGNAL(takeTheQueue()), cashSubW->mainW, SLOT(addClient()));
    connect(controlSubW->mainW, SIGNAL(openDeskS(int)), cashSubW->mainW, SLOT(openCashDesk(int)));
    connect(controlSubW->mainW, SIGNAL(closeDeskS(int)), cashSubW->mainW, SLOT(closeCashDesk(int)));
}


void MainWindow::controlWindSlot(){
    disconnect(controlSubW->mainW, SIGNAL(getOutSig(int)), cashSubW->mainW, SLOT(getOutOfTheQueue(int)));
    disconnect(controlSubW->mainW, SIGNAL(takeTheQueue()), cashSubW->mainW, SLOT(addClient()));
    disconnect(controlSubW->mainW, SIGNAL(openDeskS(int)), cashSubW->mainW, SLOT(openCashDesk(int)));
    disconnect(controlSubW->mainW, SIGNAL(closeDeskS(int)), cashSubW->mainW, SLOT(closeCashDesk(int)));
    controlSubW->close();
    delete controlSubW;
    controlSubW = new controlWindow (mdiArea);
    controlSubW->setAttribute(Qt::WA_DeleteOnClose, true);
    controlSubW -> show();
    controlSubW->activateWindow();
    connect(controlSubW->mainW, SIGNAL(getOutSig(int)), cashSubW->mainW, SLOT(getOutOfTheQueue(int)));
    connect(controlSubW->mainW, SIGNAL(takeTheQueue()), cashSubW->mainW, SLOT(addClient()));
    connect(controlSubW->mainW, SIGNAL(openDeskS(int)), cashSubW->mainW, SLOT(openCashDesk(int)));
    connect(controlSubW->mainW, SIGNAL(closeDeskS(int)), cashSubW->mainW, SLOT(closeCashDesk(int)));
}


void MainWindow::settingsSlot(){
    disconnect(settSubW->setWid, SIGNAL(lemonGateSig()), this, SLOT(lemonGateSlot()));
    disconnect(settSubW->setWid, SIGNAL(fruitBlendSig()), this, SLOT(fruitBlendSlot()));
    disconnect(settSubW->setWid, SIGNAL(plumPlateSig()), this, SLOT(plumPlateSlot()));
    disconnect(settSubW->setWid, SIGNAL(perfectWhiteSig()), this, SLOT(perfectWhiteSlot()));
    disconnect(settSubW->setWid, SIGNAL(equalModeSig()), this, SLOT(equalModeSlot()));
    disconnect(settSubW->setWid, SIGNAL(queueLengthModeSig()), this, SLOT(queueLengthModeSlot()));
    settSubW->close();
    delete settSubW;
    settSubW  = new settingsWindow(mdiArea);
    settSubW->setAttribute(Qt::WA_DeleteOnClose, true);
    settSubW -> show();
    settSubW->activateWindow();
    connect(settSubW->setWid, SIGNAL(lemonGateSig()), this, SLOT(lemonGateSlot()));
    connect(settSubW->setWid, SIGNAL(fruitBlendSig()), this, SLOT(fruitBlendSlot()));
    connect(settSubW->setWid, SIGNAL(plumPlateSig()), this, SLOT(plumPlateSlot()));
    connect(settSubW->setWid, SIGNAL(perfectWhiteSig()), this, SLOT(perfectWhiteSlot()));
    connect(settSubW->setWid, SIGNAL(equalModeSig()), this, SLOT(equalModeSlot()));
    connect(settSubW->setWid, SIGNAL(queueLengthModeSig()), this, SLOT(queueLengthModeSlot()));
}


void MainWindow::backgroundTheme(QGradient newBack){
    mdiArea->setBackground(newBack);
}


void MainWindow::equalModeSlot(){
    cashSubW->mainW->setProbMode(0);
    QMessageBox::information(0, "Accounts department","Equal mode is seted.");
}


void MainWindow::queueLengthModeSlot(){
    cashSubW->mainW->setProbMode(1);
    QMessageBox::information(0, "Accounts department","Queue length mode is seted.");
}



void MainWindow::lemonGateSlot(){
    QGradient newBack(QGradient::LemonGate);
    newBack.setCoordinateMode(QGradient::StretchToDeviceMode);
    mdiArea->setBackground(newBack);
}


void MainWindow::fruitBlendSlot(){
    QGradient newBack(QGradient::FruitBlend);
    newBack.setCoordinateMode(QGradient::StretchToDeviceMode);
    mdiArea->setBackground(newBack);
}


void MainWindow::plumPlateSlot(){
    QGradient newBack(QGradient::PlumPlate);
    newBack.setCoordinateMode(QGradient::StretchToDeviceMode);
    mdiArea->setBackground(newBack);
}


void MainWindow::perfectWhiteSlot(){
    QGradient newBack(QGradient::PerfectWhite);
    newBack.setCoordinateMode(QGradient::StretchToDeviceMode);
    mdiArea->setBackground(newBack);
}


MainWindow::~MainWindow()
{
    mdiArea->closeAllSubWindows();
    delete cashSubW;
    delete controlSubW;
    delete mdiArea;
    delete settSubW;
}

