#ifndef DOCK_H
#define DOCK_H


class Dock
{
public:
    Dock();
public:
    double maxDraft;
    int containerPerHour;
    int passengersPerHour;
    double costPerHour;
    int capacity;
};

#endif // DOCK_H
