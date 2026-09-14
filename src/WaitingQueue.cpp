#include "WaitingQueue.h"
#include <iostream>
#include <string>
using namespace std;
bool WaitingQueue::isEmpty(){
    return size == 0;
}
void WaitingQueue::addToWaitingList(string studentId, string resourceId, string timestamp){
    WaitingRequest* newNode = new WaitingRequest;
    newNode->studentId = studentId;
    newNode->resourceId = resourceId;
    newNode->timestamp = timestamp;
    newNode->next = nullptr;
    if(isEmpty()){
        front = newNode;
        rear = newNode;
    }
    else{
        rear->next = newNode;
        rear = newNode;
    }
    size = size + 1;
}
WaitingRequest WaitingQueue::removeFromWaitingList(){
    if(isEmpty()){
        WaitingRequest empty;
        empty.studentId = "";
        empty.resourceId = "";
        empty.timestamp = "";
        empty.next = nullptr;
        return empty;
    }
    WaitingRequest* temp = front;
    WaitingRequest removed;
    removed.studentId = temp->studentId;
    removed.resourceId = temp->resourceId;
    removed.timestamp = temp->timestamp;
    removed.next = nullptr;
    front = front->next;

    if(front == nullptr){
        rear = nullptr;
    }
    delete temp;
    size--;
    return removed;

}
void WaitingQueue::displayWaitingList(){
    if(isEmpty()){
        cout << "Waiting queue is empty." << endl;
        return;
    }
    WaitingRequest* current = front;
    while(current != nullptr){
        cout << "[" << current->studentId << "] Room: " << current->resourceId 
             << " | Requested: " << current->timestamp << endl;
        current = current->next;
    }
}
WaitingQueue::~WaitingQueue(){
    WaitingRequest* current = front;
    while(current != nullptr){
        WaitingRequest* temp = current;
        current = current->next;
        delete temp;
    }
}

