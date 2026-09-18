#ifndef CANCELLATIONHISTORY_H
#define CANCELLATIONHISTORY_H
#include <string>
using namespace std;

struct CancellationRequest{
    int studentID;
    string studentName;
    string resourceID;
    int reservationID;
    string date;
    CancellationRequest* next;

};
class CancellationHistory{
private:
    CancellationRequest* top = nullptr;
    int size = 0;
public:
    bool isEmpty();
    void storeCancellation(int studentID, string studentName, string resourceID, int reservationID, string date);
    CancellationRequest restoreLastCancellation();
    void displayHistory();
    ~CancellationHistory();
};



#endif