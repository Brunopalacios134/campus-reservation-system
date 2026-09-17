#include "Reservation.h"
#include <iostream>
using namespace std;

Reservation::Reservation()
{
  reservationID = 0;
  studentID = 0;
  studentName = "";
  resourceID = "";
  date = "";
  startTime = "";
  endTime = "";
}

Reservation::Reservation(int reservationID, int studentID, string studentName, string resourceID, string date, string startTime, string endTime)
{
  this->reservationID = reservationID;
  this->studentID = studentID;
  this->studentName = studentName;
  this->resourceID = resourceID;
  this->date = date;
  this->startTime = startTime;
  this->endTime = endTime;
}

int Reservation::getReservationID() const
{
  return reservationID;
}

int Reservation::getStudentID() const
{
  return studentID;
}

string Reservation:: getStudentName() const
{
  return studentName;
}

string Reservation::getResourceID() const
{
  return resourceID;
}

string Reservation::getDate() const
{
  return date;
}
string Reservation::getStartTime() const
{
  return startTime;
}
string Reservation::getEndTime() const
{
  return endTime;
}


void Reservation::displayReservation() const
{
  cout<< "Reservation ID: " << reservationID << endl;
  cout<< "Student ID: " << studentID << endl;
  cout<< "Student Name: " << studentName << endl;
  cout<< "Resource ID: " << resourceID << endl;
  cout<< "Reservation Date: " << date << " | " << startTime << " | " << endTime << endl;
}
