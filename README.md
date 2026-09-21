                                                  ===== Campus Resource Reservation System ======

A comprehensive C++ application for managing university resource reservations, built as an educational project to apply object-oriented programming, data structures, and algorithms.

                                                            ====== Overview ========

This system manages campus resources including study rooms, laptops, calculators, lab equipment, and tutoring appointments. It provides:

Resource Management: Load, search, sort, and display available resources
Reservation System: Students can reserve resources for specific dates
Waiting Lists: FIFO queue system for unavailable resources
Cancellation History: Stack-based undo functionality for recent cancellations

                                                            ===== Key Features =====
- Data Structures Used
  --> Linked Lists: Store resources and reservations
  --> Stacks: Maintain cancellation history for undo functionality
  --> Queues: Implement FIFO waiting lists per resource
  --> Vector: Stores and manages the resource inventory


campus-reservation-system/
├── include/
│   ├── Resource.h
│   ├── ResourceManager.h
│   ├── Reservation.h
│   ├── ReservationList.h
│   ├── WaitingQueue.h
│   ├── CancellationHistory.h
│   └── ReservationManager.h
├── src/
│   ├── main.cpp
│   ├── Resource.cpp
│   ├── ResourceManager.cpp
│   ├── Reservation.cpp
│   ├── ReservationList.cpp
│   ├── WaitingQueue.cpp
│   ├── CancellationHistory.cpp
│   └── ReservationManager.cpp
├── data/
│   └── resources.txt
├── tests/
│   └── test_queue.cpp
└── docs/
    └── complexity_analysis.md

                                                          ===== Running the Application =====


===== CAMPUS RESOURCE RESERVATION SYSTEM =====

1. View Resources
2. Create Reservation
3. Cancel Reservation
4. View Waiting List
5. Undo Cancellation
6. Search Reservations
7. Sort Resources
8. Generate Report(Note: "Generate Report" is listed in the menu but not implemented in Milestone 1)
9. Exit

                                                          ===== Naming Conventions =====


// Classes - PascalCase
class ReservationManager { };

// Methods/Functions - camelCase
void displayAllResources();
int getTotalResourceCount();

// Variables - camelCase
int studentID;
string resourceName;
bool isAvailable;

// Constants - UPPER_SNAKE_CASE
const int MAX_RESOURCES = 100;
const string DATE_FORMAT = "YYYY-MM-DD";

                                                            ===== Header Guard Format =====

#ifndef CLASSNAME_H
#define CLASSNAME_H

// 

#endif // CLASSNAME_H
