#include "settingswidget.h"

settingsWidget::settingsWidget(QWidget * parent): QWidget(parent)
{
    setMinimumWidth(400);
    settLay = new QVBoxLayout(this);
    probModeLayout =  new QHBoxLayout(this);
    themeLayout = new QHBoxLayout(this);
    probModeLab = new QLabel("Distribution of clients by cash desks: ", this);
    themeLab = new QLabel("Application theme: ", this);

    probBut = new QPushButton("Probability mode", this);
    themeBut =  new QPushButton("Theme", this);

    probModeMenu = new QMenu(this);

    equalMode = new QAction("Equal probability", this);
    queueLengthMode = new QAction("Depends on queue length", this);

    probModeMenu->addAction(equalMode);
    probModeMenu->addAction(queueLengthMode);

    probBut->setMenu(probModeMenu);

    themeMenu = new QMenu(this);

    perfectWhiteTheme = new QAction("Perfect white", this);
    lemonGateTheme = new QAction("Lemon gate", this);
    fruitBlendTheme = new QAction("Fruit blend", this);
    plumPlateTheme = new QAction("Plum plate", this);

    themeMenu->addAction(perfectWhiteTheme);
    themeMenu->addAction(lemonGateTheme);
    themeMenu->addAction(fruitBlendTheme);
    themeMenu->addAction(plumPlateTheme);

    themeBut->setMenu(themeMenu);


    themeLayout->addWidget(themeLab);
    themeLayout->addWidget(themeBut);
    probModeLayout->addWidget(probModeLab);
    probModeLayout->addWidget(probBut);

    settLay->addLayout(probModeLayout);
    settLay->addLayout(themeLayout);


    connect(perfectWhiteTheme, SIGNAL(triggered()), this, SIGNAL(perfectWhiteSig()));
    connect(lemonGateTheme, SIGNAL(triggered()), this, SIGNAL(lemonGateSig()));
    connect(fruitBlendTheme, SIGNAL(triggered()), this, SIGNAL(fruitBlendSig()));
    connect(plumPlateTheme, SIGNAL(triggered()), this, SIGNAL(plumPlateSig()));
    connect(equalMode, SIGNAL(triggered()), this, SIGNAL(equalModeSig()));
    connect(queueLengthMode, SIGNAL(triggered()), this, SIGNAL(queueLengthModeSig()));
}




settingsWidget::~settingsWidget(){
    //close();
    delete probModeLab;
    delete themeLab;
    delete probBut;
    delete themeBut;
    delete probModeMenu;
    delete equalMode;
    delete queueLengthMode;
    delete themeMenu;
    delete perfectWhiteTheme;
    delete lemonGateTheme;
    delete fruitBlendTheme;
    delete plumPlateTheme;
    delete themeLayout;
    delete probModeLayout;
    delete settLay;
}
