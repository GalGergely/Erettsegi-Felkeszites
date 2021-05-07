// 2019majus.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>

using namespace std;
struct Auto
{
	int nap;
	int ora;
	int perc;
	string oraPerc;
	string rendszam;
	int szemAz;
	int kmSzamlalo;
	bool ki_be;
};


int main()
{
	int db = 0;
	Auto a[500];
	ifstream be;
	//int asd;
	be.open("autok.txt");
	//be >> asd;
	while (!be.eof())
	{
		be >> a[db].nap >> a[db].oraPerc >> a[db].rendszam >> a[db].szemAz >> a[db].kmSzamlalo >> a[db].ki_be;
		db++;

	}
	/*for (int  i = 0; i < db; i++)
	{
		cout << a[i].nap << " " << a[i].oraPerc << " " << a[i].ki_be << endl;
	}*/
	for (int i = 0; i < db - 1; i++)
	{
		string tmp = a[i].oraPerc.substr(0, 2);
		a[i].ora = stoi(tmp);
		tmp = a[i].oraPerc.substr(3, 2);
		a[i].perc = stoi(tmp);
	}
	/*for (int i = 0; i < db-1; i++)
	{
		cout << a[i].ora << " " << a[i].perc << endl;
	}*/

	cout << "2. feladat: " << endl;
	for (int i = db; i > 0; i--)
	{
		if (a[i].ki_be == 0)
		{
			cout << a[i].nap << " " << a[i].rendszam << endl;
			break;
		}
	}
	cout << "3. feladat: " << endl;
	cout << "Nap :";
	int napSzam = 0;
	cin >> napSzam;
	for (int i = 0; i < db; i++)
	{
		if (napSzam == a[i].nap)
		{
			if (a[i].ki_be == 0)
			{
				cout << a[i].nap << " " << a[i].rendszam << " " << a[i].szemAz << " ki" << endl;
			}
			if (a[i].ki_be == 1)
			{
				cout << a[i].nap << " " << a[i].rendszam << " " << a[i].szemAz << " be" << endl;
			}
		}
	}
	cout << "4. feladat: " << endl;

	bool asd = true;
	//const int db2 = db;
	string b[500];
	int cnt = 0;
	for (int i = 0; i < db; i++)
	{
		asd = true;
		for (int j = 0; j < db; j++)
		{
			if (b[j] == a[i].rendszam)
			{
				asd = false;
			}
		}
		if (asd == true)
		{
			b[cnt] = a[i].rendszam;
			cnt++;
		}
	}
	for (int i = 0; i < cnt; i++)
	{
		cout << b[i] << endl;
	}
	int cnt2 = 0;
	for (int j = 0; j < cnt; j++)
	{
		for (int i = db; i > 0; i--)
		{
			if (b[j] == a[i].rendszam)
			{
				if (a[i].ki_be == 0)
				{
					cnt2++;
					break;
				}
				if (a[i].ki_be == 1)
				{
					break;
				}
			}
		}
	}
	cout << cnt2;


	return 0;
}

