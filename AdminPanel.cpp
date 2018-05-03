#include "AdminPanel.h"
#include "ui_AdminPanel.h"
#include "AdminAddHarbour.h"

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
