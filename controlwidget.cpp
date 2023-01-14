#include "controlwidget.h"
#include <QRegularExpression>
#include <QRegularExpressionValidator>

controlWidget::controlWidget(QWidget * parent) : QWidget(parent)
{
    setMinimumWidth(400);
    mainVLayout = new QVBoxLayout(this);
    getOutLayout  = new QHBoxLayout(this);

    QRegularExpression rx ("[0-9]*");
    QRegularExpressionValidator *val = new QRegularExpressionValidator(rx);

    takeBut = new QPushButton("Take the queue", this);
    getOutBut = new QPushButton("Get out of the queue", this);
    clientLab = new QLabel("Client number:", this);
    clientNEdit = new QLineEdit(this);
    clientNEdit->setValidator(val);

    getOutLayout->addWidget(clientLab);
    getOutLayout-> addWidget(clientNEdit);
    getOutLayout->addWidget(getOutBut);
    mainVLayout->addWidget(takeBut);
    mainVLayout->addLayout(getOutLayout);

    openLab = new QLabel("Cash desk number:");
    openDEdit = new QLineEdit(this);
    openDEdit->setValidator(val);
    openDeskB = new QPushButton("Open cash desk", this);
    openHLayout = new QHBoxLayout(this);
    openHLayout->addWidget(openLab);
    openHLayout->addWidget(openDEdit);
    openHLayout->addWidget(openDeskB);

    mainVLayout->addLayout(openHLayout);

    closeLab = new QLabel("Cash desk number:");
    closeDEdit = new QLineEdit(this);
    closeDEdit->setValidator(val);
    closeDeskB = new QPushButton("Close cash desk", this);
    closeHLayout = new QHBoxLayout(this);
    closeHLayout->addWidget(closeLab);
    closeHLayout->addWidget(closeDEdit);
    closeHLayout->addWidget(closeDeskB);

    mainVLayout->addLayout(closeHLayout);


    connect(takeBut, SIGNAL(released()), this, SIGNAL(takeTheQueue()));
    connect(getOutBut, SIGNAL(released()), this, SLOT(getOutSlot()));
    connect(openDeskB, SIGNAL(released()), this, SLOT(openDeskSlot()));
    connect(closeDeskB, SIGNAL(released()), this, SLOT(closeDeskSlot()));

}


void controlWidget::getOutSlot(){
    int client = clientNEdit->text().toInt();
    emit getOutSig(client);
}


void controlWidget::openDeskSlot(){
    int cashDesk = openDEdit->text().toInt();
    emit openDeskS(cashDesk);
}


void controlWidget::closeDeskSlot(){
    int cashDesk = closeDEdit->text().toInt();
    emit closeDeskS(cashDesk);
}


void controlWidget::moveEvent(QMoveEvent *moveEvent)
{
    emit moveSig();
}


controlWidget::~controlWidget(){
    //close();
    delete clientNEdit;
    delete openDEdit;
    delete closeDEdit;
    delete clientLab;
    delete openLab;
    delete closeLab;
    delete takeBut;
    delete getOutBut;
    delete openDeskB;
    delete closeDeskB;
    delete openHLayout;
    delete closeHLayout;
    delete getOutLayout;
    delete mainVLayout;
}


