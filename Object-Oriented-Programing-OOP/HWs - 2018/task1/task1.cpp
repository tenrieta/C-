#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct Players
{
    int id;
    char name[127];

};

struct Decks
{
    int player_id;
    int card_id[60];
    char colour [6];
};

struct Cards
{
    char colour[6];
    char name[63];
    int id;
};
void OpenFiles()
{
    ofstream myfile("players.bin",ios::binary | ios::app );
    ofstream myfile2("cards.bin",ios::binary | ios::app );
    ofstream myfile3("decks.bin", ios::binary | ios::app );
    myfile.close();
    myfile2.close();
    myfile3.close();
}
int CheckFile(char* fileName,int num) //Функция която проверява дали файла  е празен и ако не е връща поредния индекс
{
    int structureSize = 0;
    Players p1;
    Cards c1;
    if(num == 1)
    {
        structureSize = sizeof(p1);
    }
    else if(num == 2)
    {
        structureSize = sizeof(c1);
    }
    int length;
    ifstream myfile(fileName,ios::ate);
    if(myfile.tellg() == 0)
    {
        length=0;
    }
    myfile.close();
    ifstream myfile2(fileName,ios::binary);
    if(length == 0)
    {
        return 0;
    }
    else
    {
        myfile2.seekg((-structureSize),myfile2.end);
        if(num == 1)
        {
            myfile2.read((char*)&p1, structureSize);
            return p1.id+1;
        }
        else
        {
            myfile2.read((char*)&c1, structureSize);
            return c1.id+1  ;
        }
    }
}

void CreatePlayers(Players player, int id)
{
    char name[127];
    cin.getline(name,127);
    cin.sync();
    player.id=id;
    for(unsigned int i=0; i<=strlen(name); i++)
    {
        player.name[i]= name[i];
    }
    ofstream file_players("players.bin", ios::binary | ios::app);
    file_players.write((char*)(&player),sizeof(Players));
    //file_players << player.id << " ";
    //file_players << player.name;
    //file_players << endl;
    file_players.close();
}

