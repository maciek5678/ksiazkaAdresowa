#include <iostream>
#include <fstream>
#include <cstdlib>
#include <windows.h>
#include <string>
#include <vector>
#include <conio.h>
#include <cstdio>


using namespace std;
class Uzytkownicy
{

    string login;
    string haslo;
public:

    int id;
    void zapiszUzytkownikowDoPliku(int liczbaLoginow, vector<Uzytkownicy> &uzytkownik);
    int przepiszDaneUzytkownikow(int liczbaLoginow, vector<Uzytkownicy> &uzytkownik);
    void logowanie(int liczbaLoginow, vector<Uzytkownicy> &uzytkownik);
    int rejestracja(int liczbaLoginow, vector<Uzytkownicy> &uzytkownik);
    friend void zmienHaslo(int liczbaLoginow,int idUzytkownika, vector<Uzytkownicy> &uzytkownik);



};

void pokazMenu(int idUzytkownika,int liczbaLoginow, vector<Uzytkownicy> &uzytkownik);


