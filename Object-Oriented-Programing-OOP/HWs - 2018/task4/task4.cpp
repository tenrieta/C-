#include <iostream>
#include <cstring>
#define golden_coins int

using namespace std;

char* convertItoS(int number);

class Soldier
{
public:
    Soldier()
    {
        char tmp[] = "Soldier";
        this->name= new char[strlen(tmp)+1];
        strcpy(this->name,tmp);
        age = 0;
        fight_level = 0;
        salary = 0;
    };
    Soldier(const Soldier& sldr)
    {
        this->name = new char[strlen( sldr.name)+1];
        strcpy(this->name, sldr.name);
        this->age = sldr.age;
        this->fight_level = sldr.fight_level;
        this->salary = sldr.salary;
    };
    Soldier& operator = (const Soldier& sldr)
    {
        if(this==&sldr)
        return *this;
        delete [] this->name;
        this->name = new char[strlen( sldr.name)+1];
        strcpy(this->name, sldr.name);
        this->age = sldr.age;
        this->fight_level = sldr.fight_level;
        this->salary = sldr.salary;
        return *this;
    };
    ~Soldier()
    {
        delete [] this->name;
        //cout<<"Goodbye soldier"<<endl;
    };
    void setSldrInfo(char* name, int age, int fight_level, golden_coins salary)
    {
        delete [] name;
        this->name = new char[strlen(name)+1];
        strcpy(this->name, name);
        this->age = age;
        this->fight_level = fight_level;
        this->salary = salary;
    }
    char* getName()const
    {
        return this->name;
    }
    int getAge()const
    {
        return this->age;
    }
    int getFightLevel()const
    {
        return this->fight_level;
    }
    golden_coins getSalary()const
    {
        return this->salary;
    }
protected:
    char* name;
    int age;
    int fight_level;
    golden_coins  salary;
};

class Sergeant: public Soldier
{
public:
    Sergeant(): Soldier()
    {
        char tmp[] = "Description";
        this->squad_description= new char[strlen(tmp)+1];
        strcpy(this->squad_description,tmp);
        this->all_soldiers = NULL;
        this->numberOfSoldiers = 0;
    };
    Sergeant(const Sergeant&srgnt): Soldier(srgnt)
    {
        this->squad_description = new char[strlen(srgnt.squad_description)+1];
        strcpy(this->squad_description,srgnt.squad_description);
        this->all_soldiers = new Soldier[srgnt.numberOfSoldiers+1];
        for(int i=0; i<numberOfSoldiers; i++)
        {
            this->all_soldiers[i]= srgnt.all_soldiers[i];
        }
        this->numberOfSoldiers = srgnt.numberOfSoldiers;
    }
    Sergeant& operator = (const Sergeant& srgnt)
    {
        if(&srgnt==this)
        return *this;
        (*this).Soldier:: operator = (srgnt);
        this->all_soldiers = new Soldier[srgnt.numberOfSoldiers];
        for(int i=0; i<numberOfSoldiers; i++)
        {
            this->all_soldiers[i]= srgnt.all_soldiers[i];
        }
        this->numberOfSoldiers = srgnt.numberOfSoldiers;
        return *this;
    };
    ~Sergeant()
    {
        delete[] squad_description;
        delete[] all_soldiers;
    };
    void AddSoldier(const Soldier& sldr)
    {
       if(this->getFightLevel() <= sldr.getFightLevel())
       {
           cout << "Silite na voinika ne sa podhodqshti za tozi serjant" << endl;
       }
       else
       {
           char tmpstring[100] = "Broqt na voinicite e: ";
           Soldier* tmp = new Soldier[numberOfSoldiers+1];
           for(int i=0; i<numberOfSoldiers; i++)
           {
               tmp[i]= all_soldiers[i];
           }
           all_soldiers = new Soldier[numberOfSoldiers+1];
           for(int i=0; i<numberOfSoldiers; i++)
           {
               all_soldiers[i]=tmp[i];
           }
           all_soldiers[numberOfSoldiers] = sldr;

           this->numberOfSoldiers++;
           delete [] tmp;
           strcat(tmpstring,convertItoS(numberOfSoldiers));
           squad_description = new char[strlen(tmpstring)+1];
           strcpy(this->squad_description,tmpstring);
       }
    };
    void SquadDescription()
    {
        cout<< squad_description <<endl;
    };
    void SetSrgInfo(char* name, int age, int fight_level, golden_coins salary)
    {
        delete [] name;
        this->name = new char[strlen(name)+1];
        strcpy(this->name, name);
        this->age = age;
        this->fight_level = fight_level;
        this->salary = salary;
    };
    int getNumberOfSoldiers() const
    {
        return this->numberOfSoldiers;
    }
    Soldier* all_soldiers;
private:
    int numberOfSoldiers;
    char* squad_description;

};

