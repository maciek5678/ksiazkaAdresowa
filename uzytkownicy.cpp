#include <iostream>
#include <fstream>
#include <cstdlib>
#include <windows.h>
#include <string>
#include <vector>
#include <conio.h>
#include <cstdio>
#include "uzytkownicy.h"
using namespace std;
int Uzytkownicy::przepiszDaneUzytkownikow(int liczbaLoginow, vector<Uzytkownicy> &uzytkownik)
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
        Uzytkownicy uzytkownikLokalny;
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
void Uzytkownicy::logowanie(int liczbaLoginow, vector<Uzytkownicy> &uzytkownik)
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
            pokazMenu (uzytkownik[i].id, liczbaLoginow, uzytkownik);
            break;
        }
    }

}
void Uzytkownicy::zapiszUzytkownikowDoPliku(int liczbaLoginow, vector<Uzytkownicy> &uzytkownik)
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

int Uzytkownicy::rejestracja(int liczbaLoginow, vector<Uzytkownicy> &uzytkownik)
{
    Uzytkownicy uzytkownikLokalny;

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
    uzytkownikLokalny.zapiszUzytkownikowDoPliku( liczbaLoginow,uzytkownik);
    return liczbaLoginow;
}
