#ifndef STUDENT_H
#define STUDENT_H

typedef struct {
    char* name;
    int age;
    float grade;
} Student;

#define MAX_STRING_LENGTH 256

Student* createStudent(char* name, int age, float grade);  /*riceve tre valori va la malloc */
void setName(Student* student, char* name);  /*cambia il nome dello studente e lo riceve per referenza*/
char* getName(Student student); /*riceve il nome dello studente per copia*/
void setAge(Student* student, int age);
int getAge(Student student);
void setGrade(Student* student, float grade);
float getGrade(Student student);
void disposeStudent(Student* student); /*ammazza lo studente*/
void printStudent(Student student); /*stampa i dati dello studente*/
char* studentToCSV(Student student);
Student* createFromCSV(char* csvLine);

#include "Student.c"
#endif // STUDENT_H


