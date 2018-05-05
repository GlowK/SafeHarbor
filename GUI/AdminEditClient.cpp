#include "AdminEditClient.h"
#include "ui_AdminEditClient.h"
#include "AdminCorporation.h"

AdminEditClient::AdminEditClient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminEditClient)
{
    ui->setupUi(this);
}

AdminEditClient::~AdminEditClient()
{
    delete ui;
}

void AdminEditClient::on_pushButtonCorporation_clicked()
{
    AdminCorporation adminCorporation;
    adminCorporation.setModal(true);
    adminCorporation.exec();
}
