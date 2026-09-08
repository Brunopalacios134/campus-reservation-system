#include "WaitingQueue.h"
#include <iostream>
#include <string>
using namespace std;
bool WaitingQueue::isEmpty(){
    return size == 0;
}
void WaitingQueue :: addToWaitingList(string studentId, string resourceId, string timestamp){
    WaitingRequest* newNode = new WaitingRequest;
    newNode->studentId = studentId;
    newNode->resourceId = resourceId;
    newNode->timestamp = timestamp;
    newNode->next = nullptr;

}
void WaitingQueue::removeFromWaitingList(){

}
void WaitingQueue::displayWaitingList(){

}
WaitingQueue::~WaitingQueue(){

}

