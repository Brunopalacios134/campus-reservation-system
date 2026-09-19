#include <iostream>
#include <limits>
#include "Resource.h"
#include "ResourceManager.h"
#include "Reservation.h"
#include "Reservationlist.h"
#include "WaitingQueue.h"
#include "CancellationHistory.h"
#include "ReservationManager.h"
using namespace std;
    int main(){
        int choice, sortChoice;
        ResourceManager resourceManager;
        ReservationList reservationList;
        WaitingQueue waitingQueue;
        CancellationHistory cancellationHistory;
        ReservationManager reservationManager(reservationList, resourceManager, waitingQueue, cancellationHistory);
resourceManager.loadFromFile("data/resources.txt"); 
        do{
            cout << "===== Campus Resource Reservation System =====" << endl;
            cout << "1. View Resources" << endl;
            cout << "2. Create Reservation" << endl;
            cout << "3. Cancel Reservation" << endl;
            cout << "4. View Waiting List" << endl;
            cout << "5. Undo Cancellation" << endl;
            cout << "6. Search Reservations" << endl;
            cout << "7. Sort Resources" << endl;
            cout << "8. Generate Report" << endl;
            cout << "9. Exit" << endl;

            cout << endl << "Enter Choice: ";
            cin >> choice;
            if(cin.fail()){
                cout << "That is not a valid number." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            switch (choice){
                case 1:
                    cout << "Displaying available resources..." << endl;
                    resourceManager.displayAll();
                    break;
                case 2:{
                    cout << "Opening reservation form..." << endl;
                    int newReservationID, newStudentID;
                    string newStudentName, newResourceID, newDate;
                    cout << "Enter Reservation ID: ";
                    cin >> newReservationID;
                    cout << "Enter Student ID: ";
                    cin >> newStudentID;
                    cin.ignore(); 
                    cout << "Enter Student Name: ";
                    getline(cin, newStudentName);
                    cout << "Enter Resource ID: ";
                    cin >> newResourceID;
                    cout << "Enter Date: ";
                    cin >> newDate;
                    reservationManager.createReservation(newReservationID, newStudentID, newStudentName, newResourceID, newDate);
                    break;
                }
                case 3: {
                    int idToCancel;
                    cout << "Enter Reservation ID to cancel: ";
                    cin >> idToCancel;
                    reservationManager.cancelReservation(idToCancel);
                    cout << "Canceling reservation..." << endl;
                    break;
                }
                case 4:
                    cout << "Loading waiting list..." << endl;
                    waitingQueue.displayWaitingList();
                    break;
                case 5:
                    reservationManager.undoCancellation();
                    cout << "Undoing last cancellation..." << endl;
                    break;
                case 6:
                    cout << "Searching for reservations..." << endl;
                    reservationList.displayReservations();
                    break;
                case 7:
                    cout << "Please make a selection." << endl; 
                    cout << "1. Sort by Name  |  2. Sort by Type" << endl;
                    cin >> sortChoice;
                    if(sortChoice == 1){
                        cout << "Sorting resources by NAME..." << endl; 
                        resourceManager.sortByName();
                    }
                    else if(sortChoice == 2){
                        cout << "Sorting resources by TYPE..." << endl;
                        resourceManager.sortByType();
                    }
                    resourceManager.displayAll();
                    break;
                case 8:
                    cout << "Generating usage report..." << endl;
                    cout << "This feature is not implemented in Milestone 1." << endl;
                    break;
                case 9:
                    cout << "Exiting system." << endl;
                    break;
                default:
                    cout << "Invalid Choice! Please select between 1 and 9." << endl;
            }
        }while (choice != 9);
        return 0;
    }
    