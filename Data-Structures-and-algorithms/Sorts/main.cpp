#include <iostream>
#include <cstring>
#include <fstream>
#include <stdlib.h>
#include "StudentData.h"

using namespace std;

int main()
{
    char input[39];//za program i fail
    char whatToSort[8];
    char typeSort[5];
    char* str = new char[256];
    char* name = new char[256];
    char* age = new char[3];
    char* subject = new char[256];
    char* grade = new char[2];
    char* date = new char[11];
    bool flag = true;
    int j = 0, k = 0, cntData = 1, cntUpper = 0;
    StudentData d;
    Student* tmp = new Student;
    /*cin.getline(input,38);
    //cout<<strlen(input)<<endl;
    for(int i=25; i<strlen(input); i++)
    {
        if(input[i]==' ')
        {
            flag = false;
            i++;
            whatToSort[j] = '\0';
            j = 0;
        }
        if(flag == true)
        {
            whatToSort[j] = input[i];
        }
        else
        {
            typeSort[j] = input[i];
        }
        j++;
    }
    typeSort[j] = '\0';
    //cout<<whatToSort<<endl;
    //cout<<typeSort<<endl;*/
    j = 0;
    ifstream myfile("exams-data.csv");//pyt do faila??
    if(myfile.is_open())
    {
        while(true)
        {
            myfile>>str[j];
            j++;
            if(myfile.eof())
                break;
        }
        myfile.close();
    }
    //cout<<str<<endl;
    str[j] = '\0';
    j = 27;
    while(str[j]!='\0')
    {

        if((cntData==1) && (str[j]!=',') && !(str[j]>='0'&&str[j]<='9'))//imena
        {
            if(str[j]>='A'&&str[j]<='Z')
            {
                cntUpper++;
            }
            if(cntUpper == 2)
            {
                name[k] = ' ';
                name[k+1] = str[j];
                cntUpper = 0;
                k++;
            }
            else
            {
                name[k] = str[j];
            }
            k++;
        }
        else if((cntData==2) && (str[j]!=',') && (str[j]>='0'&&str[j]<='9'))
        {
            age[k] = str[j];
            k++;
        }
        else if((cntData == 3) && (str[j]!=',') && !(str[j]>='0'&&str[j]<='9'))
        {
            subject[k] = str[j];
            k++;
        }
        else if((cntData == 4)&& (str[j]>='0'&&str[j]<='9'))
        {
            grade[k] = str[j];
            k++;
        }
        else if((cntData == 5) && (str[j]!=',') && ((str[j]>='0'&&str[j]<='9')||str[j]=='-'))
        {
            date[k] = str[j];
            k++;
        }
        else
        {
            switch(cntData)
            {
                case 1:
                    name[k] = '\0';
                    break;
                case 2:
                    age[k] = '\0';
                    break;
                case 3:
                    subject[k] = '\0';
                    break;
                case 4:
                    grade[k] = '\0';
                    break;
                case 5:
                    date[k] = '\0';
                    break;
                default:
                    break;
            }
            cntData++;
            k = 0;
        }
        if(cntData>5)//vlizaaaa v bezkraen zaradi /0
        {
            cntData = 1;
            k = 0;
            //j -= 1;
            if(tmp!=NULL)
                delete[] tmp;
            tmp->setName(name);
            cout<<tmp->name<<endl;
            tmp->setAge(atoi(age));
            cout<<tmp->age<<endl;
            tmp->setSubject(subject);
            cout<<tmp->subject<<endl;
            tmp->setGrade(atoi(grade));
            cout<<tmp->grade<<endl;
            tmp->setDate(date);
            cout<<tmp->date<<endl;
            d.addStudent(tmp);
        }
        j++;
    }
    //cout<<endl;
    /*cout<<name<<endl;
    cout<<age<<endl;
    cout<<subject<<endl;
    cout<<grade<<endl;
    cout<<date<<endl;*/
    //Student* tmp2 = new Student;
    //tmp2 = d.firstStudent();
    //cout<<tmp2->name<<endl;
    //myfile.close();
return 0;
}
