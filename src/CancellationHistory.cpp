#include "CancellationHistory.h"
#include <iostream>
#include <string>
using namespace std;

bool CancellationHistory::isEmpty(){
    return top == nullptr;
}
void CancellationHistory::storeCancellation(int studentID, string studentName, string resourceID, int reservationID, string date, string startTime, string endTime){
    CancellationRequest* newNode = new CancellationRequest;
    newNode->studentID = studentID;
    newNode->studentName = studentName;
    newNode->resourceID = resourceID;
    newNode->date = date;
    newNode->startTime = startTime;
    newNode->endTime = endTime;
    newNode->reservationID = reservationID;
    newNode->next = top;
    top = newNode;
    size = size + 1;
}
CancellationRequest CancellationHistory::restoreLastCancellation(){
    if(isEmpty()){
        CancellationRequest empty;
        empty.studentID = -1;
        empty.studentName = "";
        empty.resourceID = "";
        empty.date = "";
        empty.startTime = "";
        empty.endTime = "";
        empty.reservationID = -1;
        empty.next = nullptr;
        return empty;
    }
    CancellationRequest* temp = top;
    CancellationRequest data = *temp;
    top = top->next;
    delete temp;
    size = size-1;
    return data;   
}
void CancellationHistory::displayHistory(){
    if(isEmpty()){
        cout << "There is not cancellation history." << endl;
        return;
    }
    CancellationRequest* current = top;
    while(current != nullptr){
        cout << "[" << current->studentID << "] Room: " << current->resourceID
     << " | Reservation ID: " << current->reservationID 
     << " | Cancelled at: " << current->date << " | Start time: " << current->startTime << " | End time: " << current->endTime << endl;
        current = current->next;
    }
}
CancellationHistory::~CancellationHistory(){
    CancellationRequest* current = top;
    while(current != nullptr){
        CancellationRequest* temp = current;
        current = current->next;
        delete temp;
    }
}
