#include <iostream>
#include <stdlib.h>
//#include <ctime>
using namespace std;

void cyrillicString(const char* str);
char* strcpy(char* newStr, const char* str);
int strlen(const char* str);
const char* strstr(const char* str, const char* what);
char* strcat(char* str1, const char* str2);

int main()
{
	int headings;
	cout<<"Enter number of headings: ";
	cin>>headings;
	const char* exclamations[] = {"Shok", "Skandal", "Nechuvano"};
	const unsigned int cntExclamations = 3;
	const char* objects[] = {"prase(da/da)", "vila(da/ne)", "kola(da/ne)", "kotka(da/da)", "jivotno(da/da)", "starec(da/da)", "domat(da/ne)", "kuche(da/da)"};
	const unsigned int cntObjects = 8;
	const char* actions[] = {"podskacha pred", "gleda", "se smee na", "se qdosva na", "pee na", "gotvi za"};
	const unsigned int cntActions = 5;
	unsigned int idxE = 0, idxO = 0, idxA = 0, idxOS = 0, idxSign = 0;
	unsigned int len = 0;
	char* title = NULL;
	int lenTitle = 0;
	//srand(time(NULL));
	while(headings!=0)
    {

        idxE = rand()%cntExclamations;
        idxO = rand()%cntObjects;
        while(!strstr(objects[idxO],"(da/da)"))
        {
            idxO = rand()%cntObjects;
        }
        idxA = rand()%cntActions;
        idxOS = rand()%cntObjects;
        while(!strstr(objects[idxOS],"(da/ne)"))
        {
            idxOS = rand()%cntObjects;
        }
        idxSign = rand()%10 + 3;
        lenTitle = strlen(exclamations[idxE]) + strlen(objects[idxO]) + strlen(actions[idxA]) + strlen(objects[idxOS]) + idxSign - 7 + 3 + 1; // -7(da/ne) + 3space +1 za 0
        if(title!=NULL)
          delete[] title;
        title = new char[lenTitle];
        title[0] = '\0';
        strcpy(title, exclamations[idxE]);
        len = strlen(title);
        while(idxSign != 0)
        {
            title[len] = '!';
            len++;
            idxSign--;
        }
        title[len] = ' ';
        title[len+1] = '\0';
        strcat(title, objects[idxO]);
        title[len+1] = title[len+1] - 32;
        len = strlen(title);
        title[len-7] = ' ';
        title[len-6] = '\0';
        strcat(title, actions[idxA]);
        len = strlen(title);
        title[len] = ' ';
        title[len+1] = '\0';
        strcat(title, objects[idxOS]);
        len = strlen(title) - 7;
        title[len] = '\0';
        cyrillicString(title);
        title[0] = '\0';
        headings--;
    }
    delete[] title;
    return 0;
}
void cyrillicString(const char* str)
{
    int i = 0, j = 0;
    int len = strlen(str)+1;
    char* newStr = new char[len];
    newStr[0] = '\0';
    while(str[i]!='\0')
    {
            if(str[i] == 'c')
            {
                if(str[i+1]=='h' && i!=len-1)
                {
                    newStr[j] = 231;
                    i++;
                }
                else
                {
                    newStr[j] = 230;
                }
            }
            else if(str[i] == 's')
            {
                if(str[i+1]=='h' && i!=len-1)
                {
                    if(str[i+2]=='t' && i!=len-2)
                    {
                        newStr[j] = 233;
                        i++;
                    }
                    else
                        newStr[j] = 232;
                    i++;
                }
                else
                {
                    newStr[j] = 225;
                }
            }
            else if(str[i] == 'i')
            {
                if(str[i+1] == 'u' && i!=len-1)
                {
                    newStr[j] = 238;
                    i++;
                }
                else if(str[i+1] == 'a' && i!= len-1)
                {
                    newStr[j] = 239;
                    i++;
                }
                else
                {
                    newStr[j] = 168;
                }
            }
            else if(str[i]=='a' || str[i] =='b' || str[i]=='A' || str[i] =='B' || (str[i]>='k' && str[i]<='p'))
            {
                newStr[j] = str[i] + 63;
            }
            else if(str[i]>='r' && str[i]<='u')
            {
                 newStr[j] = str[i] + 110;
            }
            else if(str[i]=='d' || str[i] =='e' || str[i]=='D' || str[i] =='E')
            {
                newStr[j] = str[i] + 64;
            }
            else if(str[i]=='v' || str[i] =='w')
            {
                newStr[j] = 162;
            }
            else if(str[i] == 'f')
            {
                newStr[j] = 228;
            }
            else if(str[i] == 'g')
            {
                newStr[j] = 163;
            }
            else if(str[i] == 'h')
            {
                newStr[j] = 229;
            }
            else if(str[i] == 'j')
            {
                newStr[j] = 166;
            }
            else if(str[i] == 'q')
            {
                newStr[j] = 239;
            }
            else if(str[i] == 'x')
            {
                newStr[j] = 170;
                j++;
                newStr[j] = 225;
            }
            else if(str[i] == 'y')
            {
                newStr[j] = 168;
            }
            else if(str[i] == 'z')
            {
                newStr[j] = 167;
            }
            else if(str[i] == 'C')
            {
                if((str[i+1]=='h' || str[i+1] == 'H')&& i!=len-1)
                {
                    newStr[j] = 151;
                    i++;
                }
                else
                {
                    newStr[j] = 150;
                }
            }
            else if(str[i] == 'S')
            {
                if((str[i+1]=='h' || str[i+1] == 'H') && i!=len-1)
                {
                    if((str[i+2]=='t' || str[i+2] == 'T') && i!=len-2)
                    {
                        newStr[j] = 153;
                        i++;
                    }
                    else
                        newStr[j] = 152;
                    i++;
                }
                else
                {
                    newStr[j] = 145;
                }
            }
            else if(str[i] == 'I')
            {
                if((str[i+1] == 'u' || str[i+1] == 'U') && i!=len-1)
                {
                    newStr[j] = 158;
                    i++;
                }
                else if((str[i+1] == 'a' || str[i+1] == 'A') && i!= len-1)
                {
                    newStr[j] = 159;
                    i++;
                }
                else
                {
                    newStr[j] = 136;
                }
            }
            else if(str[i]>='K' && str[i]<='P')
            {
                newStr[j] = str[i] + 63;
            }
            else if(str[i]>='R' && str[i]<='U')
            {
                 newStr[j] = str[i] + 62;
            }
            else if(str[i]=='V' || str[i] =='W')
            {
                newStr[j] = 130;
            }
            else if(str[i] == 'F')
            {
                newStr[j] = 148;
            }
            else if(str[i] == 'G')
            {
                newStr[j] = 131;
            }
            else if(str[i] == 'H')
            {
                newStr[j] = 149;
            }
            else if(str[i] == 'J')
            {
                newStr[j] = 134;
            }
            else if(str[i] == 'Q')
            {
                newStr[j] = 159;
            }
            else if(str[i] == 'X')
            {
                newStr[j] = 138;
                j++;
                newStr[j] = 145;
            }
            else if(str[i] == 'Y')
            {
                newStr[j] = 136;
            }
            else if(str[i] == 'Z')
            {
                newStr[j] = 135;
            }
            else
            {
                newStr[j] = str[i];
            }
        j++;
        i++;
    }
    newStr[j] = '\0';
    cout<<newStr<<endl;
    return;
}

char* strcpy(char* newStr, const char* str)
{
    int i = 0 ;
    while(str[i] != '\0')
    {
        newStr[i] = str[i];
        i++;
    }
    newStr[i] = '\0';
    return newStr;
}

int strlen(const char* str)
{
    int i = 0;
    while(str[i] != '\0')
    {
        i++;
    }
    return i;
}

const char* strstr(const char* str, const char* what)
{
    int i = 0, j = 0;
    int lenWhat = strlen(what);
    while(str[i]!=0)
    {
        if(str[i] == what[0])
        {
            while(j != lenWhat)
            {
                if(str[i] == what[j])
                {
                     i++;
                     j++;
                }
                else
                {
                    i = i- j;
                    break;
                }
            }
            if(j == lenWhat)
                return str;
        }
        i++;
    }
    return  NULL;
}

char* strcat(char* str1, const char* str2)
{
    int i = 0, j = 0;
    while(str1[i] != '\0')
    {
         i++;
    }
    while(str2[j]!= '\0')
    {
        str1[i] = str2[j];
        i++;
        j++;
    }
    str1[i] = '\0';
    return str1;
}
