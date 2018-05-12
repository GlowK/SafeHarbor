#ifndef ADMINCORRIDORDETAILS_H
#define ADMINCORRIDORDETAILS_H

#include <QDialog>
#include "AdminPanel.h"

namespace Ui {
class AdminCorridorDetails;
}

class AdminPanel;

class AdminCorridorDetails : public QDialog
{
    Q_OBJECT
    TransportCorridor tempCorridor;
    int tempNumberOfCorridors;
    int maxShipsOnCorridors;

signals:
    void sendBackCorridorData(TransportCorridor, int);

public slots:
    void receiveCorridorData(TransportCorridor,int);

public:
    explicit AdminCorridorDetails(AdminPanel *parent = 0);
    ~AdminCorridorDetails();

private slots:
    void on_lineEditCapacityPerCorridor_returnPressed();

    void on_lineEditNumberOfCorridors_returnPressed();

    void on_lineEditNumberOfCorridors_editingFinished();

    void on_lineEditCapacityPerCorridor_editingFinished();

    void on_pushButtonTransferDetails_clicked();

private:
    Ui::AdminCorridorDetails *ui;
    void updateMaxShipsOnCorridorsLabel();
    void updateCorridorDetails();
};

#endif // ADMINCORRIDORDETAILS_H
