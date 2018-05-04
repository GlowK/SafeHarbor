#include "AdminGeo.h"
#include "ui_AdminGeo.h"

AdminGeo::AdminGeo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminGeo)
{
    ui->setupUi(this);
}

AdminGeo::~AdminGeo()
{
    delete ui;
}
