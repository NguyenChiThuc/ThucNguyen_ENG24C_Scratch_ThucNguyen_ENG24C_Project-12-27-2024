#ifndef FUNCTION_H
#define FUNCTION_H

#include "datatype.h"  // Include the datatype header for Student structure

// Function Prototypes

// Menu printing functions
void printMenu();
void printMenuStudent();

// Student-related functions
void printInformation(struct Student students);  // Print information of a single student
void printListInformation(struct Student students[], int n);  // Print information of all students
void addStudent(int *length, struct Student sv[]);  // Add a student to the list
void addInformation(struct Student *std);  // Input and fill student information
void editInformation(struct Student students[], int count);  // Edit student information by ID
void deleteStudent(struct Student students[], int *n);  // Delete a student by ID
void bubblesortStudent(struct Student students[], int n);  // Sort students by name using bubble sort

#endif // FUNCTION_H