class Spell
{
    public:
    Spell()
    {
        char tmp[] = "Spell";
        this->name= new char[strlen(tmp)+1];
        strcpy(this->name,tmp);
        char tmp2[] = "Description";
        this->spell_description= new char[strlen(tmp)+1];
        strcpy(this->spell_description,tmp);
        char tmp3[] = "Type";
        this->type= new char[strlen(tmp)+1];
        strcpy(this->type,tmp);
        this->magic_power = 0;
    };
 Spell(const Spell& spl)
    {
        this->name = new char[strlen(spl.name)+1];
        strcpy(this->name,spl.name);
        this->spell_description = new char[strlen(spl.spell_description)+1];
        strcpy(this->spell_description, spl.spell_description);
        this->type = new char[strlen(spl.type)+1];
        strcpy(this->type,spl.type);
        this->magic_power = spl.magic_power;
    };
    Spell& operator = (const Spell& spl)
    {
        if(this==&spl)
        return *this;
        delete [] this->name;
        this->name = new char[strlen( spl.name)+1];
        strcpy(this->name, spl.name);
        this->spell_description = new char[strlen(spl.spell_description)+1];
        strcpy(this->spell_description, spl.spell_description);
        this->type = new char[strlen(spl.type)+1];
        strcpy(this->type,spl.type);
        this->magic_power = spl.magic_power;
        return *this;
    };
    ~Spell()
    {
        delete[] this->name;
        delete[] this->spell_description;
        delete[] this->type;
    };
    void setSpellInfo(char* name,char* sd,char* type,int mp)
    {
        delete [] name;
        this->name = new char[strlen(name)+1];
        strcpy(this->name,name);
        this->spell_description = new char[strlen(sd)+1];
        strcpy(this->spell_description,sd);
        this->type = new char[strlen(type)+1];
        strcpy(this->type,type);
        this->magic_power = mp;
    }
    char* getName() const
    {
        return this->name;
    }
    char* getSpellDescription() const
    {
        return this->spell_description;
    }
    char* getType() const
    {
        return this->type;
    }
    int getMagicLevel() const
    {
        return this-> magic_power;
    }
private:
    char* name;
    char* spell_description;
    char* type;
    int magic_power;
};

