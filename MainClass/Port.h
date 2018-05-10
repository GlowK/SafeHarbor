#ifndef PORT_H
#define PORT_H
#include <QString>
#include "GeoCoordinate.h"
#include "Anchorage.h"
#include "TransportCorridor.h"
#include "Dock.h"

class Port
{
public:
    QString name;
    QString owner; // ToDo - User Class in future :)
    GeoCoordinate location;
    int numberOfTugboats;

    int pAnchorage; // ToDo - Real pointers to AnchorageClass object... CorridorClass object... DockClass object
    Anchorage anchorage;

    int pCorridor;
    int numberOfCorridors;
    TransportCorridor transportCorridor;

    int pDock;
    int numberOfDocks;
    Dock dock;

    int warehouseCapacity;

public:
    Port(QString name, QString owner, GeoCoordinate location);
    Port();
    void setName(const QString &value);
    void setOwner(const QString &value);
    void setNumberOfTugboats(int value);
    void toString();
};

#endif // PORT_H
