#ifndef REPORTMANAGER_H
#define REPORTMANAGER_H

#include "Reservationlist.h"
#include "WaitingQueue.h"
#include "ResourceManager.h"

class ReportManager {
private:
    ReservationList& reservations;
    WaitingQueue& waitingQueue;
    ResourceManager& resourceManager;

public:
    ReportManager(ReservationList& reservations, WaitingQueue& waitingQueue, ResourceManager& resourceManager);
    void displayActiveReservations() const;
    void displayResourceUtilization() const;
    void displayMostRequestedResources() const;
    void displayWaitingListStatistics() const;
};

#endif