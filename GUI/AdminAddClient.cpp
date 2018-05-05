#include "GUI/AdminAddClient.h"
#include "ui_AdminAddClient.h"
#include "GUI/AdminCorporation.h"

AdminAddClient::AdminAddClient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminAddClient)
{
    ui->setupUi(this);
}

AdminAddClient::~AdminAddClient()
{
    delete ui;
}

void AdminAddClient::on_pushButtonCorporation_clicked()
{
    AdminCorporation adminCorporation;
    adminCorporation.setModal(true);
    adminCorporation.exec();
}