void CreateCards (Cards card, int id)
{
    char buff[100];
    char colour[6];
    char name[63];
    card.id = id;
    cin.getline(buff,100);
    cin.sync();
    int i = 0,p = 0;
    if(((buff[0] == 'b') && (buff[1] == 'l') && (buff[2] == 'a') && (buff[3] == 'c') && (buff[4] == 'k') && (buff[5] == ' ')) || ((buff[0] == 'B') && (buff[1] == 'l') && (buff[2] == 'a') && (buff[3] == 'c') && (buff[4] == 'k') && (buff[5] == ' ')))
    {
        colour[0] = 'b';
        colour[1] = 'l';
        colour[2] = 'a';
        colour[3] = 'c';
        colour[4] = 'k';
        colour[5] = '\0';
        i = 6;
        while(buff[i] != '\0')
        {
            name[p] = buff[i];
            i++;
            p++;
        }
        name[p] = '\0';
    }
    else if(((buff[0] == 'b') && (buff[1] == 'l') && (buff[2] == 'u') && (buff[3] == 'e') && (buff[4] == ' ')) || ((buff[0] == 'B') && (buff[1] == 'l') && (buff[2] == 'u') && (buff[3] == 'e') && (buff[4] == ' ')))
    {
        colour[0] = 'b';
        colour[1] = 'l';
        colour[2] = 'u';
        colour[3] = 'e';
        colour[4] = '\0';
        i = 5;
        while(buff[i] != '\0')
        {
            name[p] = buff[i];
            i++;
            p++;
        }
        name[p] = '\0';
    }
    else if(((buff[0] == 'w') && (buff[1] == 'h') && (buff[2] == 'i') && (buff[3] == 't') && (buff[4] == 'e') && (buff[5] == ' ')) || ((buff[0] == 'W') && (buff[1] == 'h') && (buff[2] == 'i') && (buff[3] == 't') && (buff[4] == 'e') && (buff[5] == ' ')))
    {
        colour[0] = 'w';
        colour[1] = 'h';
        colour[2] = 'i';
        colour[3] = 't';
        colour[4] = 'e';
        colour[5] = '\0';
        i = 6;
        while(buff[i] != '\0')
        {
            name[p] = buff[i];
            i++;
            p++;
        }
        name[p] = '\0';
    }
    else if(((buff[0] == 'g') && (buff[1] == 'r') && (buff[2] == 'e') && (buff[3] == 'e') && (buff[4] == 'n') && (buff[5] == ' ')) || ((buff[0] == 'G') && (buff[1] == 'r') && (buff[2] == 'e') && (buff[3] == 'e') && (buff[4] == 'n') && (buff[5] == ' ')))
    {
        colour[0] = 'g';
        colour[1] = 'r';
        colour[2] = 'e';
        colour[3] = 'e';
        colour[4] = 'n';
        colour[5] = '\0';
        i = 6;
        while(buff[i] != '\0')
        {
            name[p] = buff[i];
            i++;
            p++;
        }
        name[p] = '\0';
    }
    else if(((buff[0] == 'r') && (buff[1] == 'e') && (buff[2] == 'd') && (buff[3] == ' ')) || ((buff[0] == 'R') && (buff[1] == 'e') && (buff[2] == 'd') && (buff[3] == ' ')))
    {
        colour[0] = 'r';
        colour[1] = 'e';
        colour[2] = 'd';
        colour[3] = '\0';
        i = 4;
        while(buff[i] != '\0')
        {
            name[p] = buff[i];
            i++;
            p++;
        }
        name[p] = '\0';
    }
    else
    {
        cout<<"Greshen cvqt, vuvedete komandata na novo" << endl;
        return;
    }
    for(unsigned int i = 0; i <= strlen(colour); i++)
    {
        card.colour[i] = colour[i];
    }

    for(unsigned int j = 0; j <= strlen(name); j++)
        {
            card.name[j] = name[j];
        }
    ofstream file_cards("cards.bin", ios::binary | ios::app );
    file_cards.write((char*)(&card), sizeof(Cards));
    file_cards.close();

}

