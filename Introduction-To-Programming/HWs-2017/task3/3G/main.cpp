#include <iostream>
using namespace std;

int strlen(const char* str);
int strcmp(const char* str1, const char* str2);

int main()
{
    int cntWords, rows, cols, len;
    cin>>cntWords;
    char word[cntWords][41];
    for(int i=0; i<cntWords ; i++)
    {
        do
        {
            cin>>word[i];
            len = strlen(word[i]);
        }while(len<2 && len>40);
    }
    do
    {
        cin>>rows>>cols;
    }while(rows>99 && cols>99);

    char crossWord[rows][cols];
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            do
            {
                cin>>crossWord[i][j];
            }while(!((crossWord[i][j]>='a' && crossWord[i][j]<='z') || crossWord[i][j] == '*'));
        }
    }
    char tmpStr[41];
    int k = 0, allWords = 0;
    int existed = 0;
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            if(crossWord[i][j]=='*')
            {
                if(k>1)
                {
                    allWords++;
                    for(int s=0; s<cntWords; s++)
                    {
                        if(strcmp(tmpStr, word[s])==0)
                        {
                            existed++;
                            break;
                        }
                    }
                }
                k = 0;
            }
            else
            {
                tmpStr[k] = crossWord[i][j];
                tmpStr[k+1] = '\0';
                k++;
            }
        }
        if(k>1)
        {
            allWords++;
            for(int s=0; s<cntWords; s++)
            {
                if(strcmp(tmpStr, word[s])==0)
                {
                    existed++;
                    break;
                }
            }
        }
        k = 0;
    }
    for(int i=0; i<cols; i++)
    {
        for(int j=0; j<rows; j++)
        {
            if(crossWord[j][i]=='*')
            {
                if(k>1)
                {
                    allWords++;
                    for(int s=0; s<cntWords; s++)
                    {
                        if(strcmp(tmpStr, word[s])==0)
                        {
                            existed++;
                            break;
                        }
                    }
                }
                k = 0;
            }
            else
            {
                tmpStr[k] = crossWord[j][i];
                tmpStr[k+1] = '\0';
                k++;
            }
        }
        if(k>1)
        {
            allWords++;
            for(int s=0; s<cntWords; s++)
            {
                if(strcmp(tmpStr, word[s])==0)
                {
                    existed++;
                    break;
                }
            }
        }
        k = 0;
    }
    if(allWords == existed)
        cout<< "true" <<endl;
    else
        cout<< "false" <<endl;
    return 0;
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

int strcmp(const char* str1, const char* str2)
{
    int i = 0, j = 0;
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    if(len1 == len2)
    {
        while(str1[i]!='\0')
        {
            if(str1[i] == str2[j])
            {
                i++;
                j++;
            }
            else
            {
                if(str1[i]>str2[j])
                    return -1;
                return 1;
            }
        }
    }
    if(i == len1)
        return 0;
    if(len1>len2)
        return -1;
    return 1;
}
