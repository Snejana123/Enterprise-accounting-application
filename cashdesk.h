#ifndef CASHDESK_H
#define CASHDESK_H

#include <QVector>

class cashDesk
{
    int deskNumber;
    QVector<int> clients;
    float prob;
    bool isOpen = true;
public:
    cashDesk(int);
    void addClient(int);
    bool deleteClient(int);
    void closeDesk();
    void openDesk();
    void setProb(float);
    float getProb();
    bool isCLient(int);
};

#endif // CASHDESK_H
