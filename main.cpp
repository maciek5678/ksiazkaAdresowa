#include <iostream>
#include <fstream>
#include <cstdlib>
#include <windows.h>
#include <string>
#include <vector>
#include <conio.h>
#include <cstdio>
using namespace std;
struct uzytkownicy
{
    int id;
    string login;
    string haslo;
};
struct znajomy
{
    int id;
    int idUzytkownika;
    string imie;
    string nazwisko;
    string numerTelefonu;
    string adres;
    string email;
};
vector<uzytkownicy> uzytkownik;
vector<znajomy> znajomi;
void pokazMenu(int idUzytkownika,int liczbaLoginow );
void pokazUzytkownika (int liczbaPorzadkowa)
{
    cout<<"ID: "<<  znajomi[liczbaPorzadkowa].id<<endl;
    cout<<"ID uzytkownika: "<<  znajomi[liczbaPorzadkowa].idUzytkownika<<endl;
    cout<<"Imie: "<<  znajomi[liczbaPorzadkowa].imie<<endl;
    cout<<"Nazwisko: "<<  znajomi[liczbaPorzadkowa].nazwisko<<endl;
    cout<<"Numer telefonu: "<<  znajomi[liczbaPorzadkowa].numerTelefonu<<endl;
    cout<<"Adres: "<<  znajomi[liczbaPorzadkowa].adres<<endl;
    cout<<"E-mail: "<<  znajomi[liczbaPorzadkowa].email<<endl;
    cout<<endl;
}
int pokazNajwiekszeID()
{
    fstream plik;
    int najwiekszeID=0;
    if(plik.good()==true)
        plik.open("dane_adresowe.txt",ios::in);
    if(plik.good()==false)
    {
        return najwiekszeID;
    }
    else
    {
        string linia;
        znajomy znajomyLokalny;
        string konwersjaStringNaInt;

        do
        {

            getline(plik,konwersjaStringNaInt,'|');

            znajomyLokalny.id=atoi( konwersjaStringNaInt.c_str());

            getline(plik,konwersjaStringNaInt,'|');

            znajomyLokalny.idUzytkownika=atoi( konwersjaStringNaInt.c_str());

            getline(plik,znajomyLokalny.imie,'|') ;

            getline(plik,znajomyLokalny.nazwisko,'|');

            getline(plik,znajomyLokalny.numerTelefonu,'|');

            getline(plik,znajomyLokalny.adres,'|');

            getline(plik,znajomyLokalny.email,'|');

            if (znajomyLokalny.id>najwiekszeID)
                najwiekszeID=znajomyLokalny.id;






        }
        while(getline(plik,linia));
        plik.close();
    }
    return najwiekszeID;
}
int przepiszDaneUzytkownikow(int liczbaLoginow)
{
    fstream plik;
    if(plik.good()==true)
        plik.open("Uzytkownicy.txt",ios::in);
    if(plik.good()==false)
    {

        ofstream plik( "Uzytkownicy.txt" );
        plik.open("Uzytkownicy.txt",ios::in);

    }
    else
    {
        string linia;
        uzytkownicy uzytkownikLokalny;
        uzytkownik.clear();
        string konwersjaStringNaInt;
        do
        {

            getline(plik,konwersjaStringNaInt,'|');

            uzytkownikLokalny.id=atoi( konwersjaStringNaInt.c_str());

            getline(plik,uzytkownikLokalny.login,'|') ;

            getline(plik,uzytkownikLokalny.haslo,'|');

            uzytkownik.push_back(uzytkownikLokalny);

            liczbaLoginow++;

        }
        while(getline(plik,linia));
        plik.close();
    }

    return liczbaLoginow;

}
int przepiszDane(int liczbaUzytkownikow,int idUzytkownika)
{
    fstream plik;
    if(plik.good()==true)
        plik.open("dane_adresowe.txt",ios::in);
    if(plik.good()==false)
    {
        return liczbaUzytkownikow;
    }
    else
    {
        string linia;
        znajomy znajomyLokalny;
        znajomi.clear();
        string konwersjaStringNaInt;
        do
        {

            getline(plik,konwersjaStringNaInt,'|');

            znajomyLokalny.id=atoi( konwersjaStringNaInt.c_str());

            getline(plik,konwersjaStringNaInt,'|');

            znajomyLokalny.idUzytkownika=atoi( konwersjaStringNaInt.c_str());

            getline(plik,znajomyLokalny.imie,'|') ;

            getline(plik,znajomyLokalny.nazwisko,'|');

            getline(plik,znajomyLokalny.numerTelefonu,'|');

            getline(plik,znajomyLokalny.adres,'|');

            getline(plik,znajomyLokalny.email,'|');
            if (znajomyLokalny.idUzytkownika==idUzytkownika)
            {


                znajomi.push_back(znajomyLokalny);
                liczbaUzytkownikow++;
            }





        }
        while(getline(plik,linia));
        plik.close();
    }
    return liczbaUzytkownikow;
}
void logowanie(int liczbaLoginow)
{
    string login, haslo;
    cout<<"Podaj login: ";
    cin>>login;
    cout<<"Podaj haslo: ";
    cin>>haslo;
    for (int i=0; i<liczbaLoginow; i++)
    {
        if(login==uzytkownik[i].login && haslo==uzytkownik[i].haslo)
        {
            cout<<"Zalogowano"<<endl;
            cout<<uzytkownik[i].id<<endl;
            system("pause");
            pokazMenu (uzytkownik[i].id, liczbaLoginow);
            break;
        }
    }

}

