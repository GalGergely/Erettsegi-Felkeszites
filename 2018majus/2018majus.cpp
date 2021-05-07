// 2018majus.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct ajto {
    int ora;
    int perc;
    int szemAz;
    string ki_be;
};

int main()
{
    setlocale(LC_ALL, "");
    int db = 0;
    ajto a[1000];
    ifstream be;
    be.open("ajto.txt");
    while (!be.eof())
    {
        be >> a[db].ora >> a[db].perc >> a[db].szemAz >> a[db].ki_be;
        db++;
    }
    /*for (int i = 0; i < db; i++)
    {
        cout << a[i].ora << endl;
    }*/
    cout << "2. feladat: " <<endl;
    for (int i = 0; i < db; i++)
    {
        if (a[i].ki_be=="be")
        {
            cout << "Az elsõ belépõ : " << a[i].szemAz << endl;
            break;
        }           
    }
    for (int i = db; i >0 ; i--)
    {
        if (a[i].ki_be == "ki")
        {
            cout << "Az utolsó kilépõ : "<< a[i].szemAz << endl;
            break;
        }
    }
   // cout << "3. feladat: " << endl;
    int azonosito[500];
    bool asd = true;
    int szamlalo = 0;
    for (int i = 0; i < db; i++)
    {
        asd = true;
        for (int j = 0; j <500 ; j++)
        {
            if (azonosito[j]==a[i].szemAz)
            {
                asd = false;
            }
        }
        if (asd==true)
        {
            azonosito[szamlalo] = a[i].szemAz;
            szamlalo++;
        }
    }
    int cnt[500] = { 0 };
    for (int i = 0; i < szamlalo; i++)
    {
        for (int j = 0; j < db; j++)
        {
            if (azonosito[i]==a[j].szemAz)
            {
                cnt[i] = cnt[i] + 1;
            }
        }
    }
    ofstream ki;
    int csere;
    int csere2;
    ki.open("athaladas.txt");
    for (int i = 0; i < szamlalo; i++)
    {
        for (int j = i+1; j <szamlalo ; j++)
        {
            if (azonosito[i]>azonosito[j])
            {
                csere = cnt[i];
                csere2 = azonosito[i];
                cnt[i] = cnt[j];
                azonosito[i] = azonosito[j];
                cnt[j] = csere;
                azonosito[j] = csere2;
            }
        }
    }
    for (int i = 0; i < szamlalo; i++)
    {
        ki << azonosito[i] << " " << cnt[i]<< endl;
    }

    cout << "4. feladat: " << endl;
    cout << "A végén a társalgóban voltak : ";
    for (int i = 0; i < szamlalo; i++)
    {
        
            for (int j = db; j > 0; j--)
            {
                if (a[j].szemAz == azonosito[i])
                {
                   // cout << "asdasdas";
                    if (a[j].ki_be == "be")
                    {
                        cout << azonosito[i] << " " <<endl;
                    }

                    break;
                }
            }
        
    }
    cout << "5. feladat: " << endl;
    int max = 0;
    int szamlal = 0;
    int ora = 0;
    int perc = 0;
    for (int i = 0; i < db; i++)
    {
        for (int j = i; j < db; j++)
        {
            if (a[j].ki_be == "be")
            {
                szamlal++;
            }
            else
            {
                szamlal--;
            }
            if (max < szamlal)
            {
                cout << szamlal << " ";
                max = szamlal;
                ora = a[j].ora;
                perc=a[j].perc;
                 

            }
        }
        szamlal = 0;
    }
    cout << max << "    " << ora << ":" << perc<< endl;
    cout << "6. feladat: " << endl;
    cout << "Adja meg a személy azonosítóját!: ";
    int beAz;
    cin >> beAz;
    cout << "7. feladat: " << endl;
    for (int i = 0; i < db; i++)
    {
        if (beAz==a[i].szemAz)
        {
            if (a[i].ki_be=="be")
            {
                ora = a[i].ora;
                perc = a[i].perc;
                cout << ora << ":" << perc << "-";
            }

            else
            {
               cout  << a[i].ora << ":" << a[i].perc<<endl;
            }
        }
    }
    cout << "8. feladat: " << endl;
    int bentToltott = 0;
    int ora1 = 0;
    int perc1 = 0;
    int ora2 = 0;
    int perc2= 0;
    for (int i = 0; i < db; i++)
    {
        if (beAz == a[i].szemAz)
        {
            if (a[i].ki_be == "be")
            {
                ora1 = a[i].ora;
                perc1 = a[i].perc;

            }
            else
            {

                ora2 = a[i].ora;
                perc2 = a[i].perc;
                if (ora1==ora2)
                {
                    bentToltott += perc2 - perc1;

                }

                else
                {
                    ora2 = ora2 - ora1;
                    ora2 = ora2 * 60;
                    ora2 = ora2 - perc1;
                    ora2 += perc2;
                    bentToltott += ora2;
                }
                cout << bentToltott << " ";
            }
        }
    }
    cout << bentToltott << endl;

    return 0;
}