#include <stdio.h>
#include <stdlib.h>
#include "function.h"

int main(int argc, char *argv[]) {
    int ch;
    int choice;
    int subChoice;
    int n = 1;
    struct Student students[100] = {
        {"0", "ENG24C", "ThucNguyen", {6, 5, 2006}, 1, "nct@gmail.com", "123456789", "123456"},
    };

    do {
        system("cls");
        printMenu();
        printf("\nENTER THE CHOICE: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                // Admin functionality can be added here later
                break;

            case 2:
                do {
                    system("cls");
                    printMenuStudent();
                    printf("\tEnter the Choice: ");
                    scanf("%d", &subChoice);

                    switch (subChoice) {
                        case 1:
                            system("cls");
                            addStudent(&n, students);
                            printListInformation(students, n);
                            printf("Go back(b) or Exit(any): ");
                            getchar(); // to clear the previous input buffer
                            scanf("%c", &ch);
                            if (ch == 'b') {
                                continue; // Go back to student menu
                            } else {
                                subChoice = 0; // Exit the loop
                            }
                            break;

                        case 2:
                            system("cls");
                            printListInformation(students, n);
                            printf("Go back(b) or Exit(any): ");
                            getchar();
                            scanf("%c", &ch);
                            if (ch == 'b') {
                                continue;
                            } else {
                                subChoice = 0;
                            }
                            break;

                        case 3:
                            // Search functionality for student can be added here
                            break;

                        case 4:
                            system("cls");
                            editInformation(students, n);
                            printf("Go back(b) or Exit(any): ");
                            getchar();
                            scanf("%c", &ch);
                            if (ch == 'b') {
                                continue;
                            } else {
                                subChoice = 0;
                            }
                            break;

                        case 5:
                            system("cls");
                            deleteStudent(students, &n);
                            printf("Go back(b) or Exit(any): ");
                            getchar();
                            scanf("%c", &ch);
                            if (ch == 'b') {
                                continue;
                            } else {
                                subChoice = 0;
                            }
                            break;

                        case 6:
                            system("cls");
                            bubbleSortStudent(students, n);
                            printf("Go back(b) or Exit(any): ");
                            getchar();
                            scanf("%c", &ch);
                            if (ch == 'b') {
                                continue;
                            } else {
                                subChoice = 0;
                            }
                            break;

                        case 0:
                            break;

                        default:
                            printf("Invalid choice! Please try again.\n");
                            break;
                    }
                } while (subChoice != 0);
                break;

            case 3:
                // Teacher functionality can be added here later
                break;

            case 0:
                printf("Thank you, goodbye!\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 0);
    return 0;
}

