#include "AdminGeo.h"
#include "ui_AdminGeo.h"
#include "AuxClass/SQLConnect.h"
#include <QSqlQuery>
#include <QDebug>

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

void AdminGeo::on_pushButtonShanghai_clicked()
{
    QString cityName = "Shanghai";
    double * geoPointer = getGeoCoordinates(cityName);
    cityName = "Szanghaj";

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
    emit sendGeoLocation(cityName, *geoPointer,*(geoPointer + 1));
    this->close();
}

void AdminGeo::on_pushButtonSingapore_clicked()
{
    QString cityName = "Singapore";
    double * geoPointer = getGeoCoordinates(cityName);
    cityName = "Singapur"; // Polish Name
    connect(this, SIGNAL(sendGeoLocation(QString, double, double)),this->parent(), SLOT(receiveGeoLocation(QString,double, double)));
    emit sendGeoLocation(cityName, *geoPointer,*(geoPointer + 1));
    this->close();
}

void AdminGeo::on_pushButtonBoston_clicked()
{
    QString cityName = "Boston";
    double * geoPointer = getGeoCoordinates(cityName);
    cityName = "Boston"; // Polish Name
    connect(this, SIGNAL(sendGeoLocation(QString, double, double)),this->parent(), SLOT(receiveGeoLocation(QString,double, double)));
    emit sendGeoLocation(cityName, *geoPointer,*(geoPointer + 1));
    this->close();
}

void AdminGeo::on_pushButtonRotterdam_clicked()
{
    QString cityName = "Rotterdam";
    double * geoPointer = getGeoCoordinates(cityName);
    cityName = "Roterdam"; // Polish Name
    connect(this, SIGNAL(sendGeoLocation(QString, double, double)),this->parent(), SLOT(receiveGeoLocation(QString,double, double)));
    emit sendGeoLocation(cityName, *geoPointer,*(geoPointer + 1));
    this->close();
}

void AdminGeo::on_pushButtonSydney_clicked()
{
    QString cityName = "Sydney";
    double * geoPointer = getGeoCoordinates(cityName);
    cityName = "Sydney"; // Polish Name
    connect(this, SIGNAL(sendGeoLocation(QString, double, double)),this->parent(), SLOT(receiveGeoLocation(QString,double, double)));
    emit sendGeoLocation(cityName, *geoPointer,*(geoPointer + 1));
    this->close();
}

void AdminGeo::on_pushButtonHouston_clicked()
{
    QString cityName = "Houston";
    double * geoPointer = getGeoCoordinates(cityName);
    cityName = "Houston"; // Polish Name
    connect(this, SIGNAL(sendGeoLocation(QString, double, double)),this->parent(), SLOT(receiveGeoLocation(QString,double, double)));
    emit sendGeoLocation(cityName, *geoPointer,*(geoPointer + 1));
    this->close();
}

