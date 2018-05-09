#include "AdminPanel.h"
#include "ui_AdminPanel.h"
#include "AdminAddHarbour.h"
#include "AdminEditHarbour.h"
#include "AdminAddClient.h"
#include "AdminEditClient.h"
#include "AdminAddManager.h"
#include "AdminEditManager.h"
#include "AuxClass/SQLConnect.h"
#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDebug>


AdminPanel::AdminPanel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminPanel)
{
    ui->setupUi(this);
    populateComboBox();
    this->chosenPort = "temp";
}

AdminPanel::~AdminPanel()
{
    delete ui;
}

void AdminPanel::populateComboBox(){
    SQLConnect::ConnectToDB();
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT Name FROM SafeHarbour.Port ORDER BY Name ASC;");
    ui->comboBox->setModel(model);
    SQLConnect::DisconnectDB();
}

void AdminPanel::populatePortInformation(QString nameOfChosenPort){
    SQLConnect::ConnectToDB();

    /*
     * ToDo - Refaktoring i rozbicie tego cholerstwa na kilka mniejsyzch funkcji
     * */
    QSqlQuery query;
    query.prepare("SELECT * FROM SafeHarbour.Port WHERE name = (:nameOfChosenPort)");
    query.bindValue(":nameOfChosenPort", nameOfChosenPort);
    query.exec();
    query.first();
    tempPort.name = query.value(1).toString();
    tempPort.location.geoLatitude = query.value(3).toDouble();
    tempPort.location.geoLongitude = query.value(4).toDouble();
    tempPort.numberOfTugboats = query.value(5).toInt();
    tempPort.pAnchorage = query.value(6).toInt();
    tempPort.corridor = query.value(7).toInt();
    tempPort.dock = query.value(8).toInt();
    tempPort.warehouseCapacity = query.value(9).toInt();

    query.prepare("SELECT Capacity, MaxDraft, CostPerHour FROM SafeHarbour.Anchorage WHERE idAnchorage = (:pAnchorage)");
    query.bindValue(":pAnchorage", tempPort.pAnchorage);
    query.exec();
    query.first();
    tempPort.anchorage.capacity = query.value(0).toInt();
    tempPort.anchorage.maxDraft = query.value(1).toDouble();
    tempPort.anchorage.costPerHour = query.value(2).toDouble();
    tempPort.toString();

    ui->labelShowAnchorageCopacity->setNum(tempPort.anchorage.capacity);
    ui->labelShowTugboatCount->setNum(tempPort.numberOfTugboats);

    populateComboBox();
    SQLConnect::DisconnectDB();
}

void AdminPanel::on_pushCreateNewHarbour_clicked()
{
    AdminAddHarbour adminAddHarbour;
    adminAddHarbour.setModal(true);
    adminAddHarbour.exec();
    populateComboBox();
}

void AdminPanel::on_pushEditHarbour_clicked()
{
    AdminEditHarbour adminEditHarbour;
    adminEditHarbour.setModal(true);
    adminEditHarbour.exec();
}

void AdminPanel::on_pushClientAdd_clicked()
{
    AdminAddClient adminAddClient;
    adminAddClient.setModal(true);
    adminAddClient.exec();
}

void AdminPanel::on_pushClientEdit_clicked()
{
    AdminEditClient adminEditClient;
    adminEditClient.setModal(true);
    adminEditClient.exec();
}

void AdminPanel::on_pushManagerAdd_clicked()
{
    AdminAddManager adminAddManager;
    adminAddManager.setModal(true);
    adminAddManager.exec();
}

void AdminPanel::on_pushManagerEdit_clicked()
{
    AdminEditManager adminEditManager;
    adminEditManager.setModal(true);
    adminEditManager.exec();
}

void AdminPanel::on_pushLogOut_clicked()
{
    this->close();
}

void AdminPanel::on_comboBox_currentIndexChanged(const QString &arg1)
{
    this->chosenPort = arg1;
}

void AdminPanel::on_pushAcceptPort_clicked()
{
    /*
     * ToDo - Dodać wyjatek, zeby pobieral jakas wartosc z comboBoxa nawet gdy sie nie klikalo na comboBox wczesniej
     *          na przyklad pierwsza wartosc z SELECT Name FROM SafeHarbour.Port ORDER BY Name ASC bo to zawsze jest
     *          pierwsza wartosc pokazywana w ComboBoxie jak sie na niego nie klika.
     * */

    /*
     * ToDo:
     * a) Przywolanie obiektu port
     * b) Ustawienie Anchorage
     * c) Ustawienie Corridor
     * d) Ustawienie Dock
     * e) Ustawienie Magazynów
     * */
    ui->labelShowChoosenPort->setText(this->chosenPort);
    populatePortInformation(chosenPort);
}

void AdminPanel::on_pushPlusAnchorage_clicked()
{
    /*
     * ToDo: Upgrade this if statement
     * */
    if(chosenPort != "temp"){
        tempPort.anchorage.capacity++;
        ui->labelShowAnchorageCopacity->setNum(tempPort.anchorage.capacity);
    }
}

void AdminPanel::on_pushMinusAnchorage_clicked()
{
    /*
     * ToDo: Upgrade this if statement
     * */
    if(chosenPort != "temp"){
        tempPort.anchorage.capacity--;
        if(tempPort.anchorage.capacity<0){
            tempPort.anchorage.capacity = 0;
        }
        ui->labelShowAnchorageCopacity->setNum(tempPort.anchorage.capacity);
    }
}

void AdminPanel::on_pushPlusTugboat_clicked()
{
    /*
     * ToDo: Upgrade this if statement
     * */
    if(chosenPort != "temp"){
        tempPort.numberOfTugboats++;
        ui->labelShowTugboatCount->setNum(tempPort.numberOfTugboats);
    }
}

void AdminPanel::on_pushMinusTugboat_clicked()
{
    /*
     * ToDo: Upgrade this if statement
     * */
    if(chosenPort != "temp"){
        tempPort.numberOfTugboats--;
        if(tempPort.anchorage.capacity<0){
            tempPort.anchorage.capacity = 0;
        }
        ui->labelShowTugboatCount->setNum(tempPort.numberOfTugboats);
    }
}
