#include "ReportManager.h"
#include <iostream>
using namespace std;

ReportManager::ReportManager(ReservationList& reservations, WaitingQueue& waitingQueue, ResourceManager& resourceManager)
    : reservations(reservations),
      waitingQueue(waitingQueue),
      resourceManager(resourceManager)
{
}
void ReportManager::displayActiveReservations() const
{
    cout << "Active Reservations" << endl;
    reservations.displayReservations();
}