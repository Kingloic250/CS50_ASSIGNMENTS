#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100

typedef struct {
    char name[50];
    int subject1;
    int subject2;
    int subject3;
    char grade;
} Student;

Student students[MAX_STUDENTS];
int studentCount = 0;

char calculateGrade(int avg) {
    if (avg >= 90) return 'A';
    else if (avg >= 80) return 'B';
    else if (avg >= 70) return 'C';
    else if (avg >= 60) return 'D';
    else return 'F';
}

void addStudent() {
    if (studentCount >= MAX_STUDENTS) {
        printf("Database is full!\n");
        return;
    }
    printf("Enter student name: ");
    scanf("%s", students[studentCount].name);
    printf("Enter marks for Subject 1: ");
    scanf("%d", &students[studentCount].subject1);
    printf("Enter marks for Subject 2: ");
    scanf("%d", &students[studentCount].subject2);
    printf("Enter marks for Subject 3: ");
    scanf("%d", &students[studentCount].subject3);
    
    int avg = (students[studentCount].subject1 + students[studentCount].subject2 + students[studentCount].subject3) / 3;
    students[studentCount].grade = calculateGrade(avg);
    
    studentCount++;
    printf("Student added successfully!\n");
}

void displayStudents() {
    if (studentCount == 0) {
        printf("No students in database!\n");
        return;
    }
    printf("\nStudent Records:\n");
    printf("---------------------------------------------\n");
    printf("Name\tSubject1\tSubject2\tSubject3\tGrade\n");
    printf("---------------------------------------------\n");
    for (int i = 0; i < studentCount; i++) {
        printf("%s\t%d\t%d\t%d\t%c\n", students[i].name, students[i].subject1, students[i].subject2, students[i].subject3, students[i].grade);
    }
}

void saveToFile() {
    FILE *file = fopen("students.dat", "wb");
    if (!file) {
        printf("Error saving file!\n");
        return;
    }
    fwrite(&studentCount, sizeof(int), 1, file);
    fwrite(students, sizeof(Student), studentCount, file);
    fclose(file);
    printf("Data saved successfully!\n");
}

void loadFromFile() {
    FILE *file = fopen("students.dat", "rb");
    if (!file) {
        printf("No previous data found!\n");
        return;
    }
    fread(&studentCount, sizeof(int), 1, file);
    fread(students, sizeof(Student), studentCount, file);
    fclose(file);
    printf("Data loaded successfully!\n");
}

int main() {
    int choice;
    loadFromFile();
    while (1) {
        printf("\nStudent Database Menu:\n");
        printf("1. Add Student\n2. Display Students\n3. Save and Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: saveToFile(); exit(0);
            default: printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
