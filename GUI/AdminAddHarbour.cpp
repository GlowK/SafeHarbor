#include "AdminAddHarbour.h"
#include "AdminGeo.h"
#include "ui_AdminAddHarbour.h"
#include "AuxClass/SQLConnect.h"
#include <QSqlQuery>
#include <QMessageBox>



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
    ui->labelShowGeoName->setText(value);
    ui->labelShowGeo->setText(QString("Szerokość: %1 Długość: %2").arg(latitude).arg(longitude));
    tempPort.location.geoLatitude = latitude;
    tempPort.location.geoLongitude = longitude;
}

void AdminAddHarbour::receiveGeoLocationName(QString value){
    tempPort.name = value;
}


void AdminAddHarbour::on_pushGeo_clicked()
{
    AdminGeo adminGeo(this); //dopisujemy (parent) w deklaracji
    adminGeo.setModal(true);
    adminGeo.exec();
}

void AdminAddHarbour::updateTempPort(QString owner, int warehouseCap){
    tempPort.owner = owner;
    tempPort.warehouseCapacity = warehouseCap;
}


void AdminAddHarbour::on_pushSave_clicked()
{
    updateTempPort(ui->lineEditOwner->text(),ui->lineEditWarehouse->text().toInt());

    /* tempPort.toString(); <- można sobie wypluc jakie dane zostana dodane do bazy (poza pointerami bo one nic nie robia)
     * ToDo - koniecznie dodac obsługe niepoprawnych i pustych wartosci
     * ToDo - MessageBox przez automatyczne formatowanie obiektow nie wyglad najlepiej, trzeba podumac jak to ominać
     * */

    addPortToDatabase(tempPort);
    QMessageBox::information(this, "Port stworzony", "Port dodany do bazy");
    this->close();
}

void AdminAddHarbour::addPortToDatabase(Port tempPort){

    SQLConnect::ConnectToDB();
    QSqlQuery query;
    query.prepare("INSERT INTO SafeHarbour.Port (Name, Owner, GeoLatitude, GeoLongitude, NumberOfTugboats, PointerAnchorage, PointerCorridor, PointerDock, warehouseCap) VALUES (:Name, :Owner, :GeoLatitude, :GeoLongitude, :NumberOfTugboats, :PointerAnchorage, :PointerCorridor, :PointerDock, :warehouseCap);");
    query.bindValue(":Name", tempPort.name);
    query.bindValue(":Owner", tempPort.owner);
    query.bindValue(":GeoLatitude", tempPort.location.geoLatitude);
    query.bindValue(":GeoLongitude", tempPort.location.geoLongitude);
    query.bindValue(":NumberOfTugboats", tempPort.numberOfTugboats);
    query.bindValue(":PointerAnchorage", tempPort.anchorage);
    query.bindValue(":PointerCorridor", tempPort.corridor);
    query.bindValue(":PointerDock", tempPort.dock);
    query.bindValue(":warehouseCap", tempPort.warehouseCapacity);
    query.exec();
    query.first();
    SQLConnect::DisconnectDB();
}
