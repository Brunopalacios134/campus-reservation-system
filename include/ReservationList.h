#ifndef RESERVATIONLIST_H
#define RESERVATIONLIST_H
#include "Reservation.h"

class ReservationList{
  private:
    struct Node{
    Reservation data;
    Node* next;

    Node(const Reservation& reservation)
    {
      data = reservation;
      next = nullptr;
    }
  };
Node* head;

public:

ReservationList();

~ReservationList();

void insertReservation(const Reservation& reservation);

bool removeReservation(int reservationID, Reservation& removedReservation);

bool reservationExists(int reservationID) const;

bool isEmpty() const;

void displayReservations() const;
};

#endif
