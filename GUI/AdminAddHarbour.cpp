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

    QSqlQuery queryAddAnchorage;
    queryAddAnchorage.prepare("INSERT INTO SafeHarbour.Anchorage (Capacity, MaxDraft, CostPerHour) VALUES (:Capacity, :MaxDraft, :CostPerHour);");
    queryAddAnchorage.bindValue(":Capacity", 0);
    queryAddAnchorage.bindValue(":MaxDraft", 0);
    queryAddAnchorage.bindValue(":CostPerHour", 0);
    queryAddAnchorage.exec();
    queryAddAnchorage.first();

    // Logika - Jak tworze Kotwicowisko, to ID bedzie najwieksze, i to najwieksze ID przypne za moment do nowo stworzonego Portu

    queryAddAnchorage.prepare("SELECT max(idAnchorage) from Anchorage");
    queryAddAnchorage.exec();
    queryAddAnchorage.first();
    tempPort.pAnchorage = queryAddAnchorage.value(0).toInt();

    queryAddAnchorage.prepare("INSERT INTO SafeHarbour.Port (Name, Owner, GeoLatitude, GeoLongitude, NumberOfTugboats, PointerAnchorage, PointerCorridor, PointerDock, warehouseCap) VALUES (:Name, :Owner, :GeoLatitude, :GeoLongitude, :NumberOfTugboats, :PointerAnchorage, :PointerCorridor, :PointerDock, :warehouseCap);");
    queryAddAnchorage.bindValue(":Name", tempPort.name);
    queryAddAnchorage.bindValue(":Owner", tempPort.owner);
    queryAddAnchorage.bindValue(":GeoLatitude", tempPort.location.geoLatitude);
    queryAddAnchorage.bindValue(":GeoLongitude", tempPort.location.geoLongitude);
    queryAddAnchorage.bindValue(":NumberOfTugboats", tempPort.numberOfTugboats);
    queryAddAnchorage.bindValue(":PointerAnchorage", tempPort.pAnchorage);
    queryAddAnchorage.bindValue(":PointerCorridor", tempPort.corridor);
    queryAddAnchorage.bindValue(":PointerDock", tempPort.dock);
    queryAddAnchorage.bindValue(":warehouseCap", tempPort.warehouseCapacity);
    queryAddAnchorage.exec();
    queryAddAnchorage.first();
    SQLConnect::DisconnectDB();
}
