#include <iostream>
#include <fstream>
#include<iomanip>
using namespace std;

struct tesztverseny 
{
    string versenyzoKodja;
    string valasz;
    int pontok;
};

int main()
{
    setlocale(LC_ALL, "");
    int db = 0;
    string megoldas;
    tesztverseny t[500];
    ifstream be;
    be.open("valaszok.txt");
    be >> megoldas;
    while (!be.eof())
    {
        be >> t[db].versenyzoKodja >> t[db].valasz;
        db++;
    }
    /*for (int i = 0; i < db; i++)
    {
        cout << t[i].versenyzoKodja << " " << t[i].valasz << endl;
    }*/
    cout << "1. feladat: Az adatok beolvasása" << endl;
    cout << "2. feladat: A vetélkedõn " << db << " versenyzõ indult."<<endl;
    cout << "3. feladat: A versenyzõ azonosítója = ";
    string azon;
    cin >> azon;
    for (int i = 0; i < db; i++)
    {
        if (azon==t[i].versenyzoKodja)
        {
            cout << t[i].valasz << "        " << "(a versenyzõ válasza)";
        }
    }
    cout << "4. feladat: " << endl;
    cout << megoldas<< "        (a helyes megoldás)"<<endl;

    for (int i = 0; i < db; i++)
    {
        for (int j = 0; j < megoldas.length(); j++)
        {
            if (azon == t[i].versenyzoKodja)
            {
                if (megoldas[j] == t[i].valasz[j])
                {
                    cout << "+";

                }
                else
                {
                    cout << " ";
                }
            }
            
        }
        
    }
    cout << "       (a versenyzõ helyes válaszai)"<<endl;
    cout << "5. feladat: A feladat sorszáma = ";
    int sorszam;
    cin >> sorszam;
    double arany = 0;
    int fo=0;
    for (int i = 0; i < db; i++)
    {
        if (megoldas[sorszam-1] == t[i].valasz[sorszam-1])
        {
            fo++;

        }
        
    }
    arany = (double)fo / (double)db*100;
    //cout << fo << "  " << db; 
    cout << "A feladatra " << fo << " fõ, a versenyzõk " <<setprecision(4)<< arany <<"%"<< "-a adott helyes választ."<<endl;
    ofstream ki;
    ki.open("pontok.txt");
    int cnt1 = 0;
    for (int i = 0; i < db; i++)
    {
        for (int j = 0; j < megoldas.length(); j++)
        {
            
                if (megoldas[j] == t[i].valasz[j]&&j<5)
                {
                    cnt1 += 3;

                }
                if (megoldas[j] == t[i].valasz[j] && j >=5&&j<10)
                {
                    
                    cnt1 += 4;
                }
                if (megoldas[j] == t[i].valasz[j] && j >= 10 && j < 13)
                {

                    cnt1 += 5;
                }
                if (megoldas[j] == t[i].valasz[j] && j ==13)
                {

                    cnt1 += 6;
                }
        }
        ki<<t[i].versenyzoKodja<<" " << cnt1 << endl;
        t[i].pontok = cnt1;
        cnt1 = 0;
    }
    cout << "6. feladat: A versenyzõk pontszámának meghatározása"<<endl;
    cout << "7. feladat: A verseny legjobbjai:"<<endl;
    int max1 = 0;
    int max2 = 0;
    int max3 = 0;
    for (int i = 0; i < db; i++)
    {
        if (max3<t[i].pontok)
        {           
            if (max2 < t[i].pontok)
            {
                if (max1 < t[i].pontok)
                {
                    max1 = t[i].pontok;
                }
                else
                {
                    max2 = t[i].pontok;
                }
            }
            else
            {
                max3 = t[i].pontok;
            }
        }
    }
    for (int i = 0; i < db; i++)
    {
        if (t[i].pontok==max1)
        {
            cout << "1. díj " << max1 << "(pont): " << t[i].versenyzoKodja << endl;
        }
    }
    for (int i = 0; i < db; i++)
    {
        if (t[i].pontok == max2)
        {
            cout << "2. díj " << max2 << "(pont): " << t[i].versenyzoKodja << endl;
        }
    }
    for (int i = 0; i < db; i++)
    {
        if (t[i].pontok == max3)
        {
            cout << "3. díj " << max3 << "(pont): " << t[i].versenyzoKodja << endl;
        }
    }
        
    return 0;
}


