#include "GUI/AdminAddManager.h"
#include "ui_AdminAddManager.h"

AdminAddManager::AdminAddManager(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminAddManager)
{
    ui->setupUi(this);
}

AdminAddManager::~AdminAddManager()
{
    delete ui;
}
