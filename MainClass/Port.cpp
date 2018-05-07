#include "Port.h"

Port::Port(QString name, QString owner, GeoCoordinate location)
{
    this->name = name;
    this->owner = owner;
    this->location = location;
    numberOfTugboats = 0;
    anchorage = 0;
    corridor = 0;
    dock = 0;

}

Port::Port()
{
    name = "temp";
    owner = "temp";
    numberOfTugboats = 0;
    anchorage = 0;
    corridor = 0;
    dock = 0;
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