void zapiszUzytkownikowDoPliku(int liczbaLoginow)
{
    ofstream plik;
    plik.open("Uzytkownicy.txt",ios::out);
    if(plik.good()==true)

    {
        for (int i=0; i<liczbaLoginow; i++)
        {
            if (i==0)
                plik<<uzytkownik[i].id<<'|'<<uzytkownik[i].login<<'|'<<uzytkownik[i].haslo<<'|';
            else
                plik<<endl<<uzytkownik[i].id<<'|'<<uzytkownik[i].login<<'|'<<uzytkownik[i].haslo<<'|';
        }
        plik.close();
    }
}
int rejestracja(int liczbaLoginow)
{
    uzytkownicy uzytkownikLokalny;

    cout<<"Podaj login: ";
    cin>>uzytkownikLokalny.login;
    for (int i=0; i<liczbaLoginow; i++)
    {
        if(uzytkownikLokalny.login==uzytkownik[i].login )
        {
            i=0;
            cout<<"Uzytkownik wystepuje. Podaj inny login: "<<endl;
            cin>>uzytkownikLokalny.login;
        }
    }
    cout<<"Podaj haslo: ";
    cin>>uzytkownikLokalny.haslo;
    if(liczbaLoginow>0)
        uzytkownikLokalny.id=uzytkownik[liczbaLoginow-1].id+1;
    else
        uzytkownikLokalny.id=0;
    uzytkownik.push_back(uzytkownikLokalny);
    liczbaLoginow++;
    zapiszUzytkownikowDoPliku( liczbaLoginow);
    return liczbaLoginow;
}

void zapiszAdresyDoPliku(int liczbaUzytkownikow,int idUzytkownika)
{
    int liczbaWykorztstanychDanychZWektora=0;
    fstream plik;
    plik.open("dane_adresowe.txt",ios::in);
    if(plik.good()==true)
    {

        ofstream plikzapisu;
        plikzapisu.open("Adresaci_tymczasowy.txt",ios::out);
        string linia;
        znajomy znajomyLokalny;
        int liczbaDanych=0;
        string konwersjaStringNaInt;
        do
        {

            getline(plik,konwersjaStringNaInt,'|');

            znajomyLokalny.id=atoi( konwersjaStringNaInt.c_str());

            getline(plik,konwersjaStringNaInt,'|');

            znajomyLokalny.idUzytkownika=atoi( konwersjaStringNaInt.c_str());

            getline(plik,znajomyLokalny.imie,'|') ;

            getline(plik,znajomyLokalny.nazwisko,'|');

            getline(plik,znajomyLokalny.numerTelefonu,'|');

            getline(plik,znajomyLokalny.adres,'|');

            getline(plik,znajomyLokalny.email,'|');

            if(znajomyLokalny.idUzytkownika!=idUzytkownika)
            {
                if (liczbaDanych==0)
                    plikzapisu<<znajomyLokalny.id<<'|'<<znajomyLokalny.idUzytkownika<<'|'<<znajomyLokalny.imie<<'|'<<znajomyLokalny.nazwisko<<'|'<<znajomyLokalny.numerTelefonu<<'|'<<znajomyLokalny.adres<<'|'<<znajomyLokalny.email<<'|';
                else
                    plikzapisu<<endl<<znajomyLokalny.id<<'|'<<znajomyLokalny.idUzytkownika<<'|'<<znajomyLokalny.imie<<'|'<<znajomyLokalny.nazwisko<<'|'<<znajomyLokalny.numerTelefonu<<'|'<<znajomyLokalny.adres<<'|'<<znajomyLokalny.email<<'|';

                liczbaDanych++;
            }
            else
            {
                if (liczbaDanych==0)
                {
                    plikzapisu<<znajomi[liczbaWykorztstanychDanychZWektora].id<<'|'<<znajomi[liczbaWykorztstanychDanychZWektora].idUzytkownika<<'|'<<znajomi[liczbaWykorztstanychDanychZWektora].imie<<'|'<<znajomi[liczbaWykorztstanychDanychZWektora].nazwisko<<
                              '|'<<znajomi[liczbaWykorztstanychDanychZWektora].numerTelefonu<<'|'<<znajomi[liczbaWykorztstanychDanychZWektora].adres<<'|'<<znajomi[liczbaWykorztstanychDanychZWektora].email<<'|';
                    liczbaWykorztstanychDanychZWektora++;
                    liczbaDanych++;
                }
                else if (liczbaWykorztstanychDanychZWektora<liczbaUzytkownikow&&znajomi[liczbaWykorztstanychDanychZWektora].id<=znajomyLokalny.id)
                {
                    plikzapisu<< endl<<znajomi[liczbaWykorztstanychDanychZWektora].id<<'|'<<znajomi[liczbaWykorztstanychDanychZWektora].idUzytkownika<<'|'<<znajomi[liczbaWykorztstanychDanychZWektora].imie<<'|'<<znajomi[liczbaWykorztstanychDanychZWektora].nazwisko<<
                              '|'<<znajomi[liczbaWykorztstanychDanychZWektora].numerTelefonu<<'|'<<znajomi[liczbaWykorztstanychDanychZWektora].adres<<'|'<<znajomi[liczbaWykorztstanychDanychZWektora].email<<'|';
                    liczbaWykorztstanychDanychZWektora++;
                    liczbaDanych++;
                }
            }





        }
        while(getline(plik,linia));
        plik.close();


        for(int i=liczbaWykorztstanychDanychZWektora; i<liczbaUzytkownikow; i++)
        {
            if (liczbaDanych==0)
                plikzapisu<<znajomi[liczbaWykorztstanychDanychZWektora].id<<'|'<<znajomi[liczbaWykorztstanychDanychZWektora].idUzytkownika<<'|'<<znajomi[liczbaWykorztstanychDanychZWektora].imie<<'|'<<znajomi[liczbaWykorztstanychDanychZWektora].nazwisko<<
                          '|'<<znajomi[liczbaWykorztstanychDanychZWektora].numerTelefonu<<'|'<<znajomi[liczbaWykorztstanychDanychZWektora].adres<<'|'<<znajomi[liczbaWykorztstanychDanychZWektora].email<<'|';
            else
                plikzapisu<< endl<<znajomi[liczbaWykorztstanychDanychZWektora].id<<'|'<<znajomi[liczbaWykorztstanychDanychZWektora].idUzytkownika<<'|'<<znajomi[liczbaWykorztstanychDanychZWektora].imie<<'|'<<znajomi[liczbaWykorztstanychDanychZWektora].nazwisko<<
                          '|'<<znajomi[liczbaWykorztstanychDanychZWektora].numerTelefonu<<'|'<<znajomi[liczbaWykorztstanychDanychZWektora].adres<<'|'<<znajomi[liczbaWykorztstanychDanychZWektora].email<<'|';
            liczbaWykorztstanychDanychZWektora++;
            liczbaDanych++;
        }
        plikzapisu.close();
        remove ("dane_adresowe.txt");

        system("pause");
        rename  ( "Adresaci_tymczasowy.txt","dane_adresowe.txt");
    }

    else if(plik.good()==false)
    {

        ofstream plikzapisu;
        plikzapisu.open("Adresaci_tymczasowy.txt",ios::out);
        for (int i=0; i<liczbaUzytkownikow; i++)
        {
            if (i==0)
                plikzapisu<<znajomi[i].id<<'|'<<znajomi[i].idUzytkownika<<'|'<<znajomi[i].imie<<'|'<<znajomi[i].nazwisko<<'|'<<znajomi[i].numerTelefonu<<'|'<<znajomi[i].adres<<'|'<<znajomi[i].email<<'|';
            else
                plikzapisu<<endl<<znajomi[i].id<<'|'<<znajomi[i].idUzytkownika<<'|'<<znajomi[i].imie<<'|'<<znajomi[i].nazwisko<<'|'<<znajomi[i].numerTelefonu<<'|'<<znajomi[i].adres<<'|'<<znajomi[i].email<<'|';
        }
        plikzapisu.close();
        remove ("dane_adresowe.txt");
        system("pause");
        rename  ( "Adresaci_tymczasowy.txt","dane_adresowe.txt");
    }

}
int zapiszDane(int liczbaUzytkownikow,int idUzytkownika)
{
    string imie, nazwisko,numerTelefonu,adres,email;
    cout<<"Podaj imie: ";
    cin>>imie;
    cout<<"Podaj nazwisko: ";
    cin>>nazwisko;

    int i=0;
    while (i<liczbaUzytkownikow)
    {
        if(znajomi[i].imie==imie&&znajomi[i].nazwisko==nazwisko&&znajomi[i].idUzytkownika==idUzytkownika)
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
    znajomy znajomyLokalny;

    znajomyLokalny.id=pokazNajwiekszeID()+1;


    znajomyLokalny.idUzytkownika=idUzytkownika;
    znajomyLokalny.imie=imie;
    znajomyLokalny.nazwisko=nazwisko;
    znajomyLokalny.numerTelefonu=numerTelefonu;
    znajomyLokalny.adres=adres;
    znajomyLokalny.email=email;
    if(liczbaUzytkownikow>=0)
        znajomi.push_back(znajomyLokalny);
    zapiszAdresyDoPliku(liczbaUzytkownikow+1, idUzytkownika);
    return liczbaUzytkownikow+1;

}


void pokazanieWszystkichDanych(int liczbaUzytkownikow, int idUzytkownika)
{


    for(int i=0; i<liczbaUzytkownikow; i++)
    {
        if(idUzytkownika==znajomi[i].idUzytkownika)
        {
            pokazUzytkownika ( i);
        }

    }
    system("pause");

}
void wyszukiwaniePoNazwisku(int liczbaUzytkownikow, int idUzytkownika)
{
    string nazwisko;
    bool czy_nazwisko;
    czy_nazwisko=false;
    cout<<"Podaj nazwisko: ";
    cin>>nazwisko;
    for(int i=0; i<liczbaUzytkownikow; i++)
    {
        if (znajomi[i].nazwisko==nazwisko && znajomi[i].idUzytkownika==idUzytkownika)
        {
            pokazUzytkownika (i);
            czy_nazwisko=true;
        }
    }
    if(czy_nazwisko==false)
    {
        cout<<"Brak znajomych o takim nazwisku"<<endl;
    }
    system("pause");

}
void wyszukiwaniePoImieniu(int liczbaUzytkownikow, int idUzytkownika)
{
    string imie;
    bool czy_imie;
    czy_imie=false;
    cout<<"Podaj imie: ";
    cin>>imie;
    for(int i=0; i<liczbaUzytkownikow; i++)
    {
        if (znajomi[i].imie==imie && znajomi[i].idUzytkownika==idUzytkownika)
        {
            pokazUzytkownika (i);
            czy_imie=true;
        }
    }
    if(czy_imie==false)
    {

        cout<<"Brak znajomych o takim imieniu"<<endl;
    }
    system("pause");
}
void edytujKontakt(int liczbaUzytkownikow, int idUzytkownika)
{
    int id;
    int numerUzytkownika;
    cout<<"Podaj id: ";
    cin>>id;
    int i =0;
    while(true)
    {
        if (id==znajomi[i].id&& idUzytkownika==znajomi[i].idUzytkownika)
        {
            numerUzytkownika=i;
            break;
        }

        else if (id==znajomi[i].id&& idUzytkownika!=znajomi[i].idUzytkownika)
        {
            cout<<"Odmowa dostępu. Podaj inne id: ";
            cin>>id;
            i=0;
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
    zapiszAdresyDoPliku(liczbaUzytkownikow, idUzytkownika);

}
int usunKontakt(int liczbaUzytkownikow, int idUzytkownika)
{
    int id;
    int numerUzytkownika;
    cout<<"Podaj id: ";
    cin>>id;
    int i =0;
    while(true)
    {
        if (id==znajomi[i].id&& idUzytkownika==znajomi[i].idUzytkownika)
        {
            numerUzytkownika=i;
            break;
        }
        else if (id==znajomi[i].id&& idUzytkownika!=znajomi[i].idUzytkownika)
        {
            cout<<"Odmowa dostepu. Podaj inne id: ";
            cin>>id;
            i=0;
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
        zapiszAdresyDoPliku(liczbaUzytkownikow-1, idUzytkownika);
        return liczbaUzytkownikow-1;
    }
    return liczbaUzytkownikow;
}
void zmienHaslo(int liczbaLoginow,int idUzytkownika)
{
    string haslo;
    cout<<"Podaj nowe haslo: ";
    cin>> haslo;
    for(int i=0; i<liczbaLoginow; i++)
    {
        if (uzytkownik[i].id==idUzytkownika)
        {
            uzytkownik[i].haslo=haslo;
            break;
        }
    }
    zapiszUzytkownikowDoPliku( liczbaLoginow);
}
int rozmiarDanych ()
{
    fstream plik;

    plik.open("dane_adresowe.txt",ios::in);
    int liczbaLinii=0;
    if(plik.good()==true)
    {
        string linia;

        while (getline(plik,linia))
            liczbaLinii++;

    }
    return liczbaLinii;
}


void pokazMenu(int idUzytkownika,int liczbaLoginow)

{
    int liczbaUzytkownikow=0;
    char wybor;
    liczbaUzytkownikow=przepiszDane(liczbaUzytkownikow, idUzytkownika);


    while (1)
    {
        system("cls");
        cout<<"1. Zapisz dane"<<endl;
        cout<<"2. Wyszukaj po nazwisku"<<endl;
        cout<<"3. Wyszukaj po imieniu"<<endl;
        cout<<"4. Pokaz wszystkie dane"<<endl;
        cout<<"5. Usun dane"<<endl;
        cout<<"6. Edytuj dane"<<endl;
        cout<<"7. Zmien haslo"<<endl;
        cout<<"8. Wyloguj sie"<<endl;

        cin>>wybor;

        if(wybor=='1')
        {
            liczbaUzytkownikow=zapiszDane(liczbaUzytkownikow,idUzytkownika);

        }
        else if(wybor=='2')
        {
            wyszukiwaniePoNazwisku(liczbaUzytkownikow,idUzytkownika);
        }
        else if(wybor=='3')
        {

            wyszukiwaniePoImieniu(liczbaUzytkownikow,idUzytkownika);
        }
        else if(wybor=='4')
        {

            pokazanieWszystkichDanych( liczbaUzytkownikow,idUzytkownika);
        }
        else if(wybor=='5')
        {
            liczbaUzytkownikow=usunKontakt(liczbaUzytkownikow,idUzytkownika);

        }
        else if(wybor=='6')
        {
            edytujKontakt(liczbaUzytkownikow,idUzytkownika);

        }
        else if(wybor=='7')
        {
            zmienHaslo(liczbaLoginow,idUzytkownika);

        }

        else if(wybor=='8')
        {

            break;

        }
    }
}
int main()
{
    int liczbaLoginow=0;
    int idLogowania;
    liczbaLoginow=przepiszDaneUzytkownikow(liczbaLoginow);
    while (1)


    {
        char wybor;
        system("cls");
        cout<<"1. Logowanie"<<endl;
        cout<<"2. Rejestracja"<<endl;
        cout<<"3. Zamknij program"<<endl;
        cin>>wybor;

        if(wybor=='1')
        {

            logowanie(liczbaLoginow);
        }
        else if(wybor=='2')
        {
            liczbaLoginow=rejestracja(liczbaLoginow);
        }
        else if(wybor=='3')
        {

            exit(0);
        }
    }
}
