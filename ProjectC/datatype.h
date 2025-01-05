#ifndef DATATYPE_H
#define DATATYPE_H

#include <stdbool.h>

// Date structure
struct Date {
    int day;
    int month;
    int year;
};

// Student structure
struct Student {
    char id[10];
    char course[10];
    char name[50];
    struct Date birthdate;
    bool gender;  // true for male, false for female
    char email[50];
    char phone[15];
    char password[50];
};

// Function declarations
void printMenu();
void printMenuStudent();
void printInformation(struct Student students);
void printListInformation(struct Student students[], int n);
void addStudent(int *length, struct Student sv[]);
void addInformation(struct Student *std);
void editInformation(struct Student students[], int count);
void deleteStudent(struct Student students[], int *n);
void bubblesortStudent(struct Student students[], int n);

#endif // DATATYPE_H