class MagicBook
{
    public:
    MagicBook()
    {
       this->numberOfPages = 1;
       this->pages = NULL;
    };
    MagicBook(const MagicBook& book)
    {
        this->pages = new Spell[book.numberOfPages+1];
        for(int i=0; i<numberOfPages; i++)
        {
            this->pages[i]= book.pages[i];
        }
        this->numberOfPages = book.numberOfPages;
    };
    MagicBook& operator = (const MagicBook& book)
    {
        if(this==&book)
        return *this;
        this->numberOfPages = book.numberOfPages;
        this->pages = new Spell[book.numberOfPages+1];
        for(int i=0; i<book.numberOfPages; i++)
        {
            this->pages[i]= book.pages[i];
        }

        return *this;
    };
    ~MagicBook()
    {
        delete[] pages;
    };
    void AddPages(const Spell& page)
    {
       Spell* tmp = new Spell[numberOfPages];
       for(int i=0; i<numberOfPages-1; i++)
       {
           tmp[i] = pages[i];
       }
       pages = new Spell[numberOfPages+1];
       for(int i=0; i<numberOfPages-1; i++)
       {
           pages[i] = tmp[i];
       }
       pages[numberOfPages-1] = page;

       this->numberOfPages++;
       delete [] tmp;
    }
    void useMagic(const Spell& page)
    {
        int index = 0;
        for(int i = 0;i <numberOfPages;i++)
        {
            if((strcmp(page.getName(),pages[i].getName()) == 0) && (strcmp(page.getType(),pages[i].getType()) == 0) && (strcmp(page.getSpellDescription(),pages[i].getSpellDescription()) == 0) && (page.getMagicLevel() == pages[i].getMagicLevel()))
            {
                index = i;
                break;
            }
            else
            {
                index = -1;
            }
        }
        if(index == -1)
        {
            cout << "Nqma takava magiq" << endl;
        }
        else
        {
            Spell* tmp = new Spell[numberOfPages+1];
            for(int i = 0;i<numberOfPages;i++)
            {
                tmp[i] = pages[i];
            }
            pages = new Spell[numberOfPages-1];
            int p = 0;
            for(int i = 0;i < numberOfPages-1;i++,p++)
            {
                if(index == i)
                {
                    ++p;
                }
                pages[i] = tmp[p];
            }
            numberOfPages--;
        }

    }
    int getNumberOfPages() const
    {
        return this->numberOfPages;
    }
    Spell* pages;
    private:
    int numberOfPages;
};

class Magus: public Soldier
{
public:
    Magus(): Soldier()
    {
        char tmp[] = "Description";
        this->battalion_description = new char[strlen(tmp)+1];
        strcpy(this->battalion_description,tmp);
        this->all_sergeants = NULL;
        this->numberOfSergeants = 0;
        this->magic_power = 0;
    };
    Magus(const Magus& mag): Soldier(mag)
    {
        this->battalion_description = new char[strlen(mag.battalion_description)+1];
        strcpy(this->battalion_description,mag.battalion_description);
        this->numberOfSergeants = mag.numberOfSergeants;
        this->all_sergeants = new Sergeant[mag.numberOfSergeants+1];//da se smenqt mestata s number i
        for(int i=0; i<numberOfSergeants; i++)
        {
            this->all_sergeants[i]= mag.all_sergeants[i];
        }
        this->magic_power = mag.magic_power;
    }
     Magus& operator = (const Magus& mag)
    {
        if(this==&mag)
        return *this;
        Soldier:: operator = (mag);
        this->battalion_description = new char[strlen(mag.battalion_description)+1];
        strcpy(this->battalion_description,mag.battalion_description);
        this->numberOfSergeants = mag.numberOfSergeants;
        this->all_sergeants = new Sergeant[mag.numberOfSergeants+1];//da se smenqt mestata s number i allsergnts?? i +1??
        for(int i=0; i<numberOfSergeants; i++)
        {
            this->all_sergeants[i]= mag.all_sergeants[i];
        }
        this->magic_power = mag.magic_power;
        this->book = mag.book;
        return *this;
    };
    ~Magus()
    {
       delete[] battalion_description;
       delete[] all_sergeants;
    };
    void SetMgsInfo(char* name, int age, int fight_level, golden_coins salary,int magic_power,const MagicBook& book)
    {
        delete [] name;
        this->name = new char[strlen(name)+1];
        strcpy(this->name, name);
        this->age = age;
        this->fight_level = fight_level;
        this->salary = salary;
        this->magic_power = magic_power;
        this->book = book;
    }
    void AddSergeant(const Sergeant& srgnt)
    {
       if(this->getFightLevel() <= srgnt.getFightLevel())
       {
           cout << "Silite na serjanta ne sa podhodqshti za tozi mag" << endl;
       }
       else
       {
           char tmpstring[100] = "Broqt na batalionite e: ";
           Sergeant* tmp = new Sergeant[numberOfSergeants+1];
           for(int i=0; i<numberOfSergeants; i++)
           {
               tmp[i] = all_sergeants[i];
           }
           all_sergeants = new Sergeant[numberOfSergeants+1];
           for(int i=0; i<numberOfSergeants; i++)
           {
               all_sergeants[i]=tmp[i];
           }
           all_sergeants[numberOfSergeants] = srgnt;

           this->numberOfSergeants++;
           delete [] tmp;
           strcat(tmpstring,convertItoS(numberOfSergeants));
           battalion_description = new char[strlen(tmpstring)];
           strcpy(this->battalion_description,tmpstring);
       }
    }
    void BatallionDescription()
    {
        cout << battalion_description << endl;
    }
    int getNumberOfSergeants() const
    {
        return this->numberOfSergeants;
    }
    int getMagicPower() const
    {
        return this->magic_power;
    }
    Sergeant* all_sergeants;
    MagicBook book;
private:
    int numberOfSergeants;
    int magic_power;
    char* battalion_description;
};

