#include "AdminCorridorDetails.h"
#include "ui_AdminCorridorDetails.h"

AdminCorridorDetails::AdminCorridorDetails(AdminPanel *parent) :
    QDialog(parent),
    ui(new Ui::AdminCorridorDetails)
{
    ui->setupUi(this);
}

AdminCorridorDetails::~AdminCorridorDetails()
{
    delete ui;
}

void AdminCorridorDetails::receiveCorridorData(TransportCorridor receivedCorridor, int receivedNumerOfCorridors){
    tempNumberOfCorridors = receivedNumerOfCorridors;
    tempCorridor = receivedCorridor;
    maxShipsOnCorridors = tempNumberOfCorridors * tempCorridor.capacityPerCorridor;
    ui->lineEditNumberOfCorridors->setText(QString("%1").arg(tempNumberOfCorridors));
    ui->lineEditMaxSpeed->setText(QString("%1").arg(tempCorridor.maxSpeed));
    ui->lineEditMaxWidth->setText(QString("%1").arg(tempCorridor.maxWidth));
    ui->lineEditMaxDraft->setText(QString("%1").arg(tempCorridor.maxDraft));
    ui->lineEditCostPerHour->setText(QString("%1").arg(tempCorridor.costPerHour));
    ui->lineEditCapacityPerCorridor->setText(QString("%1").arg(tempCorridor.capacityPerCorridor));
    ui->labelShowMaxShips->setText(QString("%1").arg(maxShipsOnCorridors));
}

void AdminCorridorDetails::updateMaxShipsOnCorridorsLabel(){
    maxShipsOnCorridors = tempNumberOfCorridors * tempCorridor.capacityPerCorridor;
    ui->labelShowMaxShips->setText(QString("%1").arg(maxShipsOnCorridors));
}

void AdminCorridorDetails::on_lineEditCapacityPerCorridor_returnPressed()
{
    tempCorridor.capacityPerCorridor = ui->lineEditCapacityPerCorridor->text().toInt();
    updateMaxShipsOnCorridorsLabel();
}

void AdminCorridorDetails::on_lineEditNumberOfCorridors_returnPressed()
{
    tempNumberOfCorridors = ui->lineEditNumberOfCorridors->text().toInt();
    updateMaxShipsOnCorridorsLabel();

}

void AdminCorridorDetails::on_lineEditNumberOfCorridors_editingFinished()
{
    tempNumberOfCorridors = ui->lineEditNumberOfCorridors->text().toInt();
    updateMaxShipsOnCorridorsLabel();
}

void AdminCorridorDetails::on_lineEditCapacityPerCorridor_editingFinished()
{
    tempCorridor.capacityPerCorridor = ui->lineEditCapacityPerCorridor->text().toInt();
    updateMaxShipsOnCorridorsLabel();
}

void AdminCorridorDetails::updateCorridorDetails(){
    tempNumberOfCorridors = ui->lineEditNumberOfCorridors->text().toInt();
    tempCorridor.maxSpeed = ui->lineEditMaxSpeed->text().toInt();
    tempCorridor.maxDraft = ui->lineEditMaxDraft->text().toDouble();
    tempCorridor.maxWidth = ui->lineEditMaxWidth->text().toDouble();
    tempCorridor.costPerHour = ui->lineEditCostPerHour->text().toDouble();
    tempCorridor.capacityPerCorridor = ui->lineEditCapacityPerCorridor->text().toInt();
}

void AdminCorridorDetails::on_pushButtonTransferDetails_clicked()
{
    updateCorridorDetails();
    connect(this,SIGNAL(sendBackCorridorData(TransportCorridor,int)),this->parent(),SLOT(receiveCorridorDetails(TransportCorridor, int)));
    emit sendBackCorridorData(tempCorridor, tempNumberOfCorridors);
    this->close();
}
