#include <stdio.h>
#include <stdlib.h>
#include"function.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int choice;
	int currentLength=0;
	do{
	printMenuStudent();		
		printf("\nENTER THE CHOICE\n");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				break;
			case 2:{
						printMenu();
			
				break;
			}
			case 3:
				break;
			case 0:
				break;
		}
	}while(choice!=0);
	return 0;
}
