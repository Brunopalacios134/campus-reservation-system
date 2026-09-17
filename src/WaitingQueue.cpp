#include "WaitingQueue.h"
#include <iostream>
#include <string>
using namespace std;
bool WaitingQueue::isEmpty(){
    return size == 0;
}
void WaitingQueue::addToWaitingList(int studentID, string resourceID, string timestamp){
    WaitingRequest* newNode = new WaitingRequest;
    newNode->studentID = studentID;
    newNode->resourceID = resourceID;
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
        empty.studentID = -1;
        empty.resourceID = "";
        empty.timestamp = "";
        empty.next = nullptr;
        return empty;
    }
    WaitingRequest* temp = front;
    WaitingRequest removed;
    removed.studentID = temp->studentID;
    removed.resourceID = temp->resourceID;
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
        cout << "[" << current->studentID << "] Room: " << current->resourceID 
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

