#include <iostream>
#include <fstream>
#include <cstdlib>
#include <windows.h>
#include <string>
#include <vector>
#include <conio.h>
using namespace std;


struct znajomy
{
    int id;
    string imie;
    string nazwisko;
    string numerTelefonu;
    string adres;
    string email;
};
void zapiszDoPliku(int liczbaUzytkownikow);
vector<znajomy> znajomi;

int przepiszDane(int liczbaUzytkownikow)
{
    fstream plik;
    if(plik.good()==true)
        plik.open("dane_adresowe.txt",ios::in);
    if(plik.good()==false)
    {

        ofstream plik( "dane_adresowe.txt" );
        plik.open("dane_adresowe.txt",ios::in);

    }
    else
    {
        string linia;
        znajomy zn;
        znajomi.clear();
        string konwersjaStringNaInt;
        do
        {


            getline(plik,konwersjaStringNaInt,'|');


            zn.id=atoi( konwersjaStringNaInt.c_str());


            getline(plik,zn.imie,'|') ;


            getline(plik,zn.nazwisko,'|');


            getline(plik,zn.numerTelefonu,'|');


            getline(plik,zn.adres,'|');


            getline(plik,zn.email,'|');

            znajomi.push_back(zn);





            liczbaUzytkownikow++;

        }
        while(getline(plik,linia));
        plik.close();
    }

    return liczbaUzytkownikow;

}
int zapiszDane(int liczbaUzytkownikow)
{
    string imie, nazwisko,numerTelefonu,adres,email;
    cout<<"Podaj imie: ";
    cin>>imie;
    cout<<"Podaj nazwisko: ";
    cin>>nazwisko;

    int i=0;
    while (i<liczbaUzytkownikow)
    {
        if(znajomi[i].imie==imie&&znajomi[i].nazwisko==nazwisko)
        {
            cout<<"Takie dane juz wprowadzone. Podaj inne dane"<<endl;
            cout<<"Podaj imie: ";
            cin>>imie;
            cout<<"Podaj nazwisko: ";
            cin>>nazwisko;
            i=0;
        }
        else
        {
            i++;



        }

    }

    cout<<"Podaj numer telefonu: ";
    cin>>numerTelefonu;
    cout<<"Podaj adres: ";
    cin.get();
    getline(cin,adres);
    cout<<"Podaj email: ";
    cin>>email;
    znajomy zn;
    if(liczbaUzytkownikow>0)
        zn.id=znajomi[liczbaUzytkownikow-1].id+1;
    else
        zn.id=0;
    zn.imie=imie;
    zn.nazwisko=nazwisko;
    zn.numerTelefonu=numerTelefonu;
    zn.adres=adres;
    zn.email=email;
    if(liczbaUzytkownikow>=0)
        znajomi.push_back(zn);
    zapiszDoPliku(liczbaUzytkownikow+1);
    return liczbaUzytkownikow+1;

}
void wyszukiwaniePoNazwisku(int liczbaUzytkownikow)
{
    string nazwisko;
    bool czy_nazwisko;
    czy_nazwisko=false;
    cout<<"Podaj nazwisko: ";
    cin>>nazwisko;
    for(int i=0; i<liczbaUzytkownikow; i++)
    {
        if (znajomi[i].nazwisko==nazwisko)
        {
            cout<<"ID: "<<  znajomi[i].id<<endl;
            cout<<"Imie: "<<  znajomi[i].imie<<endl;
            cout<<"Nazwisko: "<<  znajomi[i].nazwisko<<endl;
            cout<<"Numer telefonu: "<<  znajomi[i].numerTelefonu<<endl;
            cout<<"Adres: "<<  znajomi[i].adres<<endl;
            cout<<"E-mail: "<<  znajomi[i].email<<endl;
            cout<<endl;
            czy_nazwisko=true;
        }

    }
    if(czy_nazwisko==false)
    {

        cout<<"Brak znajomych o takim nazwisku"<<endl;
    }
    system("pause");
}
void wyszukiwaniePoImieniu(int liczbaUzytkownikow)
{
    string imie;
    bool czy_imie;
    czy_imie=false;
    cout<<"Podaj imie: ";
    cin>>imie;
    for(int i=0; i<liczbaUzytkownikow; i++)
    {
        if (znajomi[i].imie==imie)
        {
            cout<<"ID: "<<  znajomi[i].id<<endl;
            cout<<"Imie: "<<  znajomi[i].imie<<endl;
            cout<<"Nazwisko: "<<  znajomi[i].nazwisko<<endl;
            cout<<"Numer telefonu: "<<  znajomi[i].numerTelefonu<<endl;
            cout<<"Adres: "<<  znajomi[i].adres<<endl;
            cout<<"E-mail: "<<  znajomi[i].email<<endl;
            cout<<endl;
            czy_imie=true;

        }


    }
    if(czy_imie==false)
    {

        cout<<"Brak znajomych o takim imieniu"<<endl;
    }
    system("pause");
}

