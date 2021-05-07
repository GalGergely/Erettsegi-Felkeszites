#include <iostream>
#include <fstream>
using namespace std;


int main()
{
    string arucikk[1000][20];
    int  db = 0;
    int cnt = 0;
    string dogshit;
    ifstream be;
    be.open("penztar.txt");
    while (!be.eof())
    {
        be >> dogshit;
        if (dogshit=="F")
        {
            db++;
            cnt = 0;
        }
        else
        {
            arucikk[db][cnt]=dogshit;
            cnt++;
           
        }
    }
    /*for (int i = 0; i < db; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            cout << arucikk[i][j] << endl;
        }
    }*/
    cout << "2. feladat:  A fizetések száma : " << db << endl;
    cout << "3. feladat: " << endl;
    int cnt2=0;    
        for (int j = 0; j < 20; j++)
        {
            if (arucikk[0][j]!="")
            {
                cnt2++;
            }
        }
        cout << "Az elsõ vásárló " << cnt2 << " darab árucikket vásárolt." << endl;
    return 0;
}
