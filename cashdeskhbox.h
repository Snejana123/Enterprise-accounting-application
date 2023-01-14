#ifndef CASHDESKHBOX_H
#define CASHDESKHBOX_H

#include<QHBoxLayout>
#include <QWidget>
#include <QVector>
#include <QLabel>
#include<QFont>


class cashDeskHBox: public QHBoxLayout
{
    int maxClient, desksNum;
    QWidget * parentW;
    int deskNumber;
    QVector<QLabel *> clients;
    bool isOpen;
    QLabel* deskLabel;
    QFont mainFont;
    QVector<QLabel *> clientsLabels;
public:
    cashDeskHBox(QWidget * , int);
    ~cashDeskHBox();
    void addClient(int);
    bool deleteClient(int);
    bool isClient(int);
    void closeDesk();
    void openDesk();
    int getDeskNumber();
    bool getOpenStatus();
    int getMaxClient();
    int getDesksNum();
};

#endif // CASHDESKHBOX_H
