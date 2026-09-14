#ifndef RESERVATION_H
#define RESERVATION_H
#include <string>
using namespace std;

class Reservation{
private:
    int reservationID;
    int studentID;
    string studentName;
    string resourceID;
    string reservationDate;

public:
    Reservation(); 

    Reservation(int reservationID, int studentID, string studentName, stirng resoureID, string reservationDate);

    int getReservationID() const;
    int getStudentID() const;
    string getStudentName() const;
    string getResourceID() const;
    string getReservationDate() const;

    void displayReservation() const;
};

#endif
