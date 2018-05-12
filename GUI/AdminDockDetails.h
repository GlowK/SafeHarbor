#ifndef ADMINDOCKDETAILS_H
#define ADMINDOCKDETAILS_H

#include <QDialog>
#include "AdminPanel.h"

namespace Ui {
class AdminDockDetails;
}

class AdminPanel;

class AdminDockDetails : public QDialog
{
    Q_OBJECT
    Dock tempDock;
    int tempNumberOfDocks;
    int maxShipsInDocks;

signals:
    void sendBackDockDetails(Dock, int);

public slots:
    void receiveDockData(Dock,int);

public:
    explicit AdminDockDetails(AdminPanel *parent = 0);
    ~AdminDockDetails();

private slots:
    void on_lineEditNumberOfDocks_returnPressed();

    void on_lineEditNumberOfDocks_editingFinished();

    void on_lineEditDockCapacity_returnPressed();

    void on_lineEditDockCapacity_editingFinished();

    void on_pushButtonTransferDetails_clicked();

private:
    Ui::AdminDockDetails *ui;
    void updateMaxShipsInDocksLabel();
    void updateDockDetails();

};

#endif // ADMINDOCKDETAILS_H
