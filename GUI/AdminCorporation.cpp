#include "GUI/AdminCorporation.h"
#include "ui_AdminCorporation.h"

AdminCorporation::AdminCorporation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminCorporation)
{
    ui->setupUi(this);
}

AdminCorporation::~AdminCorporation()
{
    delete ui;
}
