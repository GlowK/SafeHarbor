#include "GUI/AdminPanel.h"
#include "ui_AdminPanel.h"
#include "GUI/AdminAddHarbour.h"
#include "GUI/AdminEditHarbour.h"
#include "GUI/AdminAddClient.h"
#include "GUI/AdminEditClient.h"
#include "GUI/AdminAddManager.h"
#include "GUI/AdminEditManager.h"

AdminPanel::AdminPanel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminPanel)
{
    ui->setupUi(this);
}

AdminPanel::~AdminPanel()
{
    delete ui;
}

void AdminPanel::on_pushCreateNewHarbour_clicked()
{
    AdminAddHarbour adminAddHarbour;
    adminAddHarbour.setModal(true);
    adminAddHarbour.exec();
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
