#ifndef PORT_H
#define PORT_H
#include <QString>
#include "GeoCoordinate.h"


class Port
{
public:
    QString name;
    QString owner; // ToDo - User Class in future :)
    GeoCoordinate location;
    int numberOfTugboats;
    int anchorage; // ToDo - Real pointers to AnchorageClass object... CorridorClass object... DockClass object
    int corridor;
    int dock;

    Port(QString name, QString owner, GeoCoordinate location);
};

#endif // PORT_H
