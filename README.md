                                                  ===== Campus Resource Reservation System ======

A comprehensive C++ application for managing university resource reservations, built as an educational project to apply object-oriented programming, data structures, and algorithms.

                                                            ====== Overview ========

This system manages campus resources including study rooms, laptops, calculators, lab equipment, and tutoring appointments. It provides:

Resource Management: Load, search, sort, and display available resources
Reservation System: Students can reserve resources for specific dates/times
Waiting Lists: FIFO queue system for unavailable resources
Cancellation History: Stack-based undo functionality for recent cancellations
Reporting: Generate usage statistics and utilization reports
File Persistence: Load/save all data to files

                                                            ===== Key Features =====
- Data Structures Used
  --> Linked Lists: Store resources and reservations
  --> Stacks: Maintain cancellation history for undo functionality
  --> Queues: Implement FIFO waiting lists per resource
  --> Hash Maps: Quick resource ID lookups


  campus-resource-system/
├── Header/                   # Header files (.h)
│   ├── ResourceManager.h
│   ├── Resource.h
│   ├── ReservationManager.h
│   ├── WaitingListRequest.h
│   ├── ReservationList.h
│   ├── Reservation.h   
│   └── CancellationHistory.h              
├── source code/              # Implementation files (.cpp)
│   ├── main.cpp              # Entry point
│   ├── CancellationHistory.cpp
│   ├── Reservation.cpp
│   ├── ReservationList.cpp
│   ├── ReservationManager.cpp
│   ├── Resource.cpp
│   ├── ResourceManager.cpp
│   └── WaitingQueue.cpp
├── data/                     # Data files
│   ├── resources.txt         # Input resource data
│   ├── reservations.txt      # Output reservations
│   └── waiting_lists.txt     # Output waiting lists
└── README.md                 # This file

                                                          ===== Running the Application =====


===== CAMPUS RESOURCE RESERVATION SYSTEM =====

1. View Resources
2. Create Reservation
3. Cancel Reservation
4. View Waiting List
5. Undo Cancellation
6. Search Reservations
7. Sort Resources
8. Generate Report
9. Exit

                                                          ===== Naming Conventions =====


// Classes - PascalCase
class ReservationSystem { };

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

// ... class declaration ...

#endif // CLASSNAME_H
