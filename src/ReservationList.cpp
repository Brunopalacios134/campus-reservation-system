#include "ReservationList.h"
#include <iostream>
using namespace std;

ReservationList::ReservationList()
{
    head = nullptr;
}

ReservationList::~ReservationList()
{
    Node* current = head;

    while (current != nullptr)
        {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
}

void ReservationList::insertReservation(const Reservation& reservation)
{
    Node* newNode = new Node(reservation);

    newNode->next = head;
    head = newNode;
}

bool ReservationList::removeReservation(int reservationID, Reservation& removedReservation)
{
    Node* current = head;
    Node* previous = nullptr;

    while (current != nullptr)
        {
            if (current->data.getReservationID() == reservationID)
            {
                removedReservation = current->data;

                if (previous == nullptr)
                {
                    head = current->next;
                }
                else
                {
                    previous->next = current->next;
                }

                delete current;
                return true;
            }

            previous = current;
            current = current->next;
        }
    return false;
}

bool ReservationList::reservationExists(int reservationID) const
{
    Node* current = head;

    while (current != nullptr)
        {
            if (current->data.getReservationID() == reservationID)
            {
                return true;
            }
            current = current->next;
        }
    return false;
}

bool ReservationList::isEmpty() const
{
    return head == nullptr;
}

void ReservationList::displayReservations() const
{
    Node* current = head;

    if (current == nullptr)
    {
        cout << "No active reservations." << endl;
        return;
    }

    while (current != nullptr)
        {
            current->data.displayReservation();
            cout << endl;

            current = current->next;
        }
}
