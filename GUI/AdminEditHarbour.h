#ifndef ADMINEDITHARBOUR_H
#define ADMINEDITHARBOUR_H

#include <QDialog>
#include "MainClass/Port.h"

namespace Ui {
class AdminEditHarbour;
}

class AdminPanel;

class AdminEditHarbour : public QDialog
{
    Q_OBJECT

public:
    explicit AdminEditHarbour(AdminPanel *parent = 0);
    ~AdminEditHarbour();
public:
    Port tempPort;

public slots:
    void receiveGeoLocation(QString, double, double);
    void receiveGeoLocationName(QString);
    void receiveDataToEdit(Port);

private slots:
    void on_pushGeo_clicked();

    void on_pushSave_clicked();

private:
    Ui::AdminEditHarbour *ui;
};

#endif // ADMINEDITHARBOUR_H
