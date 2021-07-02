#include "Book.h"
#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;

Book::Book(string t, string a)
{
	Title = t;
	Author = a;
	IsRent = false;
}



void Book::RentBook()
{
	int BookNumber;
		cout << "\nWybierz jaka ksiazke chcesz wypozyczyc: \n1.'Nawyki warte miliony'\n2.'Umysl milionera'\n3.'Wlam sie do mozgu'\n4.'Silniejszy kazdego dnia'\n5.'Mysl jak oszust, zeby nie dac sie oszukac'\n\n";
		cin >> BookNumber;
		system("cls");
		switch (BookNumber)
		{
		case 1:
			{
			cout << "\nWypozyczyles ksiazke: 'Nawyki warte miliony'\n";
			}break;
		case 2:
			{
			cout << "\nWypozyczyles ksiazke: 'Umysl milionera'\n";
			}break;
		case 3:
			{
			cout << "\nWypozyczyles ksiazke: 'Wlam sie do mozgu'\n";
			}break;
		case 4:
			{
			cout << "\nWypozyczyles ksiazke: 'Silniejszy kazdego dnia'\n";
			}break;
		case 5:
			{
			cout << "\nWypozyczyles ksiazke: 'Mysl jak oszust, zeby nie dac sie oszukac'\n";
			}break;
		default:
			break;

		
		}
};

void Book::ReturnBook()
{
	string BookName;

	cout << "Podaj tytul zwracanej ksiazki: \n";
	cin >> BookName;
	cout << "Ksiazka '" << BookName << "' zostala zwrocona pomyslnie.";

};