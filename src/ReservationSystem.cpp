#include "ReservationSystem.h"
#include <iostream>

using namespace std;

ReservationSystem::ReservationSystem() {
    nextReservationID = 1001;
}

void ReservationSystem::loadResources(string filename) {

    if (resourceManager.loadFromFile(filename)) {
        cout << "Resources loaded successfully.\n";
    }
}

void ReservationSystem::displayResources() {
    resourceManager.displayAll();
}

void ReservationSystem::createReservation() {

    string studentID;
    string studentName;
    string resourceID;
    string date;

    cout << "\nEnter Student ID: ";
    cin >> studentID;

    cin.ignore();

    cout << "Enter Student Name: ";
    getline(cin, studentName);

    cout << "Enter Resource ID: ";
    cin >> resourceID;

    cout << "Enter Reservation Date: ";
    cin >> date;

    Resource* resource =
        resourceManager.search(resourceID);

    if (resource == nullptr) {

        cout << "Resource not found.\n";
        return;
    }

    if (!resource->isAvailable()) {

        cout << "Resource is unavailable.\n";

        char choice;

        cout << "Would you like to join the waiting list? (Y/N): ";
        cin >> choice;

        if (choice == 'Y' || choice == 'y') {

            WaitingRequest request;

            request.studentID = studentID;
            request.studentName = studentName;
            request.resourceID = resourceID;
            request.date = date;

            waitingQueue.addStudent(request);

            cout << "Student added to waiting list.\n";
        }

        return;
    }

    string reservationID =
        "R" + to_string(nextReservationID++);

    Reservation reservation(
        reservationID,
        studentID,
        studentName,
        resourceID,
        date
    );

    reservationList.insert(reservation);

    resource->setAvailability(false);

    cout << "\nReservation created successfully.\n";

    reservation.display();
}

void ReservationSystem::cancelReservation() {

    string reservationID;

    cout << "\nEnter Reservation ID to cancel: ";
    cin >> reservationID;

    Reservation cancelled;

    if (!reservationList.remove(
            reservationID,
            cancelled)) {

        cout << "Reservation not found.\n";
        return;
    }

    cancellationStack.push(cancelled);

    Resource* resource =
        resourceManager.search(
            cancelled.getResourceID()
        );

    if (resource != nullptr) {
        resource->setAvailability(true);
    }

    cout << "Reservation cancelled successfully.\n";

    processWaitingList();
}

void ReservationSystem::undoCancellation() {

    Reservation reservation;

    if (!cancellationStack.pop(reservation)) {

        cout << "No cancellation to undo.\n";
        return;
    }

    Resource* resource =
        resourceManager.search(
            reservation.getResourceID()
        );

    if (resource == nullptr) {
        cout << "Resource no longer exists.\n";
        return;
    }

    if (!resource->isAvailable()) {

        cout << "Resource is currently unavailable.\n";
        cout << "Reservation cannot be restored.\n";

        cancellationStack.push(reservation);

        return;
    }

    reservationList.insert(reservation);

    resource->setAvailability(false);

    cout << "Most recent cancellation restored.\n";
}

void ReservationSystem::displayReservations() {

    cout << "\nActive Reservations:\n";

    reservationList.display();
}

void ReservationSystem::searchReservation() {

    string reservationID;

    cout << "\nEnter Reservation ID: ";
    cin >> reservationID;

    Reservation* reservation =
        reservationList.search(reservationID);

    if (reservation == nullptr) {

        cout << "Reservation not found.\n";
        return;
    }

    reservation->display();
}

void ReservationSystem::displayWaitingList() {
    waitingQueue.display();
}

void ReservationSystem::displayCancellationHistory() {
    cancellationStack.display();
}

void ReservationSystem::processWaitingList() {

    if (waitingQueue.empty()) {
        return;
    }

    // We need to check the first waiting student.
    WaitingRequest request;

    waitingQueue.removeStudent(request);

    Resource* resource =
        resourceManager.search(request.resourceID);

    if (resource == nullptr) {
        return;
    }

    if (!resource->isAvailable()) {

        // Resource still unavailable.
        waitingQueue.addStudent(request);

        return;
    }

    string reservationID =
        "R" + to_string(nextReservationID++);

    Reservation reservation(
        reservationID,
        request.studentID,
        request.studentName,
        request.resourceID,
        request.date
    );

    reservationList.insert(reservation);

    resource->setAvailability(false);

    cout << "\nWaiting-list student automatically assigned.\n";

    reservation.display();
}

void ReservationSystem::run() {

    int choice;

    do {

        cout << "\n==============================\n";
        cout << "Campus Resource Reservation\n";
        cout << "==============================\n";

        cout << "1. Display Resources\n";
        cout << "2. Display Availability\n";
        cout << "3. Create Reservation\n";
        cout << "4. Cancel Reservation\n";
        cout << "5. View Active Reservations\n";
        cout << "6. Search Reservation\n";
        cout << "7. View Waiting List\n";
        cout << "8. View Cancellation History\n";
        cout << "9. Undo Cancellation\n";
        cout << "10. Sort Resources by Name\n";
        cout << "11. Sort Resources by Type\n";
        cout << "0. Exit\n";

        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            displayResources();
            break;

        case 2:
            resourceManager.displayAvailability();
            break;

        case 3:
            createReservation();
            break;

        case 4:
            cancelReservation();
            break;

        case 5:
            displayReservations();
            break;

        case 6:
            searchReservation();
            break;

        case 7:
            displayWaitingList();
            break;

        case 8:
            displayCancellationHistory();
            break;

        case 9:
            undoCancellation();
            break;

        case 10:
            resourceManager.sortByName();
            cout << "Resources sorted by name.\n";
            break;

        case 11:
            resourceManager.sortByType();
            cout << "Resources sorted by type.\n";
            break;

        case 0:
            cout << "Goodbye!\n";
            break;

        default:
            cout << "Invalid option.\n";
        }

    } while (choice != 0);
}