#include "AdminGeo.h"
#include "ui_AdminGeo.h"
#include "AuxClass/SQLConnect.h"
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>

/*
 * includujemy naszego parent.h
 * */

#include "AdminAddHarbour.h"

/*
 * Qwidget zmieniamy na parent class
 * */

AdminGeo::AdminGeo(AdminAddHarbour *parent) :
    QDialog(parent),
    ui(new Ui::AdminGeo)
{
    ui->setupUi(this);
    QString cityNameTable[NUMBER_OF_CITIES] = {"Shanghai","Singapore", "Boston", "Rotterdam", "Sydney","Houston" };
    checkButtonsVisibilitie(cityNameTable);
}

AdminGeo::~AdminGeo()
{
    delete ui;
}

double * AdminGeo::getGeoCoordinates(QString cityName){
    SQLConnect::ConnectToDB();
    QSqlQuery query;
    query.prepare("SELECT Latitude, Longitude FROM SafeHarbour.GeoCoordinate WHERE name = (?)");
    query.bindValue(0, cityName);
    query.exec();
    query.first();
    static double geoArray[2];
    geoArray[0] = query.value(0).toDouble();
    geoArray[1] = query.value(1).toDouble();
    SQLConnect::DisconnectDB();
    return geoArray;
}

void AdminGeo::connectGeoNameSS(QString cityName){
    connect(this, SIGNAL(sendGeoLocationName(QString)), parent(),SLOT(receiveGeoLocationName(QString)));
    emit sendGeoLocationName(cityName);
}

void AdminGeo::connectGeoSS(QString cityName, double latitude, double longitude){
    /*
     * connect(
     *  obiekt z ktorego cos wysyłamy,
     *  SIGNAL(metoda signal z obiektu),
     *  obiekt na ktorym będziemy odbierac sygnał,
     *  SLOT(metoda slot z docelowego)
     * );
     *
     * emit(metoda sygnal(atrybuty ktore chcemy wysłać));
     *
     *
     * Zeby wszystko zadzialalo wprowadzilem zmiany w:
     * AdminAddHarbour.cpp
     * AdminAddHarbour.h
     * AdminGeo.cpp
     * AdminGeo.h
     *
     * Mozliwe ze this->parent() nie jest potrzebne, pewnie samo parent() wystarczy
     *
     * */
    connect(this, SIGNAL(sendGeoLocation(QString, double, double)),this->parent(), SLOT(receiveGeoLocation(QString,double, double)));
    emit sendGeoLocation(cityName, latitude,longitude);
}

void AdminGeo::on_pushButtonShanghai_clicked()
{
    QString cityName = "Shanghai";
    connectGeoNameSS(cityName);
    double * geoPointer = getGeoCoordinates(cityName);
    cityName = "Szanghaj";
    connectGeoSS(cityName, *geoPointer,*(geoPointer + 1));
    this->close();
}

void AdminGeo::on_pushButtonSingapore_clicked()
{
    QString cityName = "Singapore";
    connectGeoNameSS(cityName);
    double * geoPointer = getGeoCoordinates(cityName);
    cityName = "Singapur"; // Polish Name
    connectGeoSS(cityName, *geoPointer,*(geoPointer + 1));
    this->close();
}

void AdminGeo::on_pushButtonBoston_clicked()
{
    QString cityName = "Boston";
    connectGeoNameSS(cityName);
    double * geoPointer = getGeoCoordinates(cityName);
    cityName = "Boston"; // Polish Name
    connectGeoSS(cityName, *geoPointer,*(geoPointer + 1));
    this->close();
}

void AdminGeo::on_pushButtonRotterdam_clicked()
{
    QString cityName = "Rotterdam";
    connectGeoNameSS(cityName);
    double * geoPointer = getGeoCoordinates(cityName);
    cityName = "Roterdam"; // Polish Name
    connectGeoSS(cityName, *geoPointer,*(geoPointer + 1));
    this->close();
}

void AdminGeo::on_pushButtonSydney_clicked()
{
    QString cityName = "Sydney";
    connectGeoNameSS(cityName);
    double * geoPointer = getGeoCoordinates(cityName);
    cityName = "Sydney"; // Polish Name
    connectGeoSS(cityName, *geoPointer,*(geoPointer + 1));
    this->close();
}

void AdminGeo::on_pushButtonHouston_clicked()
{
    QString cityName = "Houston";
    connectGeoNameSS(cityName);
    double * geoPointer = getGeoCoordinates(cityName);
    cityName = "Houston"; // Polish Name
    connectGeoSS(cityName, *geoPointer,*(geoPointer + 1));
    this->close();
}

int AdminGeo::isCreated(QString cityName){

    /*
     * ToDo:    Ta funkcja generuje błedy:
     *          QSqlQuery::Value not positioned on a valid record
     *          przydałobysię wymyslic jakiś mądrzejszy sposob sprawdznia czy wyświetlić przycisk
     * */

    QSqlQuery query;
    query.prepare("SELECT idPort from Port where Name = (?)");
    query.bindValue(0, cityName);
    query.exec();
    query.first();
    if(query.value(0).toString() == ""){
        return 0;
    }else{
        return 1;
    }
}

void AdminGeo::isButtonVisible(QString cityName, int j){
    if(isCreated(cityName)){
        switch (j) {
        case 0:
            ui->pushButtonShanghai->setVisible(false);
            break;
        case 1:
            ui->pushButtonSingapore->setVisible(false);
            break;
        case 2:
            ui->pushButtonBoston->setVisible(false);
            break;
        case 3:
            ui->pushButtonRotterdam->setVisible(false);
            break;
        case 4:
            ui->pushButtonSydney->setVisible(false);
            break;
        case 5:
            ui->pushButtonHouston->setVisible(false);
            break;
        default:
            break;
        }
    }
}

void AdminGeo::checkButtonsVisibilitie(QString arr[]){
    SQLConnect::ConnectToDB();
    for(int i = 0; i < NUMBER_OF_CITIES; i++){
        isButtonVisible(arr[i], i);
    }
    SQLConnect::DisconnectDB();
}
