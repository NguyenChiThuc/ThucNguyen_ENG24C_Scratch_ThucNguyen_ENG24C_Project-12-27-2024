#include <stdio.h>
#include <stdlib.h>
#include"function.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
 	int choice;
    int subChoice;
    int n = 1;
    struct Student students[100] = {
        {"1", "ENG24C", "ThucNguyen", {6, 5, 2006}, true, "nct@gmail.com", "123456789", "123456"},
    };

    do {
        printMenu();
        printf("\nENTER THE CHOICE: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                break;
            case 2:
                printMenuStudent();
                printf("\tEnter the Choice: ");
                scanf("%d", &subChoice);
                switch (subChoice){
                    case 1:
                        addStudent(students, &n);
                        printListInformation(students, n); 
                        break;
                    case 2:
                        printListInformation(students, n);
                        break;
                    case 3:
                        break;
                    case 4:
                        break;
                    case 5:
                        break;
                    case 0:
                        break;
                    default:
                        printf("Lua chon cua ban khong hop le!!!\n");
                        break;
                }
                break;
            case 3:
                break;
            case 0:
                printf("Cam on, tam biet\n");
                break;
            default:
                printf("Lua chon cua ban khong hop le!!!\n");
                break;
        }
    } while(choice != 0);
    return 0;
}

