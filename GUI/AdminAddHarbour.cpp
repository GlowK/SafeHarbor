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

void AdminAddHarbour::on_pushGeo_clicked()
{
    AdminGeo adminGeo;
    adminGeo.setModal(true);
    adminGeo.exec();
}
