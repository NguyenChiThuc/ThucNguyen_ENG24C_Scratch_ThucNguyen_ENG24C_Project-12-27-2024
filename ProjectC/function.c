#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "datatype.h"

void printMenu() {
    printf("\n***Student Management System Using C***\n");
    printf("===CHOOSE YOUR ROLE===\n");
    printf("=============================\n");
    printf("[1]  Admin\n");
    printf("[2]  Student\n");
    printf("[3]  Teacher\n");
    printf("[0]  Exit the Program\n");
    printf("\n=============================\n");
}

void printMenuStudent() {
    printf("\n***Student Management System Using C***\n");
    printf("\n=== STUDENT MENU ===\n");
    printf("\n========================\n");
    printf("[1]  Add A New Student\n");
    printf("[2]  Show All students\n");
    printf("[3]  Search A Student\n");
    printf("[4]  Edit A Student\n");
    printf("[5]  Delete A student\n");
    printf("[6]  Student arrangement\n");
    printf("[0]  Exit the Program\n");
    printf("\n=======================\n");
}

void printListInformation(struct Student students[], int n) {
    printf("|====|===========|====================|==========|======|====================|==============|\n");
    printf("| ID |  ClassId  |       Name         | BirthDate|Gender|      Email         |    Phone     |\n");
    printf("|====|===========|====================|==========|======|====================|==============|\n");
    
    int i;
    for (i = 0; i < n; i++) {
        printf("|%4d|%11s|%20s|%02d/%02d/%04d| %5s|%20s|%14s|\n",
            i + 1, students[i].classroomId, students[i].name,
            students[i].dateOfBirth.day, students[i].dateOfBirth.month, students[i].dateOfBirth.year,
            students[i].gender ? "Nam" : "Nu", students[i].email, students[i].phone);
        printf("|----|-----------|--------------------|----------|------|--------------------|--------------|\n");
    }
    printf("|====|===========|====================|==========|======|====================|==============|\n");
}

void addStudent(int *length, struct Student sv[]) {
    int isValidPhoneNumber(char* phone) {
        int i;
        for (i = 0; phone[i] != '\0'; i++) {
            if (!isdigit(phone[i])) {
                return 0; 
            }
        }
        return 1; 
    }

    int isValidEmail(char* email) {
        if (strchr(email, '@') != NULL) {
            return 1;  // valid if it contains '@'
        }
        return 0;
    }

    int isValidPassword(char* password) {
        if (strlen(password) >= 6) {
            return 1;  // valid if the password has at least 6 characters
        }
        return 0;
    }

    printf("\n\t***Add a new student***\n");
    int newStudents;
    printf("\nEnter the number of students to add: ");
    scanf("%d", &newStudents);
    getchar();
    
    int i;
    for (i = *length; i < *length + newStudents; i++) {
        printf("\n       Student %d\n", i + 1);
        
        // Enter student information
        printf("Enter Student ID: ");
        fgets(sv[i].studentId, 10, stdin);
        sv[i].studentId[strcspn(sv[i].studentId, "\n")] = '\0';
        
        printf("Enter student name: ");
        fgets(sv[i].fullName, 30, stdin);
        sv[i].fullName[strcspn(sv[i].fullName, "\n")] = '\0';
        
        // Enter date of birth with validation
        printf("Enter student's birthdate (dd/mm/yyyy): \n");
        do {
            printf("   Enter day: ");
            scanf("%d", &sv[i].dateOfBrith.day);
            if (sv[i].dateOfBrith.day < 1 || sv[i].dateOfBrith.day > 31) {
                printf("Invalid day! Please enter again.\n");
            }
        } while (sv[i].dateOfBrith.day < 1 || sv[i].dateOfBrith.day > 31);
        
        do {
            printf("   Enter month: ");
            scanf("%d", &sv[i].dateOfBrith.month);
            if (sv[i].dateOfBrith.month < 1 || sv[i].dateOfBrith.month > 12) {
                printf("Invalid month! Please enter again.\n");
            }
        } while (sv[i].dateOfBrith.month < 1 || sv[i].dateOfBrith.month > 12);
        
        do {
            printf("   Enter year: ");
            scanf("%d", &sv[i].dateOfBrith.year);
            if (sv[i].dateOfBrith.year < 1 || sv[i].dateOfBrith.year > 2024) {
                printf("Invalid year! Please enter again.\n");
            }
        } while (sv[i].dateOfBrith.year < 1 || sv[i].dateOfBrith.year > 2024);
        
        // Enter gender with validation
        do {
            printf("Enter student's gender (1 for Male, 0 for Female): ");
            scanf("%d", &sv[i].gender);
            if (sv[i].gender != 1 && sv[i].gender != 0) {
                printf("Invalid gender! Please enter again.\n");
            }
        } while (sv[i].gender != 1 && sv[i].gender != 0);
        
        getchar();
        
        // Enter classroom ID
        printf("Enter student's classroom ID: ");
        fgets(sv[i].classroomId, 10, stdin);
        sv[i].classroomId[strcspn(sv[i].classroomId, "\n")] = '\0';
        
        // Enter email and validate
        do {
            printf("Enter student's email: ");
            fgets(sv[i].email, 30, stdin);
            sv[i].email[strcspn(sv[i].email, "\n")] = '\0';
            if (!isValidEmail(sv[i].email)) {
                printf("Invalid email! Please enter again.\n");
            }
        } while (!isValidEmail(sv[i].email));
        
        // Enter phone number and validate
        do {
            printf("Enter student's phone number: ");
            fgets(sv[i].phone, 20, stdin);
            sv[i].phone[strcspn(sv[i].phone, "\n")] = '\0';
            if (!isValidPhoneNumber(sv[i].phone)) {
                printf("Invalid phone number! Please enter again.\n");
            }
        } while (!isValidPhoneNumber(sv[i].phone));
        
        // Enter password and validate
        do {
            printf("Enter student's password: ");
            fgets(sv[i].password, 20, stdin);
            sv[i].password[strcspn(sv[i].password, "\n")] = '\0';
            if (!isValidPassword(sv[i].password)) {
                printf("Password must have at least 6 characters. Please enter again.\n");
            }
        } while (!isValidPassword(sv[i].password));
    }
    
    *length += newStudents;
    printf("\nStudents added successfully.\n");
}

