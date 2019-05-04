#ifndef STUDENT_H
#define STUDENT_H


struct Student
{
        Student();
        Student(char* name, int age, char* subject, int grade, char* date, Student* prev, Student* next);
        ~Student();
        void setName(char* name);
        char* getName()const{return this->name;}
        void setAge(int age);
        //int getAge()const{return this->age;}
        void setSubject(char* subject);
        //char* getSubject()const{return this->subject;}
        void setGrade(int grade);
        //int getGrade()const{return this->grade;}
        void setDate(char* date);
        //char* getDate()const{return this->date;}*/
        char* name;
        int age;
        char* subject;
        int grade;
        char* date;
        Student* prev;
        Student* next;
};

#endif
