#include "AdminGeo.h"
#include "ui_AdminGeo.h"

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


void AdminGeo::on_pushButtonShanghai_clicked()
{
    QString shanghai = "Shanghai";

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


    connect(this, SIGNAL(sendGeoLocation(QString)),this->parent(), SLOT(receiveGeoLocation(QString)));
    emit sendGeoLocation(shanghai);
    this->close();
}
