#include "StudentData.h"
#include <iostream>

StudentData::StudentData()//here?
{
    head = new Student;
    tail = new Student;
    helper = new Student;
    helper->name = NULL;
    helper->subject = NULL;
    helper->date = NULL;
    helper->prev = tail;
    helper->next = head;
    head->prev = helper;
    tail->next = helper;
    tail = head;
    //sizze = 0;
}

StudentData:: StudentData(const StudentData& s)
{
    std::cout<<"Cant copy students"<<std::endl;
}

StudentData& StudentData:: operator = (const StudentData& s)
{
    std::cout<<"Students cant be assigned"<<std::endl;
    return *this;
}

StudentData::~StudentData()
{
    //delete[] head;
    //delete[] tail;
    //delete[] cur;
}

void StudentData:: addStudent(Student* s)
{
    Student* tmp = new Student;
    tmp = s;
    tail->next = tmp;
    tmp->prev = tail;
    tmp->next = helper;
    tail = tmp;
    //sizze++;
}

Student* StudentData:: firstStudent()
{
    return head;
}
