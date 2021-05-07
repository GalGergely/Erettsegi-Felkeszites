// 2014majus.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
using namespace std;


int main()
{
    setlocale(LC_ALL, "");
    int db = 0;
    string ip[500];
    ifstream be;
    be.open("ip.txt");
    while (!be.eof())
    {
        be >> ip[db];
        db++;
    }
    cout << "1. feladat:" << "Beolvasás kész" << endl;
    cout << "2. feladat: " << endl;
    cout << db << endl;
    cout << "3. feladat: " << endl;
    string min = ip[0];
    //cout << min;
    for (int i = 1; i < db; i++)
    {

        if (min>ip[i])
        {
            
            min = ip[i];
            //cout << min<< endl;
        }
    }
    cout  << "A legalacsonyabb tárolt IP - cím: " << min << endl;
    cout << "4. feladat:" << endl;
    int doku = 0;
    int global = 0;
    int helyi = 0;
    char tomb[40];
    for (int i = 0; i < db; i++)
    {
        strcpy_s(tomb, ip[i].c_str());
        if (strncmp(tomb, "2001:0db8:xxxx:xxxx:xxxx:xxxx:xxxx:xxxx", 10)==0)
        {
            doku++;
        }
        if (strncmp(tomb, "2001:0exx:xxxx:xxxx:xxxx:xxxx:xxxx:xxxx", 7) == 0)
        {
            global++;
        }
        if (strncmp(tomb, "fcxx:xxxx:xxxx:xxxx:xxxx:xxxx:xxxx:xxxx", 2) == 0|| strncmp(tomb, "fdxx:xxxx:xxxx:xxxx:xxxx:xxxx:xxxx:xxxx", 2) == 0)
        {
            helyi++;
        }
        
    }
    cout << "Dokumentációs cím : " << doku << endl;
    cout << "Globális egyedi cím : " << global << endl;
    cout << "Helyi egyedi cím : " << helyi << endl;
    cout << "6. feladat:" << endl;
    cout << "7. feladat:" << endl;
    return 0;
}