void editInformation(struct Student students[50], int count) {
    system("cls");
    int found = 0;
    char id[50];
    printf("Enter the student ID to edit information: ");
    scanf("%s", id);
    getchar();
    int i;
    for (i = 0; i < count; i++) {
        if (strcmp(students[i].studentId, id) == 0){
            found = 1;
            printf("Information of student ID %s:\n", id);
            printf("Class ID: %s\n", students[i].classroomId);
            printf("Name: %s\n", students[i].name);
            printf("Email: %s\n", students[i].email);
            printf("Phone number: %s\n", students[i].phone);            
            printf("Enter class ID: ");
            fgets(students[i].classroomId, sizeof(students[i].classroomId), stdin);
            students[i].classroomId[strcspn(students[i].classroomId, "\n")] = '\0';            
            printf("Enter name: ");
            fgets(students[i].name, sizeof(students[i].name), stdin);
            students[i].name[strcspn(students[i].name, "\n")] = '\0';            
            printf("Enter birthdate (dd mm yyyy): ");
            scanf("%d %d %d", &students[i].dateOfBirth.day, &students[i].dateOfBirth.month, &students[i].dateOfBirth.year);
            getchar();            
            printf("Enter gender (1: Male, 0: Female): ");
            scanf("%d", &students[i].gender);
            getchar();            
            printf("Enter email: ");
            fgets(students[i].email, sizeof(students[i].email), stdin);
            students[i].email[strcspn(students[i].email, "\n")] = '\0';            
            printf("Enter phone number: ");
            fgets(students[i].phone, sizeof(students[i].phone), stdin);
            students[i].phone[strcspn(students[i].phone, "\n")] = '\0';
            printf("Information updated successfully.\n");
            break;
        }
    }
    if (!found) {
        printf("Student ID not found, please try again.\n");
    }
}

void deleteStudent(struct Student students[50], int *n) {
    int found = 0;
    int choice;
    char id[10];
    printf("Enter the student ID to delete: ");
    scanf("%s", id);
    int i;
    for (i = 0; i < *n; i++) {
        if (strcmp(students[i].studentId, id) == 0){
            found = 1;
            for (int j = i; j < *n - 1; j++) {
                students[j] = students[j + 1];
            }
            (*n)--;
            printf("Student ID %s deleted successfully.\n", id);
            break;
        }
    }
    if (!found) {
        printf("Student ID not found, please try again.\n");
    }
}

void bubblesortStudent(struct Student students[50], int n) {
    int i, j;
    struct Student temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (strcmp(students[j].name, students[j + 1].name) > 0) {
                temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
    printf("List sorted successfully.\n");
}

