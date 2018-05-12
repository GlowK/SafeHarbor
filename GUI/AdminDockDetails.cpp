#include "AdminDockDetails.h"
#include "ui_AdminDockDetails.h"

AdminDockDetails::AdminDockDetails(AdminPanel *parent) :
    QDialog(parent),
    ui(new Ui::AdminDockDetails)
{
    ui->setupUi(this);
}

AdminDockDetails::~AdminDockDetails()
{
    delete ui;
}

void AdminDockDetails::receiveDockData(Dock receivedDock, int receivedNumberOfDocks){
    tempNumberOfDocks = receivedNumberOfDocks;
    tempDock = receivedDock;
    maxShipsInDocks = tempNumberOfDocks * tempDock.capacity;
    ui->lineEditNumberOfDocks->setText(QString("%1").arg(tempNumberOfDocks));
    ui->lineEditDockCapacity->setText(QString("%1").arg(tempDock.capacity));
    ui->lineEditMaxDraft->setText(QString("%1").arg(tempDock.maxDraft));
    ui->lineEditContainersPerHour->setText(QString("%1").arg(tempDock.containerPerHour));
    ui->lineEditPassengersPerHour->setText(QString("%1").arg(tempDock.passengersPerHour));
    ui->lineEditCostPerHour->setText(QString("%1").arg(tempDock.costPerHour));
    ui->labelShowMaxShips->setText(QString("%1").arg(maxShipsInDocks));
}

void AdminDockDetails::updateMaxShipsInDocksLabel(){
    maxShipsInDocks = tempNumberOfDocks * tempDock.capacity;
    ui->labelShowMaxShips->setText(QString("%1").arg(maxShipsInDocks));
}

void AdminDockDetails::on_lineEditNumberOfDocks_returnPressed()
{
    tempNumberOfDocks = ui->lineEditNumberOfDocks->text().toInt();
    updateMaxShipsInDocksLabel();

}

void AdminDockDetails::on_lineEditNumberOfDocks_editingFinished()
{
    tempNumberOfDocks = ui->lineEditNumberOfDocks->text().toInt();
    updateMaxShipsInDocksLabel();
}

void AdminDockDetails::on_lineEditDockCapacity_returnPressed()
{
    tempDock.capacity = ui->lineEditDockCapacity->text().toInt();
    updateMaxShipsInDocksLabel();
}

void AdminDockDetails::on_lineEditDockCapacity_editingFinished()
{
    tempDock.capacity = ui->lineEditDockCapacity->text().toInt();
    updateMaxShipsInDocksLabel();
}

void AdminDockDetails::updateDockDetails(){
    tempNumberOfDocks = ui->lineEditNumberOfDocks->text().toInt();
    tempDock.capacity = ui->lineEditDockCapacity->text().toInt();
    tempDock.maxDraft = ui->lineEditMaxDraft->text().toDouble();
    tempDock.containerPerHour = ui->lineEditContainersPerHour->text().toInt();
    tempDock.passengersPerHour = ui->lineEditPassengersPerHour->text().toInt();
    tempDock.costPerHour = ui->lineEditCostPerHour->text().toDouble();
}



void AdminDockDetails::on_pushButtonTransferDetails_clicked()
{
    updateDockDetails();
    connect(this, SIGNAL(sendBackDockDetails(Dock,int)), this->parent(),SLOT(receiveDockDetails(Dock, int)));
    emit sendBackDockDetails(tempDock,tempNumberOfDocks);
    this->close();
}
