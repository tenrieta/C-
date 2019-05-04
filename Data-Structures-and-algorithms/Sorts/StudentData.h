#ifndef STUDENTDATA_H
#define STUDENTDATA_H
#include "Student.h"

class StudentData
{
    public:
        StudentData();
        StudentData(const StudentData& s);
        StudentData& operator = (const StudentData& s);
        ~StudentData();
        void addStudent(Student* s);
        Student* firstStudent();
    //private:
        Student* head;
        Student* tail;
        Student* helper;
        //int sizze;
        //Student* cur;
};

#endif
