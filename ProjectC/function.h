#include"datatype.h"
void printMenu();
void printMenuStudent();
void printInformation(struct Student students);
void printListInformation(struct Student students[], int n);
void addStudent(struct Student students[100], int *n);
void addInformation(struct Student *std);
void editInformation(struct Student students[50], int count);
void deleteStudent(struct Student students[50], int *n);
void bubblesortStudent(struct Student students[50], int n);