void CreateDeck(int player_id, int cards_id)
{
    Decks d1;
    int flag = 0, flag2 = 0, p = 0, black_counter = 0, red_counter = 0, blue_counter = 0, green_counter = 0, white_counter = 0;
    char name[127];
    char black[] = "Black";
    char white[] = "White";
    char green[] = "Green";
    char red[] = "Red";
    char blue[] = "Blue";
    char cardName[63];
    Players p1;
    Cards c1;
    cin.getline(name,255);
    cin.sync();
    ifstream file_players("players.bin", ios::binary);
    ifstream file_cards("cards.bin", ios:: binary);
    ofstream file_decks("decks.bin", ios::binary | ios::app );
 //   file_cards.write((char*)(&card), sizeof(Cards));

    for(int i=0; i<player_id; i++)
    {
      file_players.seekg(i*sizeof(Players));       // Минава през всички структури записани във файла
      file_players.read((char*)&p1, sizeof(Players)); // и ги записва в p1
      if(strcmp( p1.name, name)==0)
      {
          flag = 1;
          d1.player_id = p1.id;
          break;
      }
      if((player_id - i) == 1)           //Ако е въведено грешно име излиза от функцията и чака нова команда
      {
          return;
      }
    }

    while(p < 60)  //За да се въвеждат 60 карти
    {
        cin.getline(cardName,63);
        cin.sync();
        for(int i = 0; i <cards_id;i++)
        {
            file_cards.seekg(i*sizeof(Cards));    // Преместваме с i по големината, за да можем да минем през всички структури записани във файла
            file_cards.read((char*)&c1, sizeof(Cards));
            if((strcmp(cardName, c1.name)) == 0) // Ако името на картата е въведено вярно записва в структурата ид то
            {
                d1.card_id[p] = c1.id;
                p++;                            // Увеличава се когато си въведе карта, за да брои до 60 карти
                flag2 = 1;
                if(((strcmp(c1.colour,"White") == 0)) || ((strcmp(c1.colour,"white") == 0)))
                {
                    white_counter++;
                }
                else if(((strcmp(c1.colour,"Black") == 0)) || ((strcmp(c1.colour,"black") == 0)))
                {
                    black_counter++;
                }
                else if(((strcmp(c1.colour,"Green") == 0)) || ((strcmp(c1.colour,"green") == 0)))
                {
                    green_counter++;
                }
                else if(((strcmp(c1.colour,"Blue") == 0)) || ((strcmp(c1.colour,"blue") == 0)))
                {
                    blue_counter++;
                }
                else if(((strcmp(c1.colour,"Red") == 0)) || ((strcmp(c1.colour,"red") == 0)))
                {
                    red_counter++;
                }
                break;
            }
            if((cards_id - i) == 1)
            {
                cout << "Nqma takava karta" << endl;
                return;
            }
        }
    }
    if((black_counter >= blue_counter) && (black_counter >= white_counter) && (black_counter >= red_counter) && (black_counter >= green_counter))
    {
        for(unsigned int cnt = 0; cnt <strlen(black);cnt++)
        {
            d1.colour[cnt] = black[cnt];
        }
    }
    else if((blue_counter >= black_counter) && (blue_counter >= white_counter) && (blue_counter >= red_counter) && (blue_counter >= green_counter))
    {
        for(unsigned int cnt = 0; cnt <strlen(blue);cnt++)
        {
            d1.colour[cnt] = blue[cnt];
        }
    }
    else if((red_counter >= blue_counter) && (red_counter >= white_counter) && (red_counter >= black_counter) && (red_counter >= green_counter))
    {
        for(unsigned int cnt = 0; cnt <strlen(red);cnt++)
        {
            d1.colour[cnt] = red[cnt];
        }
    }
    else if((green_counter >= blue_counter) && (green_counter >= white_counter) && (green_counter >= red_counter) && (green_counter >= black_counter))
    {
        for(unsigned int cnt = 0; cnt <strlen(green);cnt++)
        {
            d1.colour[cnt] = green[cnt];
        }
    }
    else if((white_counter >= blue_counter) && (white_counter >= black_counter) && (white_counter >= red_counter) && (white_counter >= green_counter))
    {
        for(unsigned int cnt = 0; cnt <strlen(white);cnt++)
        {
            d1.colour[cnt] = white[cnt];
        }
    }
    if((flag == 1) && (flag2 == 1))//za da moje pri koretktno vuvedeni ime na karti i igrach zapisva vuv faila
    {
        flag = 0;
        flag2 = 0;
        file_decks.write((char*)(&d1), sizeof(Decks));
    }
    file_players.close();
}

void Report(int player_id, int card_id, char* colour)
{
    ofstream file_report("report.txt", ios::app);
    ifstream file_decks2("decks.bin", ios::binary | ios::ate);
    int length= file_decks2.tellg() / sizeof(Decks);
    file_decks2.close();
    ifstream file_decks("decks.bin", ios::binary);
    ifstream file_players("players.bin", ios::binary);
    ifstream file_cards("cards.bin", ios::binary);
    Decks d1;
    Players p1;
    Cards c1;
    file_report<<colour <<endl;

    for(int i=0; i<length; i++)
    {
        file_decks.seekg(i*sizeof(Decks));
        file_decks.read((char*)&d1, sizeof(Decks));
        if((strcmp(d1.colour, colour)== 0))
        {
            for(int j=0; j<player_id; j++)
            {
                file_players.seekg(j*sizeof(Players));
                file_players.read((char*)&p1, sizeof(Players));
                if(d1.player_id== p1.id)
                {
                    file_report<<"     Owner: "<< p1.name;
                }
            }
            for(int k=0; k<card_id; k++)
            {
                file_cards.seekg(k*sizeof(Cards));
                file_cards.read((char*)&c1, sizeof(Cards));
                if(d1.card_id[0]== c1.id)
                {
                    file_report<<" Card: "<< c1.name<< " Colour: "<< c1.colour<< endl;
                }
            }
        }
    }
    file_report.close();
    file_decks.close();
    file_players.close();
    file_cards.close();

}

