#ifndef ADMINPANEL_H
#define ADMINPANEL_H

#include <QDialog>
#include <QString>
#include "MainClass/Port.h"

namespace Ui {
class AdminPanel;
}

class AdminPanel : public QDialog
{
    Q_OBJECT

public:
    explicit AdminPanel(QWidget *parent = 0);
    QString chosenPort;
    Port tempPort;
    ~AdminPanel();

signals:
    void sendDataToEdit(Port);
    void sendAnchorageData(Anchorage);
    void sendCorridorData(TransportCorridor, int);

public slots:
    void receiveChosenPort(QString);
    void receiveAnchorageDetails(Anchorage);
    void receiveCorridorDetails(TransportCorridor, int);
    void receiveDeleteSignal();

private slots:
    void on_pushCreateNewHarbour_clicked();

    void on_pushEditHarbour_clicked();

    void on_pushClientAdd_clicked();

    void on_pushClientEdit_clicked();

    void on_pushManagerAdd_clicked();

    void on_pushManagerEdit_clicked();

    void on_pushLogOut_clicked();

    void on_pushAcceptPort_clicked();

    void on_pushPlusAnchorage_clicked();

    void on_pushMinusAnchorage_clicked();

    void on_pushPlusTugboat_clicked();

    void on_pushMinusTugboat_clicked();

    void on_pushPlusCorridor_clicked();

    void on_pushMinusCorridor_clicked();

    void on_pushPlusDock_clicked();

    void on_pushMinusDock_clicked();

    void on_pushEditAnchorage_clicked();

    void on_pushEditCorridor_clicked();

private:
    Ui::AdminPanel *ui;
    void populateComboBox();
    void populatePortInformation(QString);
    void populatePortBaseInf(QString);
    void populatePortAnchorageInf(int);
    void populatePortCorridorInf(int);
    void populatePortDockInf(int);
    void checkIfPortChosen(QString);
    void updatePortShowLabels();
    void updatePortAfterDeletion();


};

#endif // ADMINPANEL_H
