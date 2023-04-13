/*
    The program to manipulate student data: name, age, phone
    Services:
        1. Add a student to record
        2. Load a student list (from binary file)
        3. Store current student list (to a binary file)
        4. Print list
 */

#include <stdio.h>
#include <stdlib.h>


// CONST
const int NUMBER = 100000;     // max number of student record can be stored
const int NAME_SIZE = 31;      // number of name characters
const int PHONE_SIZE = 21;     // number of phone characters
const char INPUT_FILE[] = "out.dat";     // student list file
const char OUTPUT_FILE[] = "out.dat";   // output file

// Student structure
typedef struct {
    char name[30];      // name of student
    int age;                   // age
    char phone[20];     // phone
} Student;

// FUNCTION DECLARE
/*
    to get in to interactive mode
 */
void interactive(Student **list, int *size);

/*  to load a student list from a INPUT_FILE
    - Input
        1. list of student
        2. address of number of student */
void load(Student **list, int *size);

/*  to store list of student to OUTPUT_FILE
    - Input:
        1. list of student
        2. size of list */
void store(Student **list, int size);

/*  to add a student to a given list
    - input:
        1. student record
        2. student list
        3. size of the list */
void add(Student **list, int *size);

/*
    to print the student list */
void print_list(Student **list, int size);


// MAIN
int main() {
    // declare list of student
    Student **list = (Student **) malloc (NUMBER * sizeof(Student *));
    int size = 0;   // actual number of student in the list
    // get into user interface
    interactive(list, &size);
    return 0;
}   // close main


// FUNCTION DEFINE

// open user interface
void interactive(Student **list, int *size) {
    printf("The program provides 3 services with student data:\n");
    printf("[1] Load student list from database.\n");
    printf("[2] Store current student list to database.\n");
    printf("[3] Add a student record to current student list.\n");
    printf("[4] Print student list.\n");
    printf("[0] Quit!\n");
    // Loop
    while (1) {
        int choice = 0;
        printf("Please enter your choice(a number): ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            load(list, size);
            break;
        case 2:
            store(list, *size);
            break;
        case 3:
            add(list, size);
            break;
        case 4:
            print_list(list, *size);
            break;
        default:
            return;
        }   // close switch
    }   // close while
} // close interactive


// load file
void load(Student **list, int *size) {
    FILE *file = fopen(INPUT_FILE, "rb");
    // check if being able to read file
    if (file == NULL) {
        printf("Unable to read file %s\n", INPUT_FILE);
        return;
    }   // close if
    // read all data in file
    while (!feof(file)) {
        Student *stu = (Student *) malloc (sizeof(Student));
        int number = fread(stu, sizeof(Student), 1, file);
        if (number == 0)
            break;
        // add new student record in the list
        list[*size] = stu;
        *size += 1;
    }   // close while
    printf("Successfully Loaded from file %s\n", INPUT_FILE);
    printf("Number of student loaded: %d\n", *size);
    fclose(file);
}   // close load


// store file
void store(Student **list, int size) {
    FILE *file = fopen(OUTPUT_FILE, "wb");
    // check if being able to write
    if (file == NULL) {
        printf("Unable to write to file %s\n", INPUT_FILE);
        return;
    }   // close if
    // write all student record to file
    for (int i = 0; i < size; i ++ ) {
        fwrite(list[i], sizeof(Student), 1, file);
    }   // close for
    printf("Successfully Stored in file: %s\n", OUTPUT_FILE);
    fclose(file);
}   // close store


// add student
void add(Student **list, int *size) {
    Student *stu = (Student *) malloc (sizeof(Student));
    // enter name
    printf("Enter student name: ");
    scanf("%s", stu->name);
    // enter age
    printf("Enter age: ");
    scanf("%d", &(stu->age));
    // enter phone
    printf("Enter phone number: ");
    scanf("%s", stu->phone);
    list[*size] = stu;
    *size += 1;
}   // close add


// print list
void print_list(Student **list, int size) {
    printf("Current student list:\n");
    for (int i = 0; i < size; i ++ ) {
        printf("%3d: Name: %s\tAge: %d\tPhone: %s\n", i, list[i]->name, list[i]->age, list[i]->phone);
    }   // close for
    printf("END LIST\n");
}   // close print_list