class General: public Soldier
{
    public:
    General(): Soldier()
    {
        char tmp[] = "General";
        this->army_description = new char[strlen(tmp)+1];
        strcpy(this->army_description,tmp);
        this->all_magus = NULL;
        this->numberOfMagus = 0;
    };
    General(const General& gnrl): Soldier(gnrl)
    {
        this->army_description = new char[strlen(gnrl.army_description)+1];
        strcpy(this->army_description,gnrl.army_description);
        this->all_magus = new Magus[gnrl.numberOfMagus+1];
        for(int i=0; i<numberOfMagus; i++)
        {
            this->all_magus[i] = gnrl.all_magus[i];
        }
        this->numberOfMagus = gnrl.numberOfMagus;
    }
    General operator = (const General& gnrl)
    {
        if(this==&gnrl)
        return *this;
        Soldier:: operator = (gnrl); // predi ili sled if ???
        this->army_description = new char[strlen(gnrl.army_description)+1];
        strcpy(this->army_description,gnrl.army_description);
        this->all_magus = new Magus[gnrl.numberOfMagus+1];
        for(int i=0; i<numberOfMagus;i++)
        {
            this->all_magus[i] = gnrl.all_magus[i];
        }
        this->numberOfMagus = gnrl.numberOfMagus;
        return *this;
    };
    ~General()
    {
        delete[] army_description;
        delete[] all_magus;
    }

    void SetGenInfo(char* name, int age, int fight_level, golden_coins salary)
    {
        delete [] name;
        this->name = new char[strlen(name)+1];
        strcpy(this->name, name);
        this->age = age;
        this->fight_level = fight_level;
        this->salary = salary;
    }
    void ArmyDescription()
    {
        cout << army_description << endl;
    }
    void AddMagus(const Magus& mag)
    {
       if(this->getFightLevel() <= mag.getFightLevel())
       {
           cout << "Silite na maga ne sa podhodqshti za tozi general" << endl;
       }
       else
       {
           char tmpstring[100] = "Broqt na voiskite e: ";
           Magus* tmp = new Magus[numberOfMagus+1];
           for(int i=0; i<numberOfMagus; i++)
           {
               tmp[i] = all_magus[i];
           }
           all_magus = new Magus[numberOfMagus+1];
           for(int i=0; i<numberOfMagus; i++)
           {
               all_magus[i]=tmp[i];
           }
           all_magus[numberOfMagus] = mag;

           this->numberOfMagus++;
           delete [] tmp;
           strcat(tmpstring,convertItoS(numberOfMagus));
           army_description = new char[strlen(tmpstring)+1];
           strcpy(this->army_description,tmpstring);
        }
    }
    int getNumberOfMagus() const
    {
        return this->numberOfMagus;
    }
    Magus* all_magus;
private:
        int numberOfMagus;
        char* army_description;
};

