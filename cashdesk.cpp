#include "cashdesk.h"

cashDesk::cashDesk(int deskNum)
{
    deskNumber = deskNum;
    prob = 1.0;
    isOpen = true;
}

void cashDesk::addClient(int new_client)
{
    int size = clients.size();
    for (int i = 0; i < size; i++){
        if (clients.value(i) == new_client){
            return;
        }
    }
    clients.append(new_client);
}

bool cashDesk::deleteClient(int client_num){
    int size = clients.size();
    for (int i = 0; i < size; i++){
        if (clients.value(i) == client_num){
            clients.removeAt(i);
            return true;
        }
    }
    return false;
}

void cashDesk::closeDesk(){
    isOpen = false;
}

void cashDesk::openDesk(){
    isOpen = true;
}

void cashDesk::setProb(float new_prob){
    prob = new_prob;
}

float cashDesk::getProb(){
    return prob;
}


bool cashDesk::isCLient(int clientN) {
    return clients.contains(clientN);
}
