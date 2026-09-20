ReservationSystem.h

#ifndef RESERVATIONSYSTEM_H
#define RESERVATIONSYSTEM_H

#include "ResourceManager.h"
#include "ReservationList.h"
#include "WaitingQueue.h"
#include "CancellationHistory.h"

class ReservationSystem {
private:
    ResourceManager resourceManager;
    ReservationList reservationList;
    WaitingQueue waitingQueue;
    CancellationHistory CancellationHistory;

    int nextReservationID;

public:
    ReservationSystem();

    void loadResources(string filename);

    void displayResources();

    void createReservation();

    void cancelReservation();

    void undoCancellation();

    void displayReservations();

    void searchReservation();

    void displayWaitingList();

    void displayCancellationHistory();

    void processWaitingList();

    void run();
};

#endif