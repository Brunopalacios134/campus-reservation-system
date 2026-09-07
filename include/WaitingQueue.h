#ifndef WAITINGQUEUE_H
#define WAITINGQUEUE_H
#include <string>
using namespace std;

struct WaitingRequest {
    string studentId;
    string resourceId;
    string timestamp;
    WaitingRequest* next;
};
class WaitingQueue{
private:
    WaitingRequest* front = nullptr;
    WaitingRequest* rear = nullptr;
    int size = 0;
    
public:
    void addToWaitingList(string studentId, string resourceId, string timestamp);
    WaitingRequest removeFromWaitingList();
    void displayWaitingList();
    bool isEmpty();
    ~WaitingQueue();

};
#endif
