#include "cashdeskhbox.h"

cashDeskHBox::cashDeskHBox(QWidget * parent, int deskNum): QHBoxLayout(parent)
{
    maxClient = 0;
    desksNum = 0;
    parentW = parent;
    deskLabel = new QLabel(parentW);
    mainFont.setBold(true);
    mainFont.setPointSize(20);
    deskLabel->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    deskLabel->setStyleSheet("QLabel { background-color : green; color : black}");
    deskLabel->setFont(mainFont);
    deskLabel->setText(QString().setNum(deskNum));
    addWidget(deskLabel);
    isOpen = true;
}

void cashDeskHBox::addClient(int clientNum){
    if (clientNum > maxClient)
    {
        maxClient = clientNum;
    }
    QLabel * newClient = new QLabel(QString().setNum(clientNum), parentW);
    newClient->setStyleSheet("QLabel { background-color : black; color : white}");
    newClient->setFont(mainFont);
    newClient->setNum(clientNum);
    newClient->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    clientsLabels.append(newClient);
    addWidget(newClient);
    desksNum += 1;
}

bool cashDeskHBox::deleteClient(int clientNum){
    int size = clientsLabels.size();
    QLabel *next;
    if (clientNum == maxClient)
    {
        int preMaxClient = 0;
        for (int i = 0; i < size; i++)
        {
            next = clientsLabels.value(i);
            QString txt = next->text();
            int nextNum = txt.toInt();
            if ((nextNum < maxClient) && (nextNum > preMaxClient))
            {
                preMaxClient = nextNum;
            }
            if (txt == QString().setNum(clientNum))
            {
                removeWidget(clientsLabels.at(i));
                clientsLabels.removeAt(i);
                delete next;
                desksNum -= 1;
                return true;
            }
        }
        maxClient = preMaxClient;
    }else
    {
        for (int i = 0; i < size; i++)
        {
            next = clientsLabels.value(i);
            QString txt = next->text();
            if (txt == QString().setNum(clientNum))
            {
                removeWidget(clientsLabels.at(i));
                clientsLabels.removeAt(i);
                delete next;
                desksNum -= 1;
                return true;
            }
        }
    }
    return false;
}

bool cashDeskHBox::isClient(int clientNum){
    int size = clientsLabels.size();
    QLabel *next;
    for (int i = 0; i < size; i++){
        next = clientsLabels.value(i);
        QString txt = next->text();
        if (txt == QString().setNum(clientNum)){
            return true;
        }
    }
    return false;
}

void cashDeskHBox::closeDesk(){
    isOpen = false;
    deskLabel->setStyleSheet("QLabel { background-color : red; color : black}");
}

void cashDeskHBox::openDesk(){
    isOpen = true;
    deskLabel->setStyleSheet("QLabel { background-color : green; color : black}");
}

int cashDeskHBox::getDeskNumber(){
    return desksNum;
}


bool cashDeskHBox::getOpenStatus(){
    return isOpen;
}


int cashDeskHBox::getMaxClient(){
    return maxClient;
}


int cashDeskHBox::getDesksNum(){
    return desksNum;
}


cashDeskHBox::~cashDeskHBox(){
    delete deskLabel;
    int size = clientsLabels.size();
    QLabel *next;
    for (int i = 0; i < size; i++){
        next = clientsLabels.value(i);
        delete next;
    }
    clients.clear();
    clientsLabels.clear();
}

