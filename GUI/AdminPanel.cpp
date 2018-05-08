#include "AdminPanel.h"
#include "ui_AdminPanel.h"
#include "AdminAddHarbour.h"
#include "AdminEditHarbour.h"
#include "AdminAddClient.h"
#include "AdminEditClient.h"
#include "AdminAddManager.h"
#include "AdminEditManager.h"
#include "AuxClass/SQLConnect.h"
#include <QString>
#include <QSqlDatabase>
#include <QSqlQueryModel>


AdminPanel::AdminPanel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminPanel)
{
    ui->setupUi(this);
    populateComboBox();
}

AdminPanel::~AdminPanel()
{
    delete ui;
}

void AdminPanel::populateComboBox(){
    SQLConnect::ConnectToDB();
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT Name FROM SafeHarbour.Port ORDER BY Name ASC;");
    ui->comboBox->setModel(model);
}

void AdminPanel::on_pushCreateNewHarbour_clicked()
{
    AdminAddHarbour adminAddHarbour;
    adminAddHarbour.setModal(true);
    adminAddHarbour.exec();
    populateComboBox();
}

void AdminPanel::on_pushEditHarbour_clicked()
{
    AdminEditHarbour adminEditHarbour;
    adminEditHarbour.setModal(true);
    adminEditHarbour.exec();
}

void AdminPanel::on_pushClientAdd_clicked()
{
    AdminAddClient adminAddClient;
    adminAddClient.setModal(true);
    adminAddClient.exec();
}

void AdminPanel::on_pushClientEdit_clicked()
{
    AdminEditClient adminEditClient;
    adminEditClient.setModal(true);
    adminEditClient.exec();
}

void AdminPanel::on_pushManagerAdd_clicked()
{
    AdminAddManager adminAddManager;
    adminAddManager.setModal(true);
    adminAddManager.exec();
}

void AdminPanel::on_pushManagerEdit_clicked()
{
    AdminEditManager adminEditManager;
    adminEditManager.setModal(true);
    adminEditManager.exec();
}

void AdminPanel::on_pushLogOut_clicked()
{
    this->close();
}