void printFightLevel(const General& gen)
{
    int arr[3];
    int sum = gen.getFightLevel(),counter = 1;
    for(int i = 0;i <gen.getNumberOfMagus();i++)
    {
        sum += gen.all_magus[i].getFightLevel();
        counter++;
        for(int p = 0;p <gen.all_magus[i].getNumberOfSergeants();p++)
        {
            sum += gen.all_magus[i].all_sergeants[p].getFightLevel();
            counter++;
            for(int k = 0;k < gen.all_magus[i].all_sergeants[p].getNumberOfSoldiers();k++)
            {
                sum += gen.all_magus[i].all_sergeants[p].all_soldiers[k].getFightLevel();
                counter++;
            }
        }
    }

    cout << "Obshtata  sila na voiskata e " << sum << endl;
    cout << "Srednata  sila na voiskata e " << sum/counter<< endl;
}
void printMagicPower(const General& gen)
{
    int sum = 0;
    for(int i = 0;i <gen.getNumberOfMagus();i++)
    {
        sum+= gen.all_magus[i].getMagicPower();
    }

    cout << "Obshtata magicheska sila na voiskata e " << sum << endl;
    cout << "Srednata magicheska sila na voiskata e " << sum/gen.getNumberOfMagus()<< endl;
}
void printGold(const General& gen)
{
    int sum = gen.getSalary();
    for(int i = 0;i <gen.getNumberOfMagus();i++)
    {
        sum += gen.all_magus[i].getSalary();
        for(int p = 0;p <gen.all_magus[i].getNumberOfSergeants();p++)
        {
            sum += gen.all_magus[i].all_sergeants[p].getSalary();
            for(int k = 0;k < gen.all_magus[i].all_sergeants[p].getNumberOfSoldiers();k++)
            {
                sum += gen.all_magus[i].all_sergeants[p].all_soldiers[k].getSalary();
            }
        }
    }
    cout << "Cenata na voiskata za 1 mesec " << sum << endl;
}
    void bonus(const General& gen)
    {
        int max_power = 0;
        int counter = 0;
        for(int i = 0;i <gen.getNumberOfMagus();i++)
        {
            max_power = gen.all_magus[i].getMagicPower();
            for(int p = 0;p<gen.all_magus[i].book.getNumberOfPages()-1;p++)
            {
                if(max_power-gen.all_magus[i].book.pages[i].getMagicLevel() > 0)
                {
                    max_power -= gen.all_magus[i].book.pages[i].getMagicLevel();
                    counter++;
                }
            }
            cout << "Mage: " << gen.all_magus[i].getName() << " can use " << counter << " spells " << endl;
            counter = 0;
        }
    }
