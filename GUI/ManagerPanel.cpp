#include "ManagerPanel.h"
#include "ui_ManagerPanel.h"

ManagerPanel::ManagerPanel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ManagerPanel)
{
    ui->setupUi(this);
}

ManagerPanel::~ManagerPanel()
{
    delete ui;
}

void ManagerPanel::on_pushLogOut_clicked()
{
    this->close();
}
