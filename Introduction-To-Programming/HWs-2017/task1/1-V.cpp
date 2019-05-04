#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
    unsigned int pHealth = 100, coins = 0;
    float pDefence = 25, pLuck = 5, pMagic = 5, pDamage = 10;
    unsigned int mHealth = 50, increase = 0, tmpHealth = 50;
    float mDefence = 5, mLuck = 0, mDamage = 5, tmpDefence = 5, tmpLuck = 0, tmpDamage = 5;
    char l, r, command;
    int prandom, mrandom;
    while(1)
    {
        cout<<"chose one: [A]-attack, [D]-defend, [P]-potion, [I]-info or [X]-exit"<<endl;
        cin>>l>>command>>r;
        if(l!='[' || r!=']'|| (command!='I' && command!='A' && command!='D' && command!='P' && command!='X'))
        {
            cout<< "greshno vuvedena komanda" << endl;
        }
        else
        {
            if(command == 'A')
            {
               mHealth -= pDamage;
               mrandom = rand()%2;
               if(mrandom==1)
               {
                   pHealth -= mDamage;
               }
               else if(mrandom==2)
               {
                   mDamage /= 2;
               }
            }
            if(command == 'P')
            {
                pHealth = 100;
                pMagic--;
            }
            if(command == 'D')
            {
                prandom = rand()%2;
                if(prandom == 1)
                {
                    mDamage /= 2;
                }
                mrandom = rand()%2;
                if(mrandom == 1)//defence
                {
                    pDamage /= 2;
                }
                else if(mrandom==2)//atack
                {
                    pHealth -= mDamage;
                }
            }
            if(command == 'I')
            {
                cout<<"Player| health:" << pHealth << " damage:" << pDamage << " defence:" << pDefence
                    << " luck:" << pLuck << " magic:"  <<pMagic<< " coins:" << coins <<endl;
                cout<<"Monster| health:" << mHealth << " damage:" << mDamage << " defence:" << mDefence << " luck:" << mLuck<<endl;
            }
            if(command == 'X')
            {
                return 0;
            }
            if(pDefence == 10)
            {
                pDamage -= pDamage*0.05; //5% ot damage namalq
                pDefence = 0;
            }
            if(pLuck == 10)
            {
                pDamage += pDamage*0.05;
                pDefence += pDefence*0.05;
            }
            if(mHealth == 0)
            {
                pHealth = 100;
                pMagic += 0.5;
                increase += 2;
                mHealth = tmpHealth + increase;
                mDamage = tmpDamage + increase;
                mDefence = tmpDefence + increase;
                mLuck = tmpLuck + increase;
                tmpHealth = mHealth;
                tmpDamage = mDamage;
                tmpDefence = mDefence;
                tmpLuck = mLuck;
                if(increase == 10)
                {
                    coins += 1;
                }
                cout<<"razpredeli 5 tochki bonus vseki buton: [H], [D], [A] or [L] natisnat vednuj uvelichava s 1 tochka suotvetniq atribut"<<endl;
                for(int i = 0; i < 5; i++)
                {
                    cin>>l>>command>>r;
                    if(command == 'H')
                    {
                        pHealth += 1;
                        cout<< "health: " << pHealth<<endl;
                    }
                    else if(command == 'A')
                    {
                        pDefence += 1;
                        cout<<"defence: " <<pDefence<<endl;
                    }
                    else if(command == 'D')
                    {
                        pDamage += 1;
                        cout<<"damage: " << pDamage<<endl;
                    }
                    else if(command == 'L')
                    {
                        pLuck += 1;
                        cout<<"luck: " << pLuck<<endl;
                    }
                    else
                    {
                        cout<< "greshno vuvedena komanda" <<endl;
                        i--;
                    }
                }
            }
            if(pHealth == 0)
            {
                if(coins != 0)
                {
                    cout<<"Jelaete li oshte edna igra? Za da natisni [Y], za ne [X]"<<endl;
                    cin>>l>>command>>r;
                    if(command == 'Y')
                    {
                        coins--;
                    }
                    else
                    {
                        return 0;
                    }
                }
                else
                {
                    cout<<"Nqmate poveche jetoni- igrata prikliuchi"<<endl;
                    return 0;
                }
            }
            cout<<"Player| health:" << pHealth << " damage:" << pDamage << " defence:" << pDefence
                    << " luck:" << pLuck << " magic:"  <<pMagic<< " coins:" << coins <<endl;
            cout<<"Monster| health:" << mHealth << " damage:" << mDamage << " defence:" << mDefence << " luck:" << mLuck<<endl;
        }
    }
    return 0;
}
