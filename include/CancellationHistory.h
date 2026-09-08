#ifndef CANCELLATIONHISTORY_H
#define CANCELLATIONHISTORY_H
#include <string>
using namespace std;

struct CancellationRequest{
    string studentId;
    string resourceId;
    string timestamp;
    string reservationId;
    CancellationRequest* next;

};
class CancellationHistory{
private:
    CancellationRequest* top = nullptr;
    int size = 0;
public:
    void storeCancellation(string studentId, string resourceId, string timestamp, string reservationId);
    CancellationRequest restoreLastCancellation();
    void displayHistory();
    ~CancellationHistory();
};



#endif