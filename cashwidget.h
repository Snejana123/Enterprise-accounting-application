#ifndef CASHWIDGET_H
#define CASHWIDGET_H

#include <QWidget>
#include<QVector>
#include <QPushButton>
#include "cashdeskhbox.h"

class cashWidget : public QWidget
{

    Q_OBJECT

    QVector<cashDeskHBox> deskBoxes;

    QVector<cashDeskHBox *> desksBoxes;
    QVBoxLayout* cashL;
    QWidget * parentW;

    int probMode = 0;

protected:
    QPushButton * addCDesk, * removeCDesk;

public slots:
    void addClient();
    void addCashDesk();
    void removeCashDesk();
    void getOutOfTheQueue(int);
    void openCashDesk(int);
    void closeCashDesk(int);

signals:
    void resizeReq();

public:
    cashWidget(QWidget *);
    ~cashWidget();
    bool deleteCashDesk();
    bool addClienttoCDesk(int, int);
    bool deleteClient(int);
    int getMaxClientNum();
    bool setProbMode(int);



};

#endif // CASHWIDGET_H
