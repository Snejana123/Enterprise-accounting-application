#include "cashwidget.h"
#include <QMessageBox>

cashWidget::cashWidget(QWidget * parent): QWidget(parent)
{
    setMinimumWidth(400);
    parentW = parent;
    cashL = new QVBoxLayout(this);

    addCDesk = new QPushButton("Add cash desk", this);
    cashL -> addWidget(addCDesk);
    removeCDesk = new QPushButton("Remove cash desk", this);
    cashL -> addWidget(removeCDesk);

    cashDeskHBox* newDeskBox =  new cashDeskHBox(this, 1);

    desksBoxes.append(newDeskBox);

    cashL -> addLayout(newDeskBox);



    connect(addCDesk, SIGNAL(released()), this, SLOT(addCashDesk()));
    connect(removeCDesk, SIGNAL(released()), this, SLOT(removeCashDesk()));
}


void cashWidget::addClient()
{
    int max_client = getMaxClientNum();
    int cash_number = desksBoxes.size();
    if (cash_number == 0){
        QMessageBox::warning(0, "Accounts department","There are no cash desks.");
        return;
    }
    if (probMode == 0){
        int openedCashDesk;
        for (int k = 0; k < cash_number; k++){
            if (desksBoxes.value(k)->getOpenStatus()){
                openedCashDesk = k + 1;
                break;
            }
            if (k == cash_number - 1){
                QMessageBox::warning(0, "Accounts department","All cash desks are closed");
                return;
            }
        }
        int cashNum = rand() % cash_number + 1;
        if (! desksBoxes.value(cashNum - 1)->getOpenStatus()){
            addClienttoCDesk(openedCashDesk, max_client + 1);
        }else{
            addClienttoCDesk(cashNum, max_client + 1);
        }
    }else if (probMode == 1){
        int deskClientNum[cash_number], clientNum = 0;
        for (int i = 0; i < cash_number; i++){
            deskClientNum[i] = desksBoxes.value(i)->getDesksNum();
            clientNum += deskClientNum[i];
        }
        if (clientNum != 0){
            if(cash_number == 1){
                if (desksBoxes.value(0)->getOpenStatus()){
                    addClienttoCDesk(1, max_client + 1);
                }else{
                    QMessageBox::warning(0, "Accounts department","All cash desks are closed");
                }
                return;
            }
            float prob[cash_number], max_prob = 0;
            int maxPrCashDesk = 0;
            for (int k = 0; k < cash_number; k++){
                prob[k] = (1.0 - (float(deskClientNum[k]) /float(clientNum)) ) / float(cash_number - 1);
                if ((prob[k] > max_prob) && (desksBoxes.value(k)->getOpenStatus())){
                    max_prob = prob[k];
                    maxPrCashDesk = k + 1;
                }
                float randPerc = float(rand() % 100 + 1) / 100.0;
                if ((randPerc < prob[k]) && (desksBoxes.value(k)->getOpenStatus())){
                    addClienttoCDesk(k + 1, max_client + 1);
                    return;
                }
            }
            if (maxPrCashDesk != 0){
                addClienttoCDesk(maxPrCashDesk, max_client + 1);
            }else{
                QMessageBox::warning(0, "Accounts department","All cash desks are closed");
            }
        }else{
            bool flag = false;
            for (int i = 0; i < cash_number; i++){
                if (desksBoxes.value(i)->getOpenStatus()){
                    addClienttoCDesk(i+1, 1);
                    flag = true;
                }
            }
            if (! flag){
                QMessageBox::warning(0, "Accounts department","All cash desks are closed");
            }
        }
    }
}



bool cashWidget::setProbMode(int mode){
    if ((mode >=0) && (mode <= 1)){
        probMode = mode;
        return true;
    }
    return false;
}



int cashWidget::getMaxClientNum(){
    int cash_number = desksBoxes.size();
    int maxCl = 0;
    for (int i = 0; i < cash_number; i++){
        int newMax = desksBoxes.value(i) -> getMaxClient();
        if (newMax > maxCl)
        {
            maxCl = newMax;
        }
    }
    return maxCl;
}


void cashWidget::getOutOfTheQueue(int client){
    int cash_number = desksBoxes.size();
    for (int i = 0; i < cash_number; i++){
        if (desksBoxes.value(i) -> isClient(client)){
            desksBoxes.value(i) ->deleteClient(client);
            return;
        }
    }
    QMessageBox::warning(0, "Accounts department","No such client");
}


void cashWidget::addCashDesk()
{
    int cash_number = desksBoxes.size();
    cashDeskHBox* newDeskBox =  new cashDeskHBox(this, cash_number + 1);
    desksBoxes.append(newDeskBox);
    cashL -> addLayout(newDeskBox);
}


bool cashWidget::deleteCashDesk()
{
    int cash_number = desksBoxes.size();
    if (cash_number == 0){
        return false;
    }
    cashL->removeItem(desksBoxes.value(cash_number - 1));
    delete desksBoxes.value(cash_number - 1);
    desksBoxes.removeLast();
    return true;
}


void cashWidget::removeCashDesk()
{
    int cash_number = desksBoxes.size();
    if (cash_number != 0){
        cashDeskHBox* desk_box = desksBoxes.value(cash_number - 1);
        if (desk_box->getDesksNum() == 0){
            cashL->removeItem(desk_box);
            delete desk_box;
            desksBoxes.removeLast();
        }else{
            QMessageBox * quest = new QMessageBox(QMessageBox::Question, "Accounts department",
                                                  "Do you want to remove cash desk with clients from application",
                                                  QMessageBox::Yes | QMessageBox::No,
                                                  0);
            int n = quest->exec();
            if (n == QMessageBox::Yes){
                cashL->removeItem(desk_box);
                delete desk_box;
                desksBoxes.removeLast();
            }
            delete quest;
        }
    }else{
        QMessageBox::warning(0, "Accounts department","There are no cash desks");
    }
}


bool cashWidget::addClienttoCDesk(int cashD, int client){
    int cash_number = desksBoxes.size();
    if (cashD > cash_number){
        return false;
    }
    for (int i = 0; i < cash_number; i++){
        if (desksBoxes.value(i) -> isClient(client)){
            return false;
        }
    }
    desksBoxes.value(cashD - 1)->addClient(client);
    return true;
}


bool cashWidget::deleteClient(int client){
    int cash_number = desksBoxes.size();
    for (int i = 0; i < cash_number; i++){
        if (desksBoxes.value(i) -> isClient(client)){
            desksBoxes.value(i) -> deleteClient(client);
            return true;
        }
    }
    return false;
}


void cashWidget::openCashDesk(int cashD){
    int cash_number = desksBoxes.size();
    if ((cashD > cash_number) || (cashD <= 0)){
        QMessageBox::warning(0, "Accounts department","No such cash desk");
        return;
    }
    cashDeskHBox * curDesk = desksBoxes.value(cashD - 1);
    curDesk->openDesk();
}


void cashWidget::closeCashDesk(int cashD){
    int cash_number = desksBoxes.size();
    if ((cashD > cash_number) || (cashD <= 0)){
        QMessageBox::warning(0, "Accounts department","No such cash desk");
        return;
    }
    cashDeskHBox * curDesk = desksBoxes.value(cashD - 1);
    curDesk->closeDesk();
}




cashWidget::~cashWidget(){
    //close();
    delete cashL;
    delete addCDesk;
    delete removeCDesk;
    int cash_num = deskBoxes.size();
    for (int i = 0; i < cash_num; i++){
        delete desksBoxes.value(i);
    }
    deskBoxes.clear();
}
