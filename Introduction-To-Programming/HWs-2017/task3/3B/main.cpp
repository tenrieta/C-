#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <ctime>
using namespace std;

char* findLetter(const char* word, char letter, char* newWord, int& cntGuessed)
{
    int i = 0;
    char* tmpWord = new char[strlen(newWord)+1];
    strcpy(tmpWord,newWord);
    while(word[i]!='\0')
    {
        if(word[i] == letter)
        {
            tmpWord[i*2] = letter;
            cntGuessed++;
        }
        i++;
    }
return tmpWord;
}

bool checkHistory(char* history, char letter)
{
    int i = 0;
    int len = strlen(history);
    while(i<len)
    {
        if(history[i] == letter)
        {
            return false;
        }
        else
        {
            i += 2;
        }
    }
    return true;
}

bool guessWordFromAList(const char** words, char* newWord, int randomIdxWord, int cntWords)
{
    int randNum = rand()%cntWords ;
    int lenRandomWord = strlen(words[randNum]);
    int lenNewWord = strlen(words[randomIdxWord]);
    for(int i = 0; i < cntWords; i++)
    {
        cout << (i+1) << ") " << words[i] << " ";
    }
    cout << endl;
    while(lenNewWord != lenRandomWord)
    {
        srand(time(NULL));
        randNum = rand()%cntWords;
        lenRandomWord = strlen(words[randNum]);
    }
    cout << "Choose a number: "<< (randNum+1) << endl;
    cout << "You chose the word: " << words[randNum] <<endl;
    if(randNum == randomIdxWord)
    {
        cout << "Yes! You guessed right." << endl;
        return true;
    }
    else
        cout << "Sorry. You guessed wrong. You must guess letters now." << endl;
        return false;
}

int main()
{
    const char* words[] = { "apple", "orange", "month", "vehicle" , "banana", "pizza", "gloves", "stars","actions", "cloud"};
    const unsigned int wordsCount = 10;
    const unsigned int maxMistakes = 16;
    srand(time(NULL));
    int randomIdxWord = rand()%wordsCount;
    unsigned cntMistakes = 0;
    unsigned int lenWord = strlen(words[randomIdxWord]);
    char* newWord = new char[lenWord*2+1];
    char* tmpWord = new char[lenWord*2+1];
    char* history = new char[maxMistakes + lenWord+1];
    int h = 0, idx = 0, cntGuessed = 0;
    char letter;
    int randomNumLetter;
    while(idx!=lenWord*2-2)
    {
        newWord[idx] = '_';
        newWord[idx+1] = ' ';
        idx+=2;
    }
    newWord[idx] = '_';
    newWord[idx+1] = '\0';
    cout<< "Your word is: " << newWord << endl;
    cout << "Guess which is your word from the list: " << endl;
    bool flag = guessWordFromAList(words, newWord, randomIdxWord, wordsCount);
    if(flag)
    {
        cout << "You won! ^_^" <<endl;
        return 0;
    }
    cout<<endl;
    cout << "Guess the word (max " << maxMistakes << " mistakes):" << endl << endl;
    while((cntMistakes!=maxMistakes) && (cntGuessed!= lenWord))
    {
        cout << "[" << cntMistakes << "/" << maxMistakes << "] " << newWord << " History: ";
        if(h != 0)
            cout << history;
        cout << endl;
        //cout << "Choose a letter: ";
        //cin >> letter;
        cout << "The chosen letter is: ";
        randomNumLetter = rand()%26+1;
        letter = randomNumLetter + 96;
        while(!checkHistory(history, letter))
        {
             randomNumLetter = rand()%26+1;
             letter = randomNumLetter + 96;
        }
        cout << letter << endl;
        if(h!=0)
        {
            history[h] = ' ';
            history[h+1] = letter;
            history[h+2] = '\0';
            h += 2;
        }
        else
        {
            history[h] = letter;
            history[h+1] = '\0';
            h++;
        }
        strcpy(tmpWord, findLetter(words[randomIdxWord],letter,newWord, cntGuessed));
        //cout<<tmpWord<<endl;
        if(strcmp(newWord,tmpWord)==0)
        {
            cout << "No such letter" << endl << endl;
            cntMistakes++;
        }
        else
        {
            strcpy(newWord, tmpWord);
            cout << "OK" << endl << endl;
        }
    }
    cout << "[" << cntMistakes << "/" << maxMistakes << "] " << newWord << " History: " << history << endl;
    if(cntMistakes == maxMistakes)
        cout << "Game over x_x" << endl;
    else
        cout << "You won! ^_^" <<endl;

    return 0;
}
