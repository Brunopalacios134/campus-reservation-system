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
void ReportManager::displayResourceUtilization() const {
    cout << "Resource Utilization" << endl;
    for (int i = 0; i < resourceManager.getResourceCount(); i++) {
        Resource r = resourceManager.getResourceAt(i);
        int n = reservations.countByResource(r.getResourceID());
        cout << "ID: " << r.getResourceID()
             << " | Name: " << r.getResourceName()
             << " | Active Reservations: " << n << endl;
    }
}

void ReportManager::displayWaitingListStatistics() const {
    cout << "Waiting List Statistics" << endl;

    bool hasWaitingStudents = false;

    for (int i = 0; i < resourceManager.getResourceCount(); i++) {
        Resource r = resourceManager.getResourceAt(i);

        int n = waitingQueue.countByResource(r.getResourceID());

        if (n > 0) {
            cout << "ID: " << r.getResourceID()
                 << " | Name: " << r.getResourceName()
                 << " | Students Waiting: " << n << endl;

            hasWaitingStudents = true;
        }
    }

    if (!hasWaitingStudents) {
        cout << "No students are currently waiting." << endl;
    }
}
