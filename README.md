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

- Algorithms Implemented
  --> Searching: Linear and binary search for resources and reservations
  --> Sorting: Bubble sort, insertion sort, and merge sort for various criteria
  --> Graph/Tree Concepts: Hierarchical resource categorization

  campus-resource-system/
├── Header/                   # Header files (.h)
│   ├── Resource.h
│   ├── Reservation.h
│   ├── WaitingListRequest.h
│   ├── ReservationSystem.h
│   ├── LinkedList.h          
│   ├── Stack.h               
│   └── Queue.h               
├── source code/              # Implementation files (.cpp)
│   ├── main.cpp              # Entry point
│   ├── Resource.cpp
│   ├── Reservation.cpp
│   ├── WaitingListRequest.cpp
│   └── ReservationSystem.cpp
├── data/                     # Data files
│   ├── resources.txt         # Input resource data
│   ├── reservations.txt      # Output reservations
│   └── waiting_lists.txt     # Output waiting lists
├── tests/                    # Unit tests
│   └── test_*.cpp
└── README.md                 # This file

                                                          ===== Running the Application =====


===== CAMPUS RESOURCE RESERVATION SYSTEM =====

1. Resource Management
   1.1 Load resources from file
   1.2 Add new resource
   1.3 Display all resources
   1.4 Search resources
   1.5 Sort resources
   
2. Reservation Management
   2.1 Create reservation
   2.2 Cancel reservation
   2.3 View my reservations
   2.4 View all reservations
   
3. Waiting List Management
   3.1 View waiting lists
   3.2 View waiting position
   
4. Cancellation History
   4.1 View recent cancellations
   4.2 Undo most recent cancellation
   
5. Reports
   5.1 System statistics
   5.2 Resource utilization
   5.3 Waiting list report
   5.4 Generate full report
   
6. File Operations
   6.1 Save all data
   6.2 Load reservations
   
0. Exit

Select option:

                                                              ===== Data File Formats ======

1. resources.txt (Input)
ResourceID    |Name              |Type          |Capacity
1             |Study Room A      |Study Room    |4
2             |Study Room B      |Study Room    |6
3             |Laptop 001        |Laptop        |1
4             |Lab Equipment UV  |Lab Equipment |1
5             |Tutoring Slot Math|Tutoring      |1


2. reservations.txt (Output)
ReservationID    |StudentID  |StudentName    |ResourceID      |ResourceName      |Date|StartTime  |EndTime      |Status
1001             |S001       |John Doe       |1|Study Room A  |2024-01-15        |09:00           |11:00        |Active
1002             |S002       |Jane Smith     |3|Laptop 001    |2024-01-15        |14:00           |15:30        |Active

3. waiting_lists.txt (Output)

ResourceID  |StudentID    |StudentName      |RequestDate    |RequestTime    |Priority      |DesiredDate
1           |S003         |Mike Johnson     |2024-01-15     |09:30:45       |1             |2024-01-16
1           |S004         |Sarah Williams   |2024-01-15     |10:15:22       |2             |2024-01-16


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





