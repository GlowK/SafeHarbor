#include "Port.h"
#include "QDebug"

Port::Port(QString name, QString owner, GeoCoordinate location)
{
    this->name = name;
    this->owner = owner;
    this->location = location;
    numberOfTugboats = 0;
    pAnchorage = 0;
    pCorridor = 0;
    dock = 0;
    warehouseCapacity = 0;

}

Port::Port()
{
    name = "temp";
    owner = "temp";
    numberOfTugboats = 0;
    numberOfCorridors = 0;
    pAnchorage = 0;
    pCorridor = 0;
    dock = 0;
    warehouseCapacity = 0;

}

void Port::setName(const QString &value)
{
    name = value;
}

void Port::setOwner(const QString &value)
{
    owner = value;
}

void Port::setNumberOfTugboats(int value)
{
    numberOfTugboats = value;
}

void Port::toString(){
    qDebug() << "name = " << this->name;
    qDebug() << "owner = " << this->owner;
    qDebug() << "latitude = " << this->location.geoLatitude;
    qDebug() << "longitude = " << this->location.geoLongitude;
    qDebug() << "numberOfTugboats = " << this->numberOfTugboats;
    qDebug() << "anchorageCapacity = " << this->anchorage.capacity;
    qDebug() << "anchorageMaxDraft = " << this->anchorage.maxDraft;
    qDebug() << "warehouseCostPerHour = " << this->anchorage.capacity;
    qDebug() << "Coridor MaxSpeed = " << this->transportCorridor.maxSpeed;
    qDebug() << "Coridor MaxWidth = " << this->transportCorridor.maxWidth;
    qDebug() << "Coridor MaxDraft = " << this->transportCorridor.maxDraft;
    qDebug() << "Coridor CostPerHour = " << this->transportCorridor.costPerHour;
    qDebug() << "Coridor CapPerCorridor = " << this->transportCorridor.capacityPerCorridor;


}
