#ifndef TRANSPORTCORRIDOR_H
#define TRANSPORTCORRIDOR_H


class TransportCorridor
{
public:
    TransportCorridor();
public:
    int maxSpeed;
    double maxWidth;
    double maxDraft;
    double costPerHour;
    int capacityPerCorridor;
};

#endif // TRANSPORTCORRIDOR_H
