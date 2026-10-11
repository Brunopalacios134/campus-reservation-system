#include <iostream>
#include <limits>
#include "Resource.h"
#include "ResourceManager.h"
#include "Reservation.h"
#include "ReservationList.h"
#include "WaitingQueue.h"
#include "CancellationHistory.h"
#include "ReservationManager.h"
#include "ReportManager.h"
using namespace std;
    int main(){
        int choice, sortChoice;
        ResourceManager resourceManager;
        ReservationList reservationList;
        WaitingQueue waitingQueue;
        CancellationHistory cancellationHistory;
        ReservationManager reservationManager(reservationList, resourceManager, waitingQueue, cancellationHistory);
resourceManager.loadFromFile("data/resources.txt");
        ReportManager reportManager(reservationList, waitingQueue, resourceManager);
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
                case 6:{
                    int searchID;
                    cout << "Enter Reservation ID to search: ";
                    if(!(cin >> searchID)){
                        cout << "Invalid reservation ID." << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        break;
                    }
                    reservationList.searchAndDisplay(searchID);
                break;
            }
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
                    else{
                        cout << "Invalid sorting choice." <<endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        break;
                    }
                    resourceManager.displayAll();
                    break;
                case 8: {
                    int reportChoice;

                    cout << "===== Reports Menu =====" << endl;
                    cout << "1. Active Reservations" << endl;
                    cout << "2. Resource Utilization" << endl;
                    cout << "3. Most Requested Resources" << endl;
                    cout << "4. Waiting List Statistics" << endl;
                    cout << "5. Back" << endl;

                    cout << "Enter Choice: ";
                    cin >> reportChoice;

                    if (cin.fail()) {
                        cout << "That is not a valid number." << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        break;
                    }

                    switch (reportChoice) {
                        case 1:
                            reportManager.displayActiveReservations();
                            break;

                        case 2:
                            reportManager.displayResourceUtilization();
                            break;

                        case 3:
                            reportManager.displayMostRequestedResources();
                            break;

                        case 4:
                            reportManager.displayWaitingListStatistics();
                            break;

                        case 5:
                            break;

                        default:
                            cout << "Invalid report choice." << endl;
                            break;
                    }

                    break;
                }
                case 9:
                    cout << "Exiting system." << endl;
                    break;
                default:
                    cout << "Invalid Choice! Please select between 1 and 9." << endl;
            }
        }while (choice != 9);
        return 0;
    }
    
