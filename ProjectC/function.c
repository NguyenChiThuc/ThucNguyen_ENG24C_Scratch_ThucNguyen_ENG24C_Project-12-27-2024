#include"function.h"
#include<stdio.h>
#include<string.h>

void printMenu(){
	printf("\n***Student Management System Using C***\n");
	printf("===CHOOSE YOUR ROLE===\n");
	printf("=============================\n");
	printf("[1]  Admin\n");
	printf("[2]  Student\n");
	printf("[3]  Teacher\n");
	printf("[0]  Exit the Program\n");
	printf("\n=============================\n");
}

void printMenuStudent(){
	printf("\n***Student Managemnet System Using C***\n");
	printf("\n=== STUDENT MENU ===\n");
	printf("\n========================\n");
	printf("[1]  Add A New Student\n");
	printf("[2]  Show All students\n");
	printf("[3]  Search A Student\n");
	printf("[4]  Edit A Student\n");
	printf("[5]  Delete A student");
	printf("[0]  Exit the Program");
	printf("\n=======================\n");
}

void printListInformation(struct Student students[], int n){
	   	printf("|====|===========|==========|====================|==========|======|====================|==============|\n");
	    printf("| ID | StudentId |  ClassId |       Name         |BirthDate |Gender|      Email         |    Phone     |\n");
	    printf("|====|===========|==========|====================|==========|======|====================|==============|\n");
	int i;
    for (i = 0; i < n; i++) {
        printf("|%4d|%10s|%10s|%20s|%02d/%02d/%04d| %4s|%20s|%14s|\n",
            i + 1, students[i].studentId, students[i].classroomId, students[i].name,
            students[i].dateOfBirth.day, students[i].dateOfBirth.month, students[i].dateOfBirth.year,
            students[i].gender ? "Nam" : "Nu", students[i].email, students[i].phone);
    	printf("|----|----------|----------|--------------------|----------|------|--------------------|--------------|\n");
    }
    	printf("|====|==========|==========|====================|==========|======|====================|==============|\n");
    	printf("Go back(b)? or Exit(0)?: ");
}


void addStudent(struct Student students[100], int *n){
	if(*n<100){
        printf("\nNhap thong tin sinh vien thu %d:\n", *n + 1);
        addInformation(&students[*n]);
        (*n)++;
        printf("Them sinh vien thanh cong!\n");
    }else{
    	printf("Danh sach sinh vien da day!\n");
	}
}
void addInformation(struct Student *std) {
    fflush(stdin);
    	printf("Nhap ma sinh vien: ");
    fgets(std->studentId, sizeof(std->studentId), stdin);
    std->studentId[strcspn(std->studentId, "\n")] = '\0';
    	printf("Nhap ma lop hoc: ");
    fgets(std->classroomId, sizeof(std->classroomId), stdin);
    std->classroomId[strcspn(std->classroomId, "\n")] = '\0';
    	printf("Nhap ten: ");
    fgets(std->name, sizeof(std->name), stdin);
    std->name[strcspn(std->name, "\n")] = '\0';
    	printf("Nhap ngay sinh (dd mm yyyy): ");
    scanf("%d %d %d", &std->dateOfBirth.day, &std->dateOfBirth.month, &std->dateOfBirth.year);
    getchar();
    	printf("Nhap gioi tinh (1:Nam,0:Nu): ");
    scanf("%d", &std->gender);
    getchar();
    	printf("Nhap email: ");
    fgets(std->email, sizeof(std->email), stdin);
    std->email[strcspn(std->email, "\n")] = '\0';
    	printf("Nhap so dien thoai: ");
    fgets(std->phone, sizeof(std->phone), stdin);
    std->phone[strcspn(std->phone, "\n")] = '\0';
    	printf("Nhap mat khau: ");
    fgets(std->password, sizeof(std->password), stdin);
    std->password[strcspn(std->password, "\n")] = '\0';
}


