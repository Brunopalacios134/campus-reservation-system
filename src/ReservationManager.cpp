#include "ReservationManager.h"
#include <iostream>

using namespace std;

ReservationManager:: ReservationManager(ReservationList& reservationList,ResourceManager& resourceManager, WaitingQueue& waitingQueue, CancellationHistory& cancellationHistory)
:reservationList(reservationList), resourceManager(resourceManager),waitingQueue(waitingQueue), cancellationHistory(cancellationHistory){}

bool ReservationManager::createReservation(int reservationID,int studentID, string studentName, string resourceID, string date){
  if (reservationList.reservationExists(reservationID)){
    cout << "reservation ID already exists." << endl;
    return false;
  }
  Resource* resource = resourceManager.search(resourceID);
  if (resource == nullptr){
    cout << "Invalid resource ID." << endl;
    return false;
  }
  
  if (!resource->isAvailable()){
    waitingQueue.addToWaitingList(studentID, resourceID, date);
    cout << "Resource is unavailable. Student added to waiting list." << endl;
    return false;
  }

  Reservation reservation (reservationID, studentID, studentName, resourceID, date);
  reservationList.insertReservation(reservation);
  resource->setAvailability(false);
  cout << "Reservation Created Successfully." << endl;
  return true;
}

bool ReservationManager::cancelReservation(int reservationID){
  Reservation removedReservation;

  if (!reservationList.removeReservation(reservationID, removedReservation)){
    cout << "Reservation not found." << endl;
    return false;
  }
cancellationHistory.storeCancellation(removedReservation.getStudentID(), removedReservation.getStudentName(), removedReservation.getResourceID(), removedReservation.getReservationID(), removedReservation.getDate());

Resource* resource = resourceManager.search(removedReservation.getResourceID());

if(resource != nullptr){
  resource->setAvailability(true);
}

cout << "Reservation Cancelled." << endl;
cout << "Added to cancellation history." << endl;

return true;
}

bool ReservationManager::undoCancellation(){
  CancellationRequest restored = cancellationHistory.restoreLastCancellation();

  if (restored.reservationID == -1){
    cout << "No cancellation to undo." << endl;
    return false;
  }

  if (reservationList.reservationExists(restored.reservationID)){
    cancellationHistory.storeCancellation(restored.studentID, restored.studentName, restored.resourceID, restored.reservationID, restored.date);
    cout << "Reservation ID already exists. Cannot restore reservation." << endl;
    return false;
  }

  Resource* resource = resourceManager.search(restored.resourceID);

  if (resource == nullptr || !resource->isAvailable()){
    cancellationHistory.storeCancellation(restored.studentID, restored.studentName, restored.resourceID, restored.reservationID, restored.date);
    cout << "Resource is unavailable. Cannot restore reservation." << endl;
    return false;
  }
  Reservation reservation(restored.reservationID, restored.studentID, restored.studentName, restored.resourceID, restored.date);
  reservationList.insertReservation(reservation);
  resource->setAvailability(false);
  cout << "Reservation Restored Successfully." << endl;
  return true;
}

void ReservationManager::displayReservations() const{
reservationList.displayReservations();
}














