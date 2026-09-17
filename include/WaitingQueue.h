#ifndef WAITINGQUEUE_H
#define WAITINGQUEUE_H
#include <string>
using namespace std;

struct WaitingRequest {
    int studentID;
    string resourceID;
    string timestamp;
    WaitingRequest* next;
};
class WaitingQueue{
private:
    WaitingRequest* front = nullptr;
    WaitingRequest* rear = nullptr;
    int size = 0;
    
public:
    void addToWaitingList(int studentID, string resourceID, string timestamp);
    WaitingRequest removeFromWaitingList();
    void displayWaitingList();
    bool isEmpty();
    ~WaitingQueue();

};
#endif
