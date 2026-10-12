# User Guide
 
Campus Resource Reservation System
 
This guide explains how to start the program and how to use every option of the main menu.
## 1. Starting the Program
Open a terminal in the root folder of the project
```
g++ -Wall -Wextra -Iinclude src/*.cpp -o campus_system
./campus_system
```
 
On Windows, run it with `.\campus_system`.
 
When the program starts it loads the 20 resources from `data/resources.txt` and shows the main menu:
 
```
===== Campus Resource Reservation System =====
1. View Resources
2. Create Reservation
3. Cancel Reservation
4. View Waiting List
5. Undo Cancellation
6. Search Reservations
7. Sort Resources
8. Generate Report
9. Exit
 
Enter Choice:
```
Type the number of the option and press Enter. After every action the menu is shown again until you choose 9.
 
## 2. Main Menu Options
 
### 1. View Resources
Shows every resource.
```
All Resources:
ID: R101 | Name: Study Room 101 | Type: Study Room | Status: Available
ID: R102 | Name: Study Room 102 | Type: Study Room | Status: Available
```
### 2. Create Reservation
 
The program asks for five values, one at a time
If the resource is available, the reservation is created:
```
Reservation Created Successfully.
```
If the reservation ID is already used, nothing is created:
```
reservation ID already exists.
```
If the resource is already reserved, the student is added to the waiting list instead:
```
Resource is unavailable. Student added to waiting list.
```
### 3. Cancel Reservation
 
Type the ID of the reservation to cancel. The resource becomes available again and the cancelled reservation is saved in the cancellation history so it can be restored later.

### 4. View Waiting List
 
Shows the students waiting for a resource, in the order they asked (first in, first out). Each line shows the student ID, the resource, and the date requested.
 
```
[1002] Room: R101 | Requested: 2026-10-12
```
 
### 5. Undo Cancellation
 
Restores the most recently cancelled reservation. The history works as a stack: the last reservation cancelled is the first one restored.
 
```
Reservation Restored Successfully.
Undoing last cancellation...
```
 
### 6. Search Reservations
 
Type a reservation ID. If it exists, the reservation is displayed:
 
```
Enter Reservation ID to search: 1
Reservation ID: 1
Student ID: 1001
Student Name: Ana Lopez
Resource ID: R101
Reservation Date: 2026-10-12
```
 
If it does not exist:
 
```
Enter Reservation ID to search: 99
Reservation not found.
```
### 7. Sort Resources
 
Choose how to sort the resource list, and then displays the sorted list:
 
```
Please make a selection.
1. Sort by Name  |  2. Sort by Type
```
### 8. Generate Report
 
Opens the reports menu:
 
```
===== Reports Menu =====
1. Active Reservations
2. Resource Utilization
3. Most Requested Resources
4. Waiting List Statistics
5. Back
```
### 9. Exit
 
Closes the program.


## Invalid Input
Every prompt that expects a number checks what was typed. If a letter or symbol is typed instead of a number, the program shows an error message and returns to the main menu.






