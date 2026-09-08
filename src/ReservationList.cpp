#include "ReservationList.h"
#include <iostream>
#include <string>
using namespace std;
bool ReservationList::remove(string reservationId){
    if(head==nullptr){
        return false;
    }
    if(head->reservationId == reservationId){
        Reservationrequest* temp = head;
        head = head->next;
        delete temp;
        size = size - 1;
        return true;
    }
    Reservationrequest* current = head;
    while(current->next != nullptr){
        if(current->next->reservationId == reservationId){
            Reservationrequest* temp = current->next;
            current->next = temp->next;
            delete temp;
            size = size-1;
            return true;
        }
        current = current->next;
    }
    return false;


}
void ReservationList::insert(string studentId, string resourceId, string timestamp, string reservationId){
    Reservationrequest* newNode = new Reservationrequest;
    newNode->studentId = studentId;
    newNode->resourceId = resourceId;
    newNode->timestamp = timestamp;
    newNode->reservationId = reservationId;
    newNode->next = head;
    head = newNode;
    size = size + 1;
    
}