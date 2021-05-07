#include <iostream> 
#include <fstream>
#include <string>

using namespace std;

class Idojaras
{
public:
    string telepules;
    string ido;
    string szelirany;
    int homerseklet;

};

int main()
{
    //1. feladat
    cout << "1. Feladat" << endl;
    ifstream be;
    int db = 0;
    Idojaras a[500];
    be.open("tavirathu13.txt");
    while (!be.eof())
    {
        be >> a[db].telepules >> a[db].ido >> a[db].szelirany >> a[db].homerseklet;
        db++;
    }
    be.close();
    //ellenőrzés
    /*for(int i=0; i<db; i++)
    {
        cout<<a[i].telepules <<" "<< a[i].ido <<" "<< a[i].szelirany <<" "<< a[i].homerseklet << endl;
    }*/
    cout << "A beolvasas sikeres" << endl;
    //2.Feladat
    cout << "2. Feladat" << endl;
    cout << "Adjon meg egy varos kodjat: ";
    string varos;
    cin >> varos;
    for (int i = db; i > 0; i--)
    {
        if (a[i].telepules == varos)
        {

            cout << a[i].ido[0] << a[i].ido[1] << ":" << a[i].ido[2] << a[i].ido[3] << endl;
            break;
        }
    }
    //3.Feladat
    cout << "3. Feladat" << endl;
    int max = a[0].homerseklet, min = a[0].homerseklet, maxInd = 0, minInd = 0;
    for (int i = 1; i < db; i++)
    {
        if (max < a[i].homerseklet)
        {
            max = a[i].homerseklet;
            maxInd = i;
        }
        if (a[i].homerseklet < min)
        {
            min = a[i].homerseklet;
            minInd = i;
        }
    }

    cout << "A maximum homerseklet: " << a[maxInd].homerseklet << " A telepules: " << a[maxInd].telepules << " Az idopont pedig: " << a[maxInd].ido[0] << a[maxInd].ido[1] << ":" << a[maxInd].ido[2] << a[maxInd].ido[3] << endl;
    cout << "A minimum homerseklet: " << a[minInd].homerseklet << " A telepules: " << a[minInd].telepules << " Az idopont pedig: " << a[minInd].ido[0] << a[minInd].ido[1] << ":" << a[minInd].ido[2] << a[minInd].ido[3] << endl;
    //4.Feladat
    cout << "4. Feladat" << endl;
    bool tmp = 0;
    for (int i = 0; i < db; i++)
    {
        if (a[i].szelirany == "00000")
        {
            cout << a[i].telepules << " " << a[i].ido[0] << a[i].ido[1] << ":" << a[i].ido[2] << a[i].ido[3] << endl;
            tmp = 1;
        }
    }
    if (tmp == 0)
    {
        cout << "Nem volt szélcsend a mérések idején." << endl;
    }