char* convertItoS(int number)
{
    int counter=0,i = 1;
    int n = number;
    do
    {
        counter++;
        n /= 10;
    }while(n > 0);
    char* tmp = new char[counter+1];
    do
    {
        tmp[counter - i] = number%10 + '0';
        i++;
        number /= 10;
    }while(number > 0);

    return tmp;
}
int main()
{
    int age=5;
    int fight_level= 110;
    int salary=300;
    Soldier sldr;
    sldr.setSldrInfo("Voichot", age, 109,salary);
    cout<< sldr.getName()<<" "<<sldr.getAge()<<" "<< sldr.getFightLevel()<<" "<< sldr.getSalary()<<endl;
    Soldier sldr2,sldr3;
    sldr2.setSldrInfo("Han",10,15,100);
    cout<< sldr2.getName()<<" "<<sldr2.getAge()<<" "<< sldr2.getFightLevel()<<" "<< sldr2.getSalary()<<endl;
    sldr3.setSldrInfo("jaba",10,15,100);
    cout<< sldr3.getName()<<" "<<sldr3.getAge()<<" "<< sldr3.getFightLevel()<<" "<< sldr3.getSalary()<<endl;
    Sergeant srgnt;
    srgnt.SetSrgInfo("Voin", age, fight_level,salary);
    srgnt.AddSoldier(sldr);
    srgnt.AddSoldier(sldr2);
    srgnt.AddSoldier(sldr3);
    cout<<srgnt.all_soldiers[0].getName()<<endl;
    cout<<srgnt.all_soldiers[1].getName()<<endl;
    cout<<srgnt.all_soldiers[2].getName()<<endl;
    //srgnt.SquadDescription();
    Spell s1,s2,s3,s4;
    s1.setSpellInfo("Ivan","Pravi te jaba","Vodna",100);
    s2.setSpellInfo("Dragan","Pravi te kon","Zemen",100);
    s3.setSpellInfo("Petkan","Pravi te magare","Ogneno",100);
    s4.setSpellInfo("Sweety","Pravi te pate","Vuzdushno",100);
    cout << s1.getName() << s1.getMagicLevel() << s1.getSpellDescription() << s1.getType() << endl;
    MagicBook m1;
    m1.AddPages(s1);
    cout << m1.pages[0].getName() << endl;
    m1.AddPages(s2);
    cout << m1.pages[1].getName() << endl;
    m1.AddPages(s3);
    cout << m1.pages[2].getName() << endl;
    cout << m1.getNumberOfPages() << endl;
    m1.AddPages(s4);
    cout << m1.pages[3].getName() << endl;
    cout << m1.getNumberOfPages() << endl;
    cout << endl << endl;
    cout << m1.pages[0].getName() << endl;
    cout << m1.pages[1].getName() << endl;
    cout << m1.pages[2].getName() << endl;
    cout << m1.pages[3].getName() << endl;
    cout << endl << endl;
    m1.useMagic(s4);
    cout << m1.getNumberOfPages() << endl;
    cout << m1.pages[0].getName() << endl;
    cout << m1.pages[1].getName() << endl;
    cout << m1.pages[2].getName() << endl;
    cout << endl << endl;
    srgnt.SquadDescription();
   // cout << m1.pages[3].name << endl;

    cout << endl << endl;
    cout << endl << endl;
    Magus mag1,mag2,mag3;

    mag1.SetMgsInfo("PanPeter",65,456,1000,999,m1);
    mag2.SetMgsInfo("PanNePeter",65,456,1000,999,m1);
    mag3.SetMgsInfo("HanSolo",65,456,1000,999,m1);
    cout << mag1.getName() << mag1.getAge() << mag1.getFightLevel() << mag1.getSalary() << mag1.getMagicPower()<< endl;
    //cout << mag1.battalion_description << endl;
    Sergeant se1,se2,se3;
    se1.SetSrgInfo("Pate", age, fight_level,salary);
    se2.SetSrgInfo("Vulk", age, fight_level,salary);
    se3.SetSrgInfo("Kuche", age, fight_level,salary);
    mag1.AddSergeant(srgnt);
    mag1.AddSergeant(se1);
    mag1.AddSergeant(se2);
    mag1.AddSergeant(se3);
    //mag2.AddSergeant(se1);
    mag1.BatallionDescription();
    cout <<mag1.all_sergeants[0].getName()<< endl;
    cout <<mag1.all_sergeants[1].getName()<< endl;
    cout <<mag1.all_sergeants[2].getName()<< endl;
    cout <<mag1.all_sergeants[3].getName()<< endl;
    General gen;
    gen.SetGenInfo("Zod",1928,9000,0);
    cout  << gen.getName() << endl;

    gen.AddMagus(mag1);
    gen.AddMagus(mag2);
    gen.AddMagus(mag3);

    cout << gen.all_magus[0].getName() << endl;
    cout << gen.all_magus[1].getName() << endl;
    cout << gen.all_magus[2].getName() << endl;

    gen.ArmyDescription();

    cout << endl << endl;
    printFightLevel(gen);
    printMagicPower(gen);
    printGold(gen);
    bonus(gen);

return 0;
}
