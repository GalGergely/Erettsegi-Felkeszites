#include <iostream>
#include <fstream>

using namespace std;
struct valami {
	string nev1;
	string nev2;
	string nev3;
	int datum;
	string verseny1;
	int helyezes1;
	string verseny2;
	int helyezes2;
	string verseny3;
	int helyezes3;
};

int main()
{
	int db = 0;
	valami v[500];
    ifstream be;
    be.open("inp1.txt");
	while (!be.eof())
	{
		be >> v[db].nev1 >> v[db].nev2 >> v[db].nev3 >> v[db].datum >> v[db].verseny1 >> v[db].helyezes1 >> v[db].verseny2 >> v[db].helyezes2 >> v[db].verseny3 >> v[db].helyezes3;
		db++;
	}
	for (int i = 0; i < db; i++)
	{
		cout << v[i].nev1 << v[i].nev2 << v[i].nev3 << endl;
		//cout << v[db].nev1 << v[db].nev2 << v[db].nev3 << v[db].datum << v[db].verseny1 << v[db].helyezes1 << v[db].verseny2 << v[db].helyezes2 << v[db].verseny3 << v[db].helyezes3 << endl;
	}
}
