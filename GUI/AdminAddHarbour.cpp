#include "AdminAddHarbour.h"
#include "AdminGeo.h"
#include "ui_AdminAddHarbour.h"


AdminAddHarbour::AdminAddHarbour(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminAddHarbour)
{
    ui->setupUi(this);
}

AdminAddHarbour::~AdminAddHarbour()
{
    delete ui;
}

    /*
     * Opisujemy co robi nasz RECEIVER
     * */

void AdminAddHarbour::receiveGeoLocation(QString value, double latitude, double longitude){
    ui->labelShowGeo->setText(value);
    tempPort.location.geoLatitude = latitude;
    tempPort.location.geoLongitude = longitude;
}


void AdminAddHarbour::on_pushGeo_clicked()
{
    AdminGeo adminGeo(this); //dopisujemy (parent) w deklaracji
    adminGeo.setModal(true);
    adminGeo.exec();
}



