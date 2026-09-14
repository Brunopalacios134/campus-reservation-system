#include "CancellationHistory.h"
#include <iostream>
#include <string>
using namespace std;

bool CancellationHistory::isEmpty(){
    return top == nullptr;
}
void CancellationHistory::storeCancellation(string studentId, string resourceId, string timestamp, string reservationId){
    CancellationRequest* newNode = new CancellationRequest;
    newNode->studentId = studentId;
    newNode->resourceId = resourceId;
    newNode->timestamp = timestamp;
    newNode->reservationId = reservationId;
    newNode->next = top;
    top = newNode;
    size = size + 1;
}
CancellationRequest CancellationHistory::restoreLastCancellation(){
    if(isEmpty()){
        CancellationRequest empty;
        empty.studentId = "";
        empty.resourceId = "";
        empty.timestamp = "";
        empty.reservationId= "";
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
        cout << "[" << current->studentId << "] Room: " << current->resourceId 
             << " | Reservation ID: " << current->reservationId 
             << " | Cancelled at: " << current->timestamp << endl;
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
