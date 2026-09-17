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
    string date;
    string startTime;
    string endTime;

public:
    Reservation(); 

    Reservation(int reservationID, int studentID, string studentName, string resourceID, string date, string startTime, string endTime);

    int getReservationID() const;
    int getStudentID() const;
    string getStudentName() const;
    string getResourceID() const;
    string getDate() const;
    string getStartTime() const;
    string getEndTime() const;

    void displayReservation() const;
};

#endif
