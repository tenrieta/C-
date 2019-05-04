#include "Student.h"
#include <iostream>
#include <cstring>
//using namespace std;

Student::Student()
{
    name = NULL;
    age = 0;
    subject = NULL;
    grade = 2;
    date = NULL;
    prev = NULL;
    next = NULL;
}

Student:: Student(char* name, int age, char* subject, int grade, char* date, Student* prev, Student* next):prev(prev),next(next)
{
    setName(name);
    setAge(age);
    setSubject(subject);
    setGrade(grade);
    setDate(date);
}

Student::~Student()
{
    //delete[] name;
    //delete[] subject;
    //delete[] date;
}

void Student:: setName(char* name)
{
    if(this->name!=NULL)
        delete[] this->name;
    this->name = new char[strlen(name)+1];
    strcpy(this->name, name);
}

void Student:: setAge(int age)
{
    this->age = age;
}

void Student:: setSubject(char* subject)
{
    if(this->subject!=NULL)
        delete[] this->subject;
    this->subject = new char[strlen(subject)+1];
    strcpy(this->subject, subject);
}

void Student:: setGrade(int grade)
{
    this->grade = grade;
}

void Student:: setDate(char* date)
{
    if(this->date!=NULL)
        delete[] this->date;
    this->date = new char[strlen(date)+1];
    strcpy(this->date, date);
}
