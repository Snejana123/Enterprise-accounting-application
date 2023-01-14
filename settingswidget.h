#ifndef SETTINGSWIDGET_H
#define SETTINGSWIDGET_H

#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QMenu>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QMenu>

class settingsWidget : public QWidget
{
    Q_OBJECT

    QLabel * probModeLab, * themeLab;
    QPushButton * probBut, * themeBut;

    QMenu * probModeMenu, *themeMenu ;
    QAction * equalMode, * queueLengthMode, * perfectWhiteTheme, * lemonGateTheme, * fruitBlendTheme, * plumPlateTheme;

    QHBoxLayout * probModeLayout, * themeLayout;
    QVBoxLayout * settLay;
public:
    settingsWidget(QWidget *);
    ~settingsWidget();
signals:
    void modeSig(int mode);
    void perfectWhiteSig();
    void lemonGateSig();
    void fruitBlendSig();
    void plumPlateSig();
    void equalModeSig();
    void queueLengthModeSig();


};

#endif // SETTINGSWIDGET_H
