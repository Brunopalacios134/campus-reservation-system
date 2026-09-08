#include "../include/WaitingQueue.h"
#include <iostream>
using namespace std;

int main() {
    WaitingQueue q;
    q.addToWaitingList("student1", "room101", "10:00");
    q.addToWaitingList("student2", "room102", "10:05");
    q.displayWaitingList();

    cout << "Removing one..." << endl;
    q.removeFromWaitingList();
    q.displayWaitingList();

    return 0;
}