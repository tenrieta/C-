#include <iostream>
#include <cstring>
using namespace std;

char* reversed(char* str, char* newStr, int i, int  j)
{
    if(i<0)
    {
        newStr[j] = '\0';
        return newStr;
    }
    else
    {
        if(j==0)
        {
            if(newStr!=NULL)
                delete[] newStr;
            newStr = new char[strlen(str)+1];
        }
        newStr[j] = str[i];
        return reversed(str, newStr, i-1, j+1);
    }
}


char* convertString(char* str, int i, char* tmpStr, int j, char* newStr, int rightBrackets, int leftBrackets, int num, int deg, bool flag)
{
    if(i<0)
    {
        int len = strlen(newStr);
        return reversed(newStr, "", len-1, 0);
    }
    else if(str[i] == ')')
    {
        if(rightBrackets == 0)//zadelqme pamet v nachaloto
        {
            if(tmpStr!=NULL)
                delete[] tmpStr;
            tmpStr = new char[i+1];
            tmpStr[0] = '\0';
        }
        convertString(str, i-1, tmpStr, j, newStr, rightBrackets+1, leftBrackets, num, deg, flag);
    }
    else if(str[i] == '(')
    {
        convertString(str, i-1, tmpStr, j, newStr, rightBrackets, leftBrackets+1, num, deg, flag);
    }
    else if(str[i] >= 'A' && str[i] <= 'Z')
    {
        if(rightBrackets > leftBrackets)//zapisvame bukvite v tmpStr
        {
            tmpStr[j] = str[i];
            tmpStr[j+1] = '\0';
            convertString(str, i-1, tmpStr, j+1, newStr, rightBrackets, leftBrackets, num, deg, flag);
        }
        else if(rightBrackets == leftBrackets)// => zatvarqne na skobite
        {
            if(i == strlen(str)-1) // ako i e duljinata na stringa i e bukva to zadelqme pamet sega
            {
                if(tmpStr!=NULL)
                    delete[] tmpStr;
                tmpStr = new char[i+1];
                tmpStr[0] = '\0';
            }
            tmpStr[j] = str[i];
            tmpStr[j+1] = '\0';
            char* tmp = new char[strlen(newStr)+1];
            strcpy(tmp, newStr);
            delete[] newStr;
            newStr = new char[strlen(tmp)+strlen(tmpStr)+1];
            strcpy(newStr, tmp);
            strcat(newStr, tmpStr); // ako imame obraboten tmpStr konkatenirame
            delete[] tmp;
            if(tmpStr!=NULL)
                delete[] tmpStr;
            tmpStr = new char[i+1];
            tmpStr[0] = '\0';
            convertString(str, i-1, tmpStr, 0, newStr, rightBrackets, leftBrackets, num, deg, flag);
            //delete[] tmpStr;
        }
    }
    else if(str[i] >= '0' && str[i] <= '9')
    {
        if((str[i-1] >= '0' && str[i-1] <= '9') && i!=0) // preobrazuvame chisloto v int
        {
            num += (str[i] - '0') * deg;
            convertString(str, i-1, tmpStr, j, newStr, rightBrackets, leftBrackets, num, deg*10, flag);
        }
        else if(flag)// preobrazuvame chisloto v int
        {
            num += (str[i] - '0') * deg;
            convertString(str, i, tmpStr, j, newStr, rightBrackets, leftBrackets, num, deg*10, false);
        }
        else if(num>1)
        {
            char* tmp;
            if(rightBrackets == leftBrackets) // ako skobite sa zatvoreni, concatenirame na noviq string tmpStr
            {
                tmp = new char[strlen(newStr)+1];
                strcpy(tmp, newStr);
                delete[] newStr;
                newStr = new char[strlen(tmp) + strlen(tmpStr)+1];
                newStr[0] = '\0';
                strcpy(newStr, tmp);
                strcat(newStr, tmpStr);
            }
            else //ako skobite ne sa zatvoreni concat na tmpStr sushtiq tmpStr
            {//2(B3(C))A2(K)
               tmp = new char[strlen(tmpStr)+1];
               strcpy(tmp, tmpStr);
               delete[] tmpStr;
               tmpStr = new char[strlen(tmp)*2+1];
               tmpStr[0] = '\0';
               strcpy(tmpStr,tmp);
               strcat(tmpStr,tmp);
               j++;
               tmpStr[j] = '\0';
            }
            delete[] tmp;
            convertString(str, i, tmpStr, j, newStr, rightBrackets, leftBrackets, num-1, 1, flag);
        }
        else //num<=1
        {
            char* tmp = new char[strlen(newStr)+1];
            strcpy(tmp, newStr);
            delete[] newStr;
            newStr = new char[strlen(tmp)+strlen(tmpStr)+1];
            strcpy(newStr, tmp);
            if(rightBrackets>leftBrackets)//ako skobite ne sa zatvoreni num ot 1 stava 0 za da moje da se izpolzva pak za sluchai kato 2(B1(C))
            {
                j = strlen(tmpStr);
                convertString(str, i-1, tmpStr, j, newStr, rightBrackets, leftBrackets, 0, 1, true);
            }
            else //ako skobite sa zatvoreni, concatenirame polucheniq tmpStr kum newStr iztrivame tmpStr
            {
                strcat(newStr, tmpStr);
                delete[] tmp;
                if(tmpStr!=NULL)
                    delete[] tmpStr;
                tmpStr = new char[i+1];
                tmpStr[0] = '\0';
                j = 0;
                convertString(str, i-1, tmpStr, j, newStr, 0, 0, 0, 1, true);
            }
        }
    }
}

int main()
{
    char* str = new char[1000];
    cin.getline(str, 1000);
    int len = strlen(str);
    char* newStr = new char[len+1];
    newStr[0] = '\0';
    cout << convertString(str, len-1, "", 0, newStr, 0, 0, 0, 1, true) << endl;
    return 0;
}
