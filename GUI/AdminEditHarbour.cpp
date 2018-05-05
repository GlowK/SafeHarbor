#include "GUI/AdminEditHarbour.h"
#include "ui_AdminEditHarbour.h"
#include "GUI/AdminGeo.h"

AdminEditHarbour::AdminEditHarbour(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminEditHarbour)
{
    ui->setupUi(this);
}

AdminEditHarbour::~AdminEditHarbour()
{
    delete ui;
}

void AdminEditHarbour::on_pushGeo_clicked()
{
    AdminGeo adminGeo;
    adminGeo.setModal(true);
    adminGeo.exec();
}
