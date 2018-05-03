#include "AdminAddHarbour.h"
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
