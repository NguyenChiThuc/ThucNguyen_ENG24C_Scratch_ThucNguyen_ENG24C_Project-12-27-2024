#include <stdio.h>
#include <stdlib.h>
#include"function.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int choice;
	int ChoiceMenuStudent;
	int currentLength=0;
	do{
		printMenu();
		printf("\nENTER THE CHOICE: ");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				break;
			case 2:{
				printMenuStudent();
				printf("Moi ban nhap lua chon: ");
				scanf("%d", &ChoiceMenuStudent);
			}
			case 3:
				break;
			case 0:
				break;
		}
	}while(choice!=0);
	return 0;
}
