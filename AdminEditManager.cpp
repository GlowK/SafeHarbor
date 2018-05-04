#include "AdminEditManager.h"
#include "ui_AdminEditManager.h"

AdminEditManager::AdminEditManager(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminEditManager)
{
    ui->setupUi(this);
}

AdminEditManager::~AdminEditManager()
{
    delete ui;
}
