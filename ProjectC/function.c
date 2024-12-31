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
	printf("[5]  Delete A student\n");
	printf("[0]  Exit the Program\n");
	printf("\n=======================\n");
}

void printListInformation(struct Student students[], int n){

	   	printf("|====|===========|==========|====================|===========|======|====================|==============|\n");
	    printf("| ID | StudentId |  ClassId |       Name         | BirthDate |Gender|      Email         |    Phone     |\n");
	    printf("|====|===========|==========|====================|===========|======|====================|==============|\n");
	int i;
    for (i = 0; i < n; i++) {
        printf("|%4d|%10s|%10s|%20s|%02d/%02d/%04d| %4s|%20s|%14s|\n",
            i + 1, students[i].studentId, students[i].classroomId, students[i].name,
            students[i].dateOfBirth.day, students[i].dateOfBirth.month, students[i].dateOfBirth.year,
            students[i].gender ? "Nam" : "Nu", students[i].email, students[i].phone);
    	printf("|----|----------|----------|--------------------|------------|------|--------------------|--------------|\n");
    }
    	printf("|====|==========|==========|====================|============|======|====================|==============|\n");
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
void editInformation(struct Student students[50], int count) {
    system("cls");
    int found = 0;
    int i;
    char id[50];
    printf("Nhap ID sinh vien muon sua thong tin: ");
    scanf("%s", id);
    getchar();
    for (i = 0; i < count; i++) {
        if (strcmp(students[i].studentId, id) == 0) {
            found = 1;
            printf("Thong tin cua sinh vien ID %s:\n", id);
            printf("ID: %s\n", students[i].studentId);
            printf("Ma lop hoc: %s\n", students[i].classroomId);
            printf("Ten: %s\n", students[i].name);
            printf("Email: %s\n", students[i].email);
            printf("So dien thoai: %s\n", students[i].phone);            
            printf("Nhap ma lop hoc: ");
            fgets(students[i].classroomId, sizeof(students[i].classroomId), stdin);
            students[i].classroomId[strcspn(students[i].classroomId, "\n")] = '\0';            
            printf("Nhap ten: ");
            fgets(students[i].name, sizeof(students[i].name), stdin);
            students[i].name[strcspn(students[i].name, "\n")] = '\0';            
            printf("Nhap ngay sinh (dd mm yyyy): ");
            scanf("%d %d %d", &students[i].dateOfBirth.day, &students[i].dateOfBirth.month, &students[i].dateOfBirth.year);
            getchar();            
            printf("Nhap gioi tinh (1:Nam, 0:Nu): ");
            scanf("%d", &students[i].gender);
            getchar();            
            printf("Nhap email: ");
            fgets(students[i].email, sizeof(students[i].email), stdin);
            students[i].email[strcspn(students[i].email, "\n")] = '\0';            
            printf("Nhap so dien thoai: ");
            fgets(students[i].phone, sizeof(students[i].phone), stdin);
            students[i].phone[strcspn(students[i].phone, "\n")] = '\0';
            printf("Thong tin da duoc cap nhat thanh cong\n");
            break;
        }
    }
    if (!found) {
        printf("ID sinh vien khong ton tai, hay nhap lai\n");
    }
}