void pokazanieWszystkichDanych(int liczbaUzytkownikow)
{


    for(int i=0; i<liczbaUzytkownikow; i++)
    {
        cout<<"ID: "<<  znajomi[i].id<<endl;
        cout<<"Imie: "<<  znajomi[i].imie<<endl;
        cout<<"Nazwisko: "<<  znajomi[i].nazwisko<<endl;
        cout<<"Numer telefonu: "<<  znajomi[i].numerTelefonu<<endl;
        cout<<"Adres: "<<  znajomi[i].adres<<endl;
        cout<<"E-mail: "<<  znajomi[i].email<<endl;
        cout<<endl;



    }
    system("pause");
}
void edytujKontakt(int liczbaUzytkownikow)
{
    int id;
    int numerUzytkownika;
    cout<<"Podaj id: ";
    cin>>id;
    int i =0;
    while(true)
    {
        if (id==znajomi[i].id)
        {
            numerUzytkownika=i;
            break;
        }
        if (i==liczbaUzytkownikow)
        {
            cout<<"Nie znaleziono id. Podaj inne: ";
            cin>>id;
            i=0;
        }
        else
        {
            i++;
        }



    }
    char wybor;
    cout<<"Co chcesz edytowac?"<<endl;
    cout<<"1.Imie"<<endl;
    cout<<"2. Nazwisko"<<endl;
    cout<<"3. Numer telefonu"<<endl;
    cout<<"4.Email"<<endl;
    cout<<"5.Adres"<<endl;
    cout<<"6.Powrot do menu"<<endl;
    cin>>wybor;
    if (wybor=='1')
    {
        string imie;
        cout<<"Podaj imie: ";
        cin>>imie;
        znajomi[numerUzytkownika].imie=imie;
    }
    else if (wybor=='2')
    {
        string nazwisko;
        cout<<"Podaj nazwisko: ";
        cin>>nazwisko;
        znajomi[numerUzytkownika].nazwisko=nazwisko;
    }
    else if (wybor=='3')
    {
        string numerTelefonu;
        cout<<"Podaj numer telefonu: ";
        cin>>numerTelefonu;
        znajomi[numerUzytkownika].numerTelefonu=numerTelefonu;
    }
    else if (wybor=='4')
    {
        string email;
        cout<<"Podaj email: ";
        cin>>email;
        znajomi[numerUzytkownika].email=email;
    }
    else if (wybor=='5')
    {
        string adres;
        cout<<"Podaj adres: ";
        cin.get();
        getline(cin,adres);
        znajomi[numerUzytkownika].adres=adres;
    }
    else if (wybor=='6')
    {


    }
    zapiszDoPliku(liczbaUzytkownikow);
}
int usunKontakt(int liczbaUzytkownikow)
{
    int id;
    int numerUzytkownika;
    cout<<"Podaj id: ";
    cin>>id;
    int i =0;
    while(true)
    {
        if (id==znajomi[i].id)
        {
            numerUzytkownika=i;
            break;
        }
        if (i==liczbaUzytkownikow)
        {

            cout<<"Nie znaleziono id. Podaj inne: ";
            cin>>id;
            i=0;
        }
        else
        {
            i++;
        }

    }
    char znak;
    cout<<"Czy jesteœ pewien? Aby potwierdzic nacisnij t"<<endl;
    znak=getch();
    if(znak =='t')

    {
        znajomi.erase(znajomi.begin()+numerUzytkownika);
        zapiszDoPliku(liczbaUzytkownikow-1);
        return liczbaUzytkownikow-1;


    }
    return liczbaUzytkownikow;
}

void zapiszDoPliku(int liczbaUzytkownikow)
{
    ofstream plik;
    plik.open("dane_adresowe.txt",ios::out);
    if(plik.good()==true)

    {
        for (int i=0; i<liczbaUzytkownikow; i++)
        {
            if (i==0)
                plik<<znajomi[i].id<<'|'<<znajomi[i].imie<<'|'<<znajomi[i].nazwisko<<'|'<<znajomi[i].numerTelefonu<<'|'<<znajomi[i].adres<<'|'<<znajomi[i].email<<'|';
            else
                plik<<endl<<znajomi[i].id<<'|'<<znajomi[i].imie<<'|'<<znajomi[i].nazwisko<<'|'<<znajomi[i].numerTelefonu<<'|'<<znajomi[i].adres<<'|'<<znajomi[i].email<<'|';
        }
        plik.close();
    }



}
int main()
{
    int liczbaUzytkownikow=0;
    char wybor;



    liczbaUzytkownikow=przepiszDane(liczbaUzytkownikow);
    while (1)
    {
        system("cls");
        cout<<"1. Zapisz dane"<<endl;
        cout<<"2. Wyszukaj po nazwisku"<<endl;
        cout<<"3. Wyszukaj po imieniu"<<endl;
        cout<<"4. Pokaz wszystkie dane"<<endl;
        cout<<"5. Usun dane"<<endl;
        cout<<"6. Edytuj dane"<<endl;
        cout<<"9. Zakoncz program"<<endl;

        cin>>wybor;

        if(wybor=='1')
        {

            liczbaUzytkownikow=zapiszDane(liczbaUzytkownikow);
        }
        else if(wybor=='2')
        {
            wyszukiwaniePoNazwisku(liczbaUzytkownikow);
        }
        else if(wybor=='3')
        {

            wyszukiwaniePoImieniu(liczbaUzytkownikow);
        }
        else if(wybor=='4')
        {
            pokazanieWszystkichDanych(liczbaUzytkownikow);

        }
        else if(wybor=='5')
        {
            liczbaUzytkownikow= usunKontakt(liczbaUzytkownikow);

        }
        else if(wybor=='6')
        {
            edytujKontakt(liczbaUzytkownikow);

        }

        else if(wybor=='9')
        {

            exit(0);

        }
    }
    return 0;
}
