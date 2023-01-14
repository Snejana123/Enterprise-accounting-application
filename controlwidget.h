#ifndef CONTROLWIDGET_H
#define CONTROLWIDGET_H

#include <QWidget>

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

class controlWidget: public QWidget
{

    Q_OBJECT

    QVBoxLayout * mainVLayout;
    QHBoxLayout * getOutLayout, * openHLayout, *closeHLayout;
    QPushButton * takeBut, * getOutBut, * openDeskB, * closeDeskB;
    QLabel * clientLab, *openLab, *closeLab;
    QLineEdit * clientNEdit, *openDEdit, *closeDEdit;

    void moveEvent(QMoveEvent *);

    public:
        controlWidget(QWidget *);
        ~controlWidget();

    signals:
        void takeTheQueue();
        void getOutSig(int);
        void openDeskS(int);
        void closeDeskS(int);
        void moveSig();

    public slots:
        void getOutSlot();
        void closeDeskSlot();
        void openDeskSlot();

};

#endif // CONTROLWIDGET_H
