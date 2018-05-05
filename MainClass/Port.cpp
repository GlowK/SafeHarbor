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