void MostCommonCard()
{
    Decks d1;
    Cards c1;
    int index = 0,maxx = 0;
    ofstream file_report("report.txt", ios::app);
        ifstream file_decks2("decks.bin", ios::binary | ios::ate);
        int length= file_decks2.tellg() / sizeof(Decks);
        file_decks2.close();
    int * buff = new int [length*60];
    //int buff[15];
        ifstream file_decks("decks.bin", ios::binary);
        for(int i=0; i<length; i++)
        {
            file_decks.seekg(i*sizeof(Decks));
            file_decks.read((char*)&d1, sizeof(Decks));
            for(int p = 0; p < 6 ;p++)
            {
                index += p;
                buff[index] = d1.card_id[p];
            }
            index += 1;
            }
            int max_times = 0;
            int temp, number;
            for (int i=0;i<length*60;i++)
            {
            temp = 0;
            number = buff[i];
            for (int j=0;j<20;j++)
            {
            if (buff[j] == number)
            {
            temp++;
    }
    }
    if (temp > max_times)
    {
    maxx = number;
    max_times = temp;
    }
    }
        delete[] buff;
        file_decks.close();
    ifstream file_cards("cards.bin", ios::binary);
    for(int i=0; i<length; i++)
        {
            file_cards.seekg(i*sizeof(Cards));
    file_cards.read((char*)&c1, sizeof(Cards));
    if(maxx == c1.id)
    {
    file_report << "Most common card: " << c1.name << endl;
    break;
    }

    }

    file_cards.close();
    file_report.close();
}
int main()
{
    int player_id = 0, card_id = 0;
    int cmd = 0;
    char command[256];
    char playersfile[] = "players.bin";
    char cardsfile[] = "cards.bin";
    char red[] = "Red";
    char blue[] = "Blue";
    char white[] = "White";
    char black[] = "Black";
    char green[] = "Green";
    Players p1;
    Cards c1;
    OpenFiles();
    player_id = CheckFile(playersfile,1);
    card_id = CheckFile(cardsfile,2);
    //cout<< sizeof(Players)<<" "<< sizeof(p1);
    while(1)
    {
        cin.getline(command,256);
        cin.sync();
        if(strcmp(command,"cp")==0)
        {
            cmd = 1;
        }
        else if(strcmp(command,"cc")==0)
        {
            cmd = 2;
        }
        else if(strcmp(command,"cd")==0)
        {
            cmd = 3;
        }
        else if(strcmp(command,"report")==0)
        {
            cmd = 4;
        }
        else
        {
            cout << "Greshna komanda" << endl;
        }
        switch(cmd)
        {
            case 1:
                CreatePlayers(p1, player_id);
                player_id++;
                if(player_id == 32768 )
                {
                    cout<< "Nqma poveche id-ta"<<endl;
                    return 0;
                }
            break;
            case 2:

                CreateCards(c1, card_id);
                card_id++;
                if(player_id == 32768 )
                {
                    cout<< "Nqma poveche id-ta"<<endl;
                    return 0;
                }
            break;
            case 3:
                CreateDeck(player_id,card_id);
            break;
            case 4:
                Report(player_id, card_id, red);
                Report(player_id, card_id, black);
                Report(player_id, card_id, blue);
                Report(player_id, card_id, white);
                Report(player_id, card_id, green);
                //MostCommonCard(); //todo uncomment

            break;
            default:
                return 0;
            break;
        }
        cmd = 0;
    }
    return 0;
}
