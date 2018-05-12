#include "AdminEditHarbour.h"
#include "ui_AdminEditHarbour.h"
#include "AdminGeoEdit.h"
#include "AdminPanel.h"
#include "AuxClass/SQLConnect.h"
#include <QSqlQuery>

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
    oldPortName = tempPort.name;
    ui->labelShowGeoName->setText(tempPort.name);
    ui->labelShowGeo->setText(QString("Szerokość: %1 Długość: %2").arg(tempPort.location.geoLatitude).arg(tempPort.location.geoLongitude));
    ui->lineEditOwner->setText(tempPort.owner);
    ui->lineEditWarehouse->setText(QString("%1").arg(tempPort.warehouseCapacity));

}

void AdminEditHarbour::on_pushGeo_clicked()
{
    AdminGeoEdit adminGeoEdit(this);
    adminGeoEdit.setModal(true);
    adminGeoEdit.exec();
}

void AdminEditHarbour::on_pushSave_clicked()
{
    editPortOnDatabase(oldPortName);
    this->close();
}

void AdminEditHarbour::updateTempPort(QString owner, int warehouseCap){
    tempPort.owner = owner;
    tempPort.warehouseCapacity = warehouseCap;
}

void AdminEditHarbour::editPortOnDatabase(QString oldPortName){

    updateTempPort(ui->lineEditOwner->text(),ui->lineEditWarehouse->text().toInt());

    SQLConnect::ConnectToDB();
    QSqlQuery queryEditPort;
    queryEditPort.prepare("UPDATE SafeHarbour.Port SET Name = :Name, Owner = :Owner, GeoLatitude = :GeoLatitude, GeoLongitude = :GeoLongitude, warehouseCap = :warehouseCap WHERE Name = :OldName;");
    queryEditPort.bindValue(":OldName", oldPortName);
    queryEditPort.bindValue(":Name", tempPort.name);
    queryEditPort.bindValue(":Owner", tempPort.owner);
    queryEditPort.bindValue(":GeoLatitude", tempPort.location.geoLatitude);
    queryEditPort.bindValue(":GeoLongitude", tempPort.location.geoLongitude);
    queryEditPort.bindValue(":warehouseCap", tempPort.warehouseCapacity);
    queryEditPort.exec();
    SQLConnect::debugQuery(queryEditPort);
    SQLConnect::DisconnectDB();

    connect(this, SIGNAL(sendNewPortName(QString)),this->parent(),SLOT(receiveChosenPort(QString)));
    emit sendNewPortName(tempPort.name);
}

