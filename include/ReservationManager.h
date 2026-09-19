#ifndef RESERVATIONMANAGER_H
#define RESERVATIONMANAGER_H

#include "ReservationList.h"
#include "ResourceManager.h"
#include "WaitingQueue.h"
#include "CancellationHistory.h"
#include <string>

using namespace std;

class ReservationManager{
  private:
    ReservationList& reservationList;
    ResourceManager& resourceManager;
    WaitingQueue& waitingQueue;
    CancellationHistory& cancellationHistory;

  public:
    ReservationManager(ReservationList& reservationList, ResourceManager& resourceManager, WaitingQueue& waitingQueue, CancellationHistory& cancellationHistory);
    bool createReservation(int reservationID, int studentID, string studentName,string resourceID, string date);
    bool cancelReservation(int reservationID);
    bool undoCancellation();
    void displayReservations() const;
};

#endif
