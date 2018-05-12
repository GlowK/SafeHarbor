#ifndef ADMINANCHORAGEDETAILS_H
#define ADMINANCHORAGEDETAILS_H

#include <QDialog>
#include "AdminPanel.h"


namespace Ui {
class AdminAnchorageDetails;
}

class AdminPanel;

class AdminAnchorageDetails : public QDialog
{
    Q_OBJECT
    Anchorage tempAnchorage;

public:
    explicit AdminAnchorageDetails(AdminPanel *parent = 0);
    ~AdminAnchorageDetails();

signals:
    void sendBackAnchorageData(Anchorage);

public slots:
    void receiveAnchorageData(Anchorage);

private slots:
    void on_pushButton_clicked();

private:
    Ui::AdminAnchorageDetails *ui;
    void updateAnchorage(int, double, double);
};

#endif // ADMINANCHORAGEDETAILS_H
