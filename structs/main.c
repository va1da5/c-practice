#include <stdio.h>
#include <string.h>

// https://www.youtube.com/watch?v=dqa0KMSMx2w&list=PLA1FTfKBAEX4hblYoH6mnq0zsie2w6Wif&index=22

struct Pupil
{
    char name[50];
    char id[37];
    int age;
    int grades[5];
};

typedef struct
{
    char name[50];
    char id[37];
    int age;
    int grades[5];
} Student;

void print_student(Student student);

int main(void)
{
    struct Pupil kevin;

    kevin.age = 21;

    strcpy(kevin.name, "Kevin");
    strcpy(kevin.id, "6753d6eb-9f93-4e35-bedf-22a2a044d40b");

    kevin.grades[0] = 7;
    kevin.grades[1] = 8;
    kevin.grades[2] = 9;
    kevin.grades[3] = 6;
    kevin.grades[4] = 9;

    printf("Name: %s, Age: %d\n\n\n", kevin.name, kevin.age);

    // -----------------------------------------

    Student martin;

    strcpy(martin.name, "Martin");
    strcpy(martin.id, "13e4c5a3-bcf7-4ca4-abf4-f36e9d5ac173");

    int grades[] = {5, 6, 7, 8, 9};
    memcpy(martin.grades, grades, sizeof(martin.grades));

    print_student(martin);

    // -----------------------------------------

    Student marry = {
        .id = "45610764-96d5-4375-a815-3c4a214f2ee6",
        .name = "Marry",
        .age = 22,
        .grades = {6, 7, 8, 9, 10}};

    print_student(marry);

    return 0;
}

void print_student(Student student)
{
    printf("ID: %s\n", student.id);
    printf("Name: %s\n", student.name);
    printf("Age: %d\n", student.age);
    printf("Grades: ");
    for (int i = 0; i < 5; i++)
    {
        printf("%d, ", student.grades[i]);
    }
    printf("\n\n");
}