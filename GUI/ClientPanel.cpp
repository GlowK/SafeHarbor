#include "ClientPanel.h"
#include "ui_ClientPanel.h"

ClientPanel::ClientPanel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ClientPanel)
{
    ui->setupUi(this);
}

ClientPanel::~ClientPanel()
{
    delete ui;
}

void ClientPanel::on_pushLogOut_clicked()
{
    this->close();
}
