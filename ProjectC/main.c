#include <stdio.h>
#include <stdlib.h>
#include"function.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int ch;
 	int choice;
    int subChoice;
    int n = 1;
    struct Student students[100] = {
        {"1", "ENG24C", "ThucNguyen", {6, 5, 2006}, true, "nct@gmail.com", "123456789", "123456"},
    };

    do {
    	system("cls");
        printMenu();
        printf("\nENTER THE CHOICE: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                break;
            case 2:
            	back:
            	system("cls");
                printMenuStudent();
                printf("\tEnter the Choice: ");
                scanf("%d", &subChoice);
                switch (subChoice){
                    case 1:
                    	system("cls");
                        addStudent(students, &n);
                        printListInformation(students, n);
						printf("Go back(b) or Exit(any): ");
						scanf("%c", &ch);
						getchar();
						if(ch='b'){
							goto back;
						}else{
							subChoice=0;
						} 
                        break;
                    case 2:
                    	system("cls");
                        printListInformation(students, n);
                        printf("Go back(b) or Exit(any): ");
						scanf("%c", &ch);
						getchar();
						if(ch='b'){
							goto back;
						}else{
							subChoice=0;
						}
                        break;
                    case 3:
                        break;
                    case 4:
                    	system("cls");
                    	editInformation(students, n);
                    	printf("Go back(b) or Exit(any): ");
						scanf("%c", &ch);
						getchar();
						if(ch='b'){
							goto back;
						}else{
							subChoice=0;
						}
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

