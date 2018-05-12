#include "AdminEditHarbour.h"
#include "ui_AdminEditHarbour.h"
#include "AdminGeo.h"
#include "AdminPanel.h"

AdminEditHarbour::AdminEditHarbour(AdminPanel *parent) :
    QDialog(parent),
    ui(new Ui::AdminEditHarbour)
{
    ui->setupUi(this);
}

AdminEditHarbour::~AdminEditHarbour()
{
    delete ui;
}

void AdminEditHarbour::receiveGeoLocation(QString value, double latitude, double longitude){
    ui->labelShowGeoName->setText(value);
    ui->labelShowGeo->setText(QString("Szerokość: %1 Długość: %2").arg(latitude).arg(longitude));
    tempPort.location.geoLatitude = latitude;
    tempPort.location.geoLongitude = longitude;
}

void AdminEditHarbour::receiveGeoLocationName(QString value){
    tempPort.name = value;
}

void AdminEditHarbour::receiveDataToEdit(Port somePortData){
    tempPort = somePortData;
    ui->labelShowGeoName->setText(tempPort.name);
    ui->labelShowGeo->setText(QString("Szerokość: %1 Długość: %2").arg(tempPort.location.geoLatitude).arg(tempPort.location.geoLongitude));
    ui->lineEditOwner->setText(tempPort.owner);
    ui->lineEditWarehouse->setText(QString("%1").arg(tempPort.warehouseCapacity));

}

void AdminEditHarbour::on_pushGeo_clicked()
{
    AdminGeo adminGeo;
    adminGeo.setModal(true);
    adminGeo.exec();
}

void AdminEditHarbour::on_pushSave_clicked()
{
    tempPort.toString();
}
