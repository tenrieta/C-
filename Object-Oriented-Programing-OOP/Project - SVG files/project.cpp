#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <fstream>

#define MAX_COLOR_LENGTH 10
#define MAX_NUMBER_LENGTH 15
#define PROJECT_FILE "project.svg"
#define TEST_FILE "test.txt"

using namespace std;

class Rectangle
{
public:
    Rectangle();
    Rectangle(const Rectangle& rect);
    Rectangle& operator = (const Rectangle& rect);
    ~Rectangle();
    char* get_xValue() const;
    char* get_yValue() const;
    char* get_widht() const;
    char* get_heigh() const;
    char* get_color() const;

    void set_xValue(char* x);
    void set_yValue(char* y);
    void set_widht(char* w);
    void set_heigh(char* h);
    void set_color(char* color);
private:
    char* xValue;
    char* yValue;
    char* widht;
    char* heigh;
    char* fill;
};
class Line
{
public:
    Line();
    Line(const Line& line);
    Line& operator = (const Line& line);
    ~Line();
    char* get_xValue() const;
    char* get_yValue() const;
    char* get_x1Value() const;
    char* get_y1Value() const;
    char* get_color() const;

    void set_xValue(char* x);
    void set_yValue(char* y);
    void set_x1Value(char* x1);
    void set_y1Value(char* y1);
    void set_color(char* color);
private:
    char* xValue;
    char* yValue;
    char* x1Value;
    char* y1Value;
    char* fill;
};
class Circle
{
public:
    Circle();
    Circle(const Circle& circ);
    Circle& operator = (const Circle& circ);
    ~Circle();
    char* get_xValue() const;
    char* get_yValue() const;
    char* get_radius() const;
    char* get_color() const;

    void set_xValue(char* x);
    void set_yValue(char* y);
    void set_radius(char* r);
    void set_color(char* color);
private:
    char* xValue;
    char* yValue;
    char* radius;
    char* fill;

};
Rectangle::Rectangle()
{
    this->xValue = new char[MAX_NUMBER_LENGTH];
    this->yValue = new char[MAX_NUMBER_LENGTH];
    this->widht = new char[MAX_NUMBER_LENGTH];
    this->heigh = new char[MAX_NUMBER_LENGTH];
    this->fill = new char[MAX_COLOR_LENGTH];
}
Rectangle::Rectangle(const Rectangle& rect)
{
    this->xValue = new char[MAX_NUMBER_LENGTH];
    strcpy(this->xValue,rect.xValue);
    this->yValue = new char[MAX_NUMBER_LENGTH];
    strcpy(this->yValue,rect.yValue);
    this->widht = new char[MAX_NUMBER_LENGTH];
    strcpy(this->widht,rect.widht);
    this->heigh = new char[MAX_NUMBER_LENGTH];
    strcpy(this->heigh,rect.heigh);
    this->fill = new char[MAX_COLOR_LENGTH];
    strcpy(this->fill,rect.fill);
}
Rectangle& Rectangle::operator = (const Rectangle& rect)
{
    if(this==&rect)
        return *this;
    strcpy(this->xValue,rect.xValue);
    strcpy(this->yValue,rect.yValue);
    strcpy(this->widht,rect.widht);
    strcpy(this->heigh,rect.heigh);
    strcpy(this->fill,rect.fill);
    return *this;
}
Rectangle::~Rectangle()
{
    delete [] xValue;
    delete [] yValue;
    delete [] widht;
    delete [] heigh;
    delete [] fill;
}
char* Rectangle::get_xValue() const
{
    return this->xValue;
}
char* Rectangle::get_yValue() const
{
    return this->yValue;
}
char* Rectangle::get_widht() const
{
    return this->widht;
}
char* Rectangle::get_heigh() const
{
    return this->heigh;
}
char* Rectangle::get_color() const
{
    return this->fill;
}

void Rectangle::set_xValue(char* x)
{
    strcpy(this->xValue,x);
}
void Rectangle::set_yValue(char* y)
{
     strcpy(this->yValue,y);
}
void Rectangle::set_widht(char* w)
{
    strcpy(this->widht,w);
}
void Rectangle::set_heigh(char* h)
{
    strcpy(this->heigh,h);
}
void Rectangle::set_color(char* color)
{
    strcpy(this->fill,color);
}

Line::Line()
{
    this->xValue = new char[MAX_NUMBER_LENGTH];
    this->yValue = new char[MAX_NUMBER_LENGTH];
    this->x1Value = new char[MAX_NUMBER_LENGTH];
    this->y1Value = new char[MAX_NUMBER_LENGTH];
    this->fill = new char[MAX_COLOR_LENGTH];
}
Line::Line(const Line& line)
{
    this->xValue = new char[MAX_NUMBER_LENGTH];
    strcpy(this->xValue,line.xValue);
    this->yValue = new char[MAX_NUMBER_LENGTH];
    strcpy(this->yValue,line.yValue);
    this->x1Value = new char[MAX_NUMBER_LENGTH];
    strcpy(this->x1Value,line.x1Value);
    this->y1Value = new char[MAX_NUMBER_LENGTH];
    strcpy(this->y1Value,line.y1Value);
    this->fill = new char[strlen(line.fill)];
    strcpy(this->fill,line.fill);
}
Line& Line::operator = (const Line& line)
{
    if(this==&line)
        return *this;
    strcpy(this->xValue,line.xValue);
    strcpy(this->yValue,line.yValue);
    strcpy(this->x1Value,line.x1Value);
    strcpy(this->y1Value,line.y1Value);
    strcpy(this->fill,line.fill);
    return *this;
}
Line::~Line()
{
    delete [] xValue;
    delete [] yValue;
    delete [] x1Value;
    delete [] y1Value;
    delete [] fill;
}
char* Line::get_xValue() const
{
    return this->xValue;
}
char* Line::get_yValue() const
{
    return this->yValue;
}
char* Line::get_x1Value() const
{
    return this->x1Value;
}
char* Line::get_y1Value() const
{
    return this->y1Value;
}
char* Line::get_color() const
{
    return this->fill;
}

void Line::set_xValue(char* x)
{
     strcpy(this->xValue,x);
}
void Line::set_yValue(char* y)
{
     strcpy(this->yValue,y);
}
void Line::set_x1Value(char* x1)
{
     strcpy(this->x1Value,x1);
}
void Line::set_y1Value(char* y1)
{
     strcpy(this->y1Value,y1);
}
void Line::set_color(char* color)
{
    strcpy(this->fill,color);
}

Circle::Circle()
{
    this->xValue = new char[MAX_NUMBER_LENGTH];
    this->yValue = new char[MAX_NUMBER_LENGTH];
    this->radius = new char[MAX_NUMBER_LENGTH];
    this->fill = new char[MAX_COLOR_LENGTH];
}
Circle::Circle(const Circle& circ)
{
    this->xValue = new char[MAX_NUMBER_LENGTH];
    strcpy(this->xValue,circ.xValue);
    this->yValue = new char[MAX_NUMBER_LENGTH];
    strcpy(this->yValue,circ.yValue);
    this->radius = new char[MAX_NUMBER_LENGTH];
    strcpy(this->radius,circ.radius);
    this->fill = new char[MAX_COLOR_LENGTH];
    strcpy(this->fill,circ.fill);
}
Circle& Circle::operator = (const Circle& circ)
{
    if(this==&circ)
        return *this;
    strcpy(this->xValue,circ.xValue);
    strcpy(this->yValue,circ.yValue);
    strcpy(this->radius,circ.radius);
    strcpy(this->fill,circ.fill);
    return *this;
}
Circle::~Circle()
{
    delete [] fill;
}
char* Circle::get_xValue() const
{
    return this->xValue;
}
char* Circle::get_yValue() const
{
    return this->yValue;
}
char* Circle::get_radius() const
{
    return this->radius;
}
char* Circle::get_color() const
{
    return this->fill;
}

void Circle::set_xValue(char* x)
{
    strcpy(this->xValue,x);
}
void Circle::set_yValue(char* y)
{
    strcpy(this->yValue,y);
}
void Circle::set_radius(char* r)
{
    strcpy(this->radius,r);
}
void Circle::set_color(char* color)
{
    strcpy(this->fill,color);
}

void wipeTestFile(char* fileName,fstream &fileClose);
void createTestFile(char* fileName);
int mainFunc(char* str,fstream &file,fstream &testFile,char* fileName);
void makeRectangle(char* xValue,char* yValue,char* widthValue,char* heightValue,char* colour,fstream &file,fstream &testFile,char* fileName,int choice);
void makeLine(char* x1Value,char* y1Value,char* x2Value,char* y2Value,char* colour,fstream &file,fstream &testFile,char* fileName,int choice);
void makeCircle(char* cxValue,char* cyValue,char* rValue,char* colour,fstream &file,fstream &testFile,char* fileName,int choice);
char* getSting(char* str,int counter);
void changeFiles(fstream &testFile,fstream &file,char* fileName);
void printFigures(fstream &file,fstream &testFile);
void printLine(char* str,int func, char* returnArr);
void eraseFigure(int lineNum,fstream &file,fstream &testFile,char* fileName);
void openFile(fstream &file,char* name);
void translate(fstream &file,fstream &testFile,char* fileName,char* str);
void translateLine(char* str,fstream &file,fstream &testFile,char* fileName,char* horizontal,char* vertical);

int main()
{
    createTestFile(TEST_FILE);
    int wrongCommandFlag = 0;
    char command[256];
    int returnCommand = 0;
    fstream file;
    fstream testFile;

    while(1)
    {
        cin.getline(command,256);
        if((strcmp(command,"open") == 0) && (returnCommand == 0))
        {
            wrongCommandFlag = 1;
            cout << "Molq vuvedete imeto na faila" << endl;
            cin.getline(command,256);
            openFile(file,command);
            openFile(testFile,TEST_FILE);
            while(1)
            {
                cin.getline(command,256);
                returnCommand = mainFunc(command,file,testFile,PROJECT_FILE);
                testFile.close();
                testFile.open(TEST_FILE,std::fstream::in | std::fstream::out | std::fstream::app);
                file.close();
                file.open(TEST_FILE,std::fstream::in | std::fstream::out | std::fstream::app);
                if(returnCommand)
                {
                    break;
                }
            }
        }
        if((strcmp(command,"close") == 0) || (returnCommand == 3))
        {
            wrongCommandFlag = 1;
            file.close();
            testFile.close();
        }
        if((strcmp(command,"save") == 0) || (returnCommand == 2))
        {
            wrongCommandFlag = 1;
            file.close();
            testFile.close();
        }
        if((strcmp(command,"save as") == 0) || (returnCommand == 2))
        {
            wrongCommandFlag = 1;
            cout << "Molq vuvdete direktoriq" << endl;
            cin.getline(command,256);
            file.close();
            testFile.close();
        }
        if((strcmp(command,"exit") == 0) || (returnCommand == 1))
        {
            wrongCommandFlag = 1;
            break;
        }
        if(!wrongCommandFlag)
        {
            wrongCommandFlag = 0;
            cout << "Greshna komanda" << endl;
        }
        wrongCommandFlag = 0;
    }

    file.close();
    testFile.close();
    return 0;
}
void wipeTestFile(char* fileName,fstream &fileClose)
{
    fileClose.close();
    ofstream file(fileName, std::ofstream::out | std::ofstream::trunc);
    file.close();
    fileClose.open(fileName,std::fstream::in | std::fstream::out | std::fstream::app);
}
void createTestFile(char* fileName)
{
    ofstream file(fileName,ios::app);
    file.close();
}
int mainFunc(char* str,fstream &file,fstream &testFile,char* fileName)
{
    char* tempString = new char[strlen(str) + 1];
    strcpy(tempString,str);
    tempString[strlen(str)] = '\0';
    int command_flag = 0;
    int counter = 0,counter2 = 0;
    char* tempString2 = new char[255];
    char tmpWord[255];
    char printString[] = "print";
    char translateString[] = "translate";
    char eraseString[] = "erase";
    char createString[] = "create";
    char withinString[] = "within";
    char rectangleString[] = "rectangle";
    char lineString[] = "line";
    char circleString[] = "circle";
    char exitString[] = "exit";
    char saveString[] = "save";
    char closeString[] = "close";

    tempString2 = getSting(tempString,counter);
    counter += strlen(tempString2);
    strcpy(tmpWord,tempString2);
    if((strcmp(tmpWord,printString)) == 0)
    {
        if(tempString[counter] == '\0')
        {
            printFigures(file,testFile);
        }
        else
        {
            cout << "Greshna Komanda" << endl;
        }

    }
    else if((strcmp(tmpWord,translateString)) == 0)
    {
        translate(file,testFile,fileName,str);
    }
    else if((strcmp(tmpWord,createString)) == 0)
    {
        counter++;
        tempString2 = getSting(tempString,counter);
        counter += strlen(tempString2);
        strcpy(tmpWord,tempString2);
        if((strcmp(tmpWord,circleString)) == 0)
        {
            Circle c1;
            counter++;
            tempString2= getSting(tempString,counter);
            counter += strlen(tempString2);
            c1.set_xValue(tempString2);
            counter++;
            tempString2 = getSting(tempString,counter);
            counter += strlen(tempString2);
            c1.set_yValue(tempString2);
            counter++;
            tempString2 = getSting(tempString,counter);
            counter += strlen(tempString2);
            c1.set_radius(tempString2);
            counter++;
            tempString2 = getSting(tempString,counter);
            counter += strlen(tempString2);
            c1.set_color(tempString2);
            makeCircle(c1.get_xValue(),c1.get_yValue(),c1.get_radius(),c1.get_color(),file,testFile,fileName,1);
            testFile.close();
            testFile.open(TEST_FILE,std::fstream::in | std::fstream::out | std::fstream::app);
            wipeTestFile(fileName,file);
            changeFiles(testFile,file,fileName);
        }
        else if((strcmp(tmpWord,lineString)) == 0)
        {
            Line l1;
            counter++;
            tempString2= getSting(tempString,counter);
            counter += strlen(tempString2);
            l1.set_xValue(tempString2);
            counter++;
            tempString2 = getSting(tempString,counter);
            counter += strlen(tempString2);
            l1.set_yValue(tempString2);
            counter++;
            tempString2 = getSting(tempString,counter);
            counter += strlen(tempString2);
            l1.set_x1Value(tempString2);
            counter++;
            tempString2 = getSting(tempString,counter);
            counter += strlen(tempString2);
            l1.set_y1Value(tempString2);
            counter++;
            tempString2 = getSting(tempString,counter);
            counter += strlen(tempString2);
            l1.set_color(tempString2);
            makeLine(l1.get_xValue(),l1.get_yValue(),l1.get_x1Value(),l1.get_y1Value(),l1.get_color(),file,testFile,fileName,1);
            testFile.close();
            testFile.open(TEST_FILE,std::fstream::in | std::fstream::out | std::fstream::app);
            wipeTestFile(fileName,file);
            changeFiles(testFile,file,fileName);
        }
        else if((strcmp(tmpWord,rectangleString)) == 0)
        {
            Rectangle r1;
            counter++;
            tempString2= getSting(tempString,counter);
            counter += strlen(tempString2);
            r1.set_xValue(tempString2);
            counter++;
            tempString2 = getSting(tempString,counter);
            counter += strlen(tempString2);
            r1.set_yValue(tempString2);
            counter++;
            tempString2 = getSting(tempString,counter);
            counter += strlen(tempString2);
            r1.set_widht(tempString2);
            counter++;
            tempString2 = getSting(tempString,counter);
            counter += strlen(tempString2);
            r1.set_heigh(tempString2);
            counter++;
            tempString2 = getSting(tempString,counter);
            counter += strlen(tempString2);;
            r1.set_color(tempString2);
            makeRectangle(r1.get_xValue(),r1.get_yValue(),r1.get_widht(),r1.get_heigh(),r1.get_color(),file,testFile,fileName,1);
            testFile.close();
            testFile.open(TEST_FILE,std::fstream::in | std::fstream::out | std::fstream::app);
            wipeTestFile(fileName,file);
            changeFiles(testFile,file,fileName);
        }
        else
        {
            cout << "Greshna komanda" << endl;
        }
    }
    else if((strcmp(tmpWord,eraseString)) == 0)
    {
        counter++;
        tempString2 = getSting(tempString,counter);
        counter += strlen(tempString2);
        if(tempString[counter] == '\0')
        {
            eraseFigure(atoi(tempString2),file,testFile,fileName);
        }
        else
        {
            cout << "Greshni danni sled erase" << endl;
        }
    }
    else if((strcmp(tmpWord,withinString)) == 0)
    {

    }
    else if((strcmp(tmpWord,exitString)) == 0)
    {
        return 1;
    }
    else if((strcmp(tmpWord,saveString)) == 0)
    {
        return 2;
    }
    else if((strcmp(tmpWord,closeString)) == 0)
    {
        return 3;
    }
    else
    {
        cout << "Greshna komanda" << endl;
    }
    delete [] tempString;
}
void makeLine(char* x1Value,char* y1Value,char* x2Value,char* y2Value,char* colour,fstream &file, fstream &testFile,char* fileName,int choice)
{
    char begString[] = " <line";
    char endString[] = "/>";
    char space[] = " ";
    char quote[] = "\"";
    char x1[] = "x1=\"";
    char x2[] = "x2=\"";
    char y1[] = "y1=\"";
    char y2[] = "y2=\"";
    char fill[] = "fill=\"";
    char* newLine = new char[6*strlen(space) + strlen(begString) + strlen(endString) + 5*strlen(quote) + strlen(x1) + strlen(x2) + strlen(y1) + strlen(y2) + strlen(fill) + 100];
    strcpy(newLine,begString);
    strcat(newLine,space);
    strcat(newLine,x1);
    strcat(newLine,x1Value);
    strcat(newLine,quote);
    strcat(newLine,space);
    strcat(newLine,y1);
    strcat(newLine,y1Value);
    strcat(newLine,quote);
    strcat(newLine,space);
    strcat(newLine,x2);
    strcat(newLine,x2Value);
    strcat(newLine,quote);
    strcat(newLine,space);
    strcat(newLine,y2);
    strcat(newLine,y2Value);
    strcat(newLine,quote);
    strcat(newLine,space);
    strcat(newLine,fill);
    strcat(newLine,colour);
    strcat(newLine,quote);
    strcat(newLine,endString);
    char tmp[5];
    if(choice == 1)
    {
        while(file.get(tmp[0]))
        {
            if((tmp[4] == '<') && (tmp[3] == 's') && (tmp[2] == 'v') && (tmp[1] == 'g') && (tmp[0] == '>'))
            {
                testFile << tmp[0];
                testFile << endl;
                testFile << newLine;
            }
        else
        {
            testFile << tmp[0];
        }
        tmp[4] = tmp[3];
        tmp[3] = tmp[2];
        tmp[2] = tmp[1];
        tmp[1] = tmp[0];
        }
    }
    else if(choice == 2)
    {
        testFile << newLine << endl;
    }
    delete [] newLine;
}

void makeCircle(char* cxValue,char* cyValue,char* rValue,char* colour,fstream &file, fstream &testFile,char* fileName,int choice)
{
    char begString[] = " <circle";
    char endString[] = "/>";
    char space[] = " ";
    char quote[] = "\"";
    char cx[] = "cx=\"";
    char cy[] = "cy=\"";
    char r[] = "r=\"";
    char fill[] = "fill=\"";
    char* newLine = new char[5*strlen(space) + strlen(begString) + strlen(endString) + 4*strlen(quote) + strlen(cx) + strlen(cy) + strlen(r) + strlen(fill) + 100];
    strcpy(newLine,begString);
    strcat(newLine,space);
    strcat(newLine,cx);
    strcat(newLine,cxValue);
    strcat(newLine,quote);
    strcat(newLine,space);
    strcat(newLine,cy);
    strcat(newLine,cyValue);
    strcat(newLine,quote);
    strcat(newLine,space);
    strcat(newLine,r);
    strcat(newLine,rValue);
    strcat(newLine,quote);
    strcat(newLine,space);
    strcat(newLine,fill);
    strcat(newLine,colour);
    strcat(newLine,quote);
    strcat(newLine,endString);
    char tmp[5];
    if(choice == 1)
    {
        while(file.get(tmp[0]))
        {
            if((tmp[4] == '<') && (tmp[3] == 's') && (tmp[2] == 'v') && (tmp[1] == 'g') && (tmp[0] == '>'))
            {
                testFile << tmp[0];
                testFile << endl;
                testFile << newLine;
            }
            else
            {
                testFile << tmp[0];
            }
            tmp[4] = tmp[3];
            tmp[3] = tmp[2];
            tmp[2] = tmp[1];
            tmp[1] = tmp[0];
        }
    }
    else if(choice == 2)
    {
        testFile << newLine << endl;
    }
    delete [] newLine;
}

void makeRectangle(char* xValue,char* yValue,char* widthValue,char* heightValue,char* colour,fstream &file,fstream &testFile,char* fileName,int choice)
{
    char begString[] = " <rect";
    char endString[] = "/>";
    char space[] = " ";
    char quote[] = "\"";
    char x[] = "x=\"";
    char y[] = "y=\"";
    char width[] = "width=\"";
    char height[] = "height=\"";
    char fill[] = "fill=\"";
    char* newLine = new char[6*strlen(space) + strlen(begString) + strlen(endString) + 5*strlen(quote) + strlen(x) + strlen(y) + strlen(width) + strlen(height) + strlen(fill) + 100];
    strcpy(newLine,begString);
    strcat(newLine,space);
    strcat(newLine,x);
    strcat(newLine,xValue);
    strcat(newLine,quote);
    strcat(newLine,space);
    strcat(newLine,y);
    strcat(newLine,yValue);
    strcat(newLine,quote);
    strcat(newLine,space);
    strcat(newLine,width);
    strcat(newLine,widthValue);
    strcat(newLine,quote);
    strcat(newLine,space);
    strcat(newLine,height);
    strcat(newLine,heightValue);
    strcat(newLine,quote);
    strcat(newLine,space);
    strcat(newLine,fill);
    strcat(newLine,colour);
    strcat(newLine,quote);
    strcat(newLine,endString);
    char tmp[5];
    if(choice == 1)
    {
        while(file.get(tmp[0]))
        {
            if((tmp[4] == '<') && (tmp[3] == 's') && (tmp[2] == 'v') && (tmp[1] == 'g') && (tmp[0] == '>'))
            {
                testFile << tmp[0];
                testFile << endl;
                testFile << newLine;
            }
            else
            {
                testFile << tmp[0];
            }
        tmp[4] = tmp[3];
        tmp[3] = tmp[2];
        tmp[2] = tmp[1];
        tmp[1] = tmp[0];
        }
    }
    else if(choice == 2)
    {
        testFile << newLine << endl;
    }
    delete [] newLine;
}

char* getSting(char* str,int counter)
{
   char tempString[255];
   int counter2 = 0;
   while((str[counter] != '\0') && (str[counter] != ' '))
   {
      tempString[counter2] = str[counter];
      counter++;
      counter2++;
   }
  tempString[counter2] = '\0';
  return tempString;
}
void changeFiles(fstream &testFile, fstream &file,char* fileName)
{
    char tmp;
    while(testFile.get(tmp))
    {
        file << tmp;
    }
    wipeTestFile(TEST_FILE,testFile);
}
void printFigures(fstream &file,fstream &testFile)
{
    char tmp[5];
    char tmpArr[255];
    char line[255];
    int flag = 0;
    int i = 0;
    while(file.get(tmp[0]))
    {
    if((tmp[4] == '<') && (tmp[3] == 's') && (tmp[2] == 'v') && (tmp[1] == 'g') && (tmp[0] == '>'))
    {
        do
        {
            file.get(tmp[0]);
            do
            {
                file.get(tmp[0]);
                line[i] = tmp[0];
                i++;
            }while(tmp[0] != '>');
            line[i] = '\0';
            i = 0;
            if(strcmp(line,"</svg>") == 0)
            {
                flag = 1;
            }
            else
            {
                printLine(line,1,tmpArr);
            }
        }while(!(flag));
    }
    tmp[4] = tmp[3];
    tmp[3] = tmp[2];
    tmp[2] = tmp[1];
    tmp[1] = tmp[0];

}

}
void printLine(char* str,int func, char* returnArr)
{
    char tmp[255];
    char name[10];
    char rectSting[] = "rectangle";
    char circString[] = "circle";
    char lineString[] = "line";
    int i = 0;
    int k = 0;
    int cnt = 0;
    for(int j = 0;j<strlen(str);j++)
    {
        if(str[j] == 'r')
        {
            strcpy(name,rectSting);
            name[9] = '\0';
            break;
        }
        else if(str[j] == 'l')
        {
            strcpy(name,lineString);
            name[4] = '\0';
            break;
        }
        else if(str[j] =='c')
        {
            strcpy(name,circString);
            name[6] = '\0';
            break;
        }
    }
    strcpy(tmp,name);
    cnt = strlen(name);
    tmp[cnt] = ' ';
    cnt++;
    for(i = 0;i <strlen(str);i++)
    {
        if((str[i-2] == '=') && (str[i-1] == '"'))
        {
            do
            {
                tmp[cnt] = str[i];
                i++;
                cnt++;
            }while(str[i] != '"');
            tmp[cnt] = ' ';
            cnt++;
        }
    }
    tmp[cnt] = '\0';
    if(func == 1)
    {
        cout << tmp << endl;
    }
    else if(func == 2)
    {
        strcpy(returnArr,tmp);
    }
}
void eraseFigure(int lineNum,fstream &file,fstream &testFile,char* fileName)
{
    char tmp[255];
    char line[255];
    int flag = 0;
    int lineCounter = 0;
    int flagDeleted = 0;
    int i = 0;
    wipeTestFile(TEST_FILE,testFile);
    while(file.get(tmp[0]))
    {
        testFile << tmp[0];
        if((tmp[4] == '<') && (tmp[3] == 's') && (tmp[2] == 'v') && (tmp[1] == 'g') && (tmp[0] == '>'))
        {
            testFile << endl;
            do
            {
                file.get(tmp[0]);
                do
                {
                    file.get(tmp[0]);
                    line[i] = tmp[0];
                    i++;
                }while(tmp[0] != '>');
                line[i] = '\0';
                i = 0;
                if(strcmp(line,"</svg>") == 0)
                {
                    flag = 1;
                }
                else
                {
                    ++lineCounter;
                    if(!(lineCounter == lineNum))
                    {
                        testFile << line;
                        testFile << endl;
                    }
                    else
                    {
                        if(line[2] == 'c')
                        {
                            cout << "Erased Circle" << " " << lineNum << endl;
                        }
                        else if(line[2] == 'r')
                        {
                            cout << "Erased Rectangle" << " " << lineNum << endl;
                        }
                        else if(line[2] == 'l')
                        {
                            cout << "Erased Line" << " " << lineNum << endl;
                        }
                        flagDeleted = 1;
                    }
                }
            }while(!(flag));
    }
    tmp[4] = tmp[3];
    tmp[3] = tmp[2];
    tmp[2] = tmp[1];
    tmp[1] = tmp[0];
}
    if(!flagDeleted)
    {
        cout << "There is no figure number " << " " <<lineNum << endl;
    }
    testFile << "</svg>";
    testFile.close();
    testFile.open(TEST_FILE,std::fstream::in | std::fstream::out | std::fstream::app);
    wipeTestFile(fileName,file);
    file.close();
    file.open(fileName,std::fstream::in | std::fstream::out | std::fstream::app);
    changeFiles(testFile,file,fileName);
    wipeTestFile(TEST_FILE,testFile);
}
void openFile(fstream &file,char* name)
{
    file.open(name,std::fstream::in | std::fstream::out | std::fstream::app);
    if(file.is_open())
    {
        cout <<"File " << name << " opened successful!" << endl;
    }
    else
    {
        cout <<"Error opening " << name << " !" << endl;
    }
}
void translate(fstream &file,fstream &testFile,char* fileName,char* str)
{
    int flag = 0,flagSymbol = 0,breakFlag = 0;
    int j = 0;
    int i = 0;
    int cnt = 0;
    char line[256],tmp[5],parsedLine[255];
    int lineCounter=0;
    char figNumber[20] = "0";
    char horizontal[100];
    char vertical[100];
    wipeTestFile(TEST_FILE,testFile);
    for(j = strlen("translate")+1;j < strlen(str)-1;j++)
    {
        if((str[j] > '0') && (str[j] < '9'))
        {
            do
            {
                figNumber[cnt] = str[j];
                cnt++;
                j++;
            }while((str[j] >= '0') && (str[j] <= '9'));
            figNumber[cnt] = '\0';
        }
        else if(str[j] == 'v')
        {
            do
            {
                if((flagSymbol) && !((str[j] >= '0') && (str[j] <= '9')))
                {
                    breakFlag = 1;
                    vertical[cnt] = '\0';
                }
                if((flagSymbol) && !(breakFlag))
                {
                    vertical[cnt] = str[j];
                    cnt++;
                }
                if(str[j] == '=')
                {
                    flagSymbol = 1;
                }
                if(!breakFlag)
                {
                    j++;
                }
            }while(!breakFlag);
        }
        else if(str[j] == 'h')
        {
            do
            {
                if((flagSymbol) && (!((str[j] >= '0') && (str[j] <= '9'))))
                {
                    breakFlag = 1;
                    horizontal[cnt] = '\0';
                }
                if((flagSymbol) && !(breakFlag))
                {
                    horizontal[cnt] = str[j];
                    cnt++;
                }
                if(str[j] == '=')
                {
                    flagSymbol = 1;
                }
                if(!breakFlag)
                {
                    j++;
                }
            }while(!breakFlag);
        }
        breakFlag = 0;
        flagSymbol = 0;
        cnt = 0;
    }
    while(file.get(tmp[0]))
    {
        if((tmp[4] == '<') && (tmp[3] == 's') && (tmp[2] == 'v') && (tmp[1] == 'g') && (tmp[0] == '>'))
        {
            testFile << tmp[0] << endl;
            do
            {
                file.get(tmp[0]);
                do
                {
                    file.get(tmp[0]);
                    line[i] = tmp[0];
                    i++;
                }while(tmp[0] != '>');
                line[i] = '\0';
                i = 0;
                ++lineCounter;
                if((atoi(figNumber) != 0))
                {
                    if(atoi(figNumber) == lineCounter)
                    {
                        printLine(line,2,parsedLine);
                        translateLine(parsedLine,file,testFile,fileName,horizontal,vertical);
                    }
                    else
                    {
						testFile << line << endl;
                    }
                }
                else
                {
					printLine(line,2,parsedLine);
                    translateLine(parsedLine,file,testFile,fileName,horizontal,vertical);
                }
                if(strcmp(line,"</svg>") == 0)
                {
                    flag = 1;
                }
                else
                {

                }
            }while(!(flag));
     }
     else
     {
        testFile << tmp[0];
     }
    tmp[4] = tmp[3];
    tmp[3] = tmp[2];
    tmp[2] = tmp[1];
    tmp[1] = tmp[0];
  }
    testFile.close();
    testFile.open(TEST_FILE,std::fstream::in | std::fstream::out | std::fstream::app);
    wipeTestFile(fileName,file);
    changeFiles(testFile,file,fileName);
    file << "</svg>";
}
void translateLine(char* str,fstream &file,fstream &testFile,char* fileName,char* horizontal,char* vertical)
{
    int i,cnt = 0,numberOfArguments = 1;
    char x[20],y[20],x1[20],y1[20],radius[20],color[10];
    if(str[0] == 'r')
    {
        Rectangle r1;
        for(i = strlen("rectangle")+1;i < strlen(str);i++,numberOfArguments++)
        {
            do
            {
                if(numberOfArguments == 1)
                {
                    x[cnt] = str[i];
                    i++;
                    cnt++;
                }
                else if(numberOfArguments == 2)
                {
                    y[cnt] = str[i];
                    i++;
                    cnt++;
                }
                else if(numberOfArguments == 3)
                {
                    x1[cnt] = str[i];
                    i++;
                    cnt++;
                }
                else if(numberOfArguments == 4)
                {
                    y1[cnt] = str[i];
                    i++;
                    cnt++;
                }
                else
                {
                    color[cnt] = str[i];
                    i++;
                    cnt++;
                }
            }while(str[i] != ' ');
            if(numberOfArguments == 1)
            {
                x[cnt] = '\0';
            }
            else if(numberOfArguments == 2)
            {
                y[cnt] = '\0';
            }
            else if(numberOfArguments == 3)
            {
                x1[cnt] = '\0';
            }
            else if(numberOfArguments == 4)
            {
                y1[cnt] = '\0';
            }
            else
            {
                color[cnt] = '\0';
            }
            cnt = 0;
        }
        r1.set_xValue(horizontal);
        r1.set_yValue(vertical);
        r1.set_widht(x1);
        r1.set_heigh(y1);
        r1.set_color(color);
        makeRectangle(r1.get_xValue(),r1.get_yValue(),r1.get_widht(),r1.get_heigh(),r1.get_color(),file,testFile,fileName,2);
    }
    else if(str[0] == 'c')
    {
        Circle c1;
        for(i = strlen("circle")+1;i < strlen(str);i++,numberOfArguments++)
        {
            do
            {
                if(numberOfArguments == 1)
                {
                    x[cnt] = str[i];
                    i++;
                    cnt++;
                }
                else if(numberOfArguments == 2)
                {
                    y[cnt] = str[i];
                    i++;
                    cnt++;
                }
                else if(numberOfArguments == 3)
                {
                    x1[cnt] = str[i];
                    i++;
                    cnt++;
                }
                else
                {
                    color[cnt] = str[i];
                    i++;
                    cnt++;
                }
            }while(str[i] != ' ');
            if(numberOfArguments == 1)
            {
                x[cnt] = '\0';
            }
            else if(numberOfArguments == 2)
            {
                y[cnt] = '\0';
            }
            else if(numberOfArguments == 3)
            {
                x1[cnt] = '\0';
            }
            else
            {
                color[cnt] = '\0';
            }
            cnt = 0;
        }
        c1.set_xValue(horizontal);
        c1.set_yValue(vertical);
		c1.set_radius(x1);
        c1.set_color(color);
        makeCircle(c1.get_xValue(),c1.get_yValue(),c1.get_radius(),c1.get_color(),file,testFile,fileName,2);
    }
    else if(str[0] == 'l')
    {
        Line l1;
        for(i = strlen("line")+1;i < strlen(str);i++,numberOfArguments++)
        {
            do
            {
                if(numberOfArguments == 1)
                {
                    x[cnt] = str[i];
                    i++;
                    cnt++;
                }
                else if(numberOfArguments == 2)
                {
                    y[cnt] = str[i];
                    i++;
                    cnt++;
                }
                else if(numberOfArguments == 3)
                {
                    x1[cnt] = str[i];
                    i++;
                    cnt++;
                }
                else if(numberOfArguments == 4)
                {
                    y1[cnt] = str[i];
                    i++;
                    cnt++;
                }
                else
                {
                    color[cnt] = str[i];
                    i++;
                    cnt++;
                }
            }while(str[i] != ' ');
            if(numberOfArguments == 1)
            {
                x[cnt] = '\0';
            }
            else if(numberOfArguments == 2)
            {
                y[cnt] = '\0';
            }
            else if(numberOfArguments == 3)
            {
                x1[cnt] = '\0';
            }
            else if(numberOfArguments == 4)
            {
                y1[cnt] = '\0';
            }
            else
            {
                color[cnt] = '\0';
            }
            cnt = 0;
        }
        l1.set_xValue(horizontal);
        l1.set_yValue(vertical);
        l1.set_x1Value(x1);
        l1.set_y1Value(y1);
        l1.set_color(color);
        makeLine(l1.get_xValue(),l1.get_yValue(),l1.get_x1Value(),l1.get_y1Value(),l1.get_color(),file,testFile,fileName,2);
    }
}
