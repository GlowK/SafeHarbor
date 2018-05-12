#include "AdminAnchorageDetails.h"
#include "ui_AdminAnchorageDetails.h"

AdminAnchorageDetails::AdminAnchorageDetails(AdminPanel *parent) :
    QDialog(parent),
    ui(new Ui::AdminAnchorageDetails)
{
    ui->setupUi(this);
}

AdminAnchorageDetails::~AdminAnchorageDetails()
{
    delete ui;
}

void AdminAnchorageDetails::receiveAnchorageData(Anchorage receivedAnchorage){
    tempAnchorage = receivedAnchorage;
    ui->lineEditCapacity->setText(QString("%1").arg(tempAnchorage.capacity));
    ui->lineEditMaxDraft->setText(QString("%1").arg(tempAnchorage.maxDraft));
    ui->lineEditCostPerHour->setText(QString("%1").arg(tempAnchorage.costPerHour));
}

void AdminAnchorageDetails::on_pushButton_clicked()
{
    updateAnchorage(ui->lineEditCapacity->text().toInt(),
                    ui->lineEditMaxDraft->text().toDouble(),
                    ui->lineEditCostPerHour->text().toDouble());
    connect(this,SIGNAL(sendBackAnchorageData(Anchorage)), this->parent(), SLOT(receiveAnchorageDetails(Anchorage)));
    emit sendBackAnchorageData(tempAnchorage);
    this->close();
}

void AdminAnchorageDetails::updateAnchorage(int capacity, double draft, double cost){
    tempAnchorage.capacity = capacity;
    tempAnchorage.maxDraft = draft;
    tempAnchorage.costPerHour = cost;
}
