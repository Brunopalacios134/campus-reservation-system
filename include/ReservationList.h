#ifndef RESERVATIONLIST_H
#define RESERVATIONLIST_H
#include <string>
using namespace std;

struct Reservationrequest {
    string studentId;
    string resourceId;
    string timestamp;
    string reservationId;
    Reservationrequest* next;
};

class ReservationList{
private:
    Reservationrequest* head = nullptr;
    int size = 0;

public:
    void insert(string studentId, string resourceId, string timestamp, string reservationId);
    bool remove(string reservationId);
    void traverse();
    void displayReservationList();
    bool validateRequest(string resourceId);
    ~ReservationList();
};
#endif