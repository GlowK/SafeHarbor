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

void AdminAddHarbour::receiveGeoLocation(QString value){
    ui->labelShowGeo->setText(value);
}


void AdminAddHarbour::on_pushGeo_clicked()
{
    AdminGeo adminGeo(this); //dopisujemy (parent) w deklaracji
    adminGeo.setModal(true);
    adminGeo.exec();
}

