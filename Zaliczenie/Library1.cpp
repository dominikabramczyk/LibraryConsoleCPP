#include <iostream>
#include "Employee.h"
#include "Student.h"
#include "Book.h"
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include <ctime>
#include <list>
using namespace std;

string GetName()
{
	string _name;
	cout << "Podaj imie: ";
	cin >> _name;
	return _name;
}

string GetSurname()
{
	string _surename;
	cout << "Podaj nazwisko: ";
	cin >> _surename;
	return _surename;
}

int GetRandomNumber()
{
	return (std::rand() % 1000 ) + 1;
}

Student RegisterStudent()
{
	int number = GetRandomNumber();
	string name = GetName();
	string surename = GetSurname();
	Student Student(name, surename, number );
	return Student;
}

Employee RegisterEmployee()
{
	string name = GetName();
	string surename = GetSurname();
	Employee Employee(name , surename);
	return Employee;
}
void DisplayEmployee(Employee Employee)
{
	cout << "Zarejestrowano pracownika!\n Imie: " << Employee.Name << "\nNazwisko: " << Employee.Surename << endl;
	system("Pause");
}

void DisplayStudent(Student Student )
{
	cout << "Zarejestrowano studenta!\n Imie: " << Student.Name << "\nNazwisko: " << Student.Surename << "\nNumer Albumu: " << Student.AlbumNumber << endl;
	system("Pause");
}
 
 list<Book> CreateBooks()
{	
	 list<Book>ListBook;
	 ListBook.push_back(Book("Calineczka", "Morawiecki"));
	 ListBook.push_back(Book("Szepty spoza nicości", "Mroz")); 
	 ListBook.push_back(Book("Ratownik", "Mitra"));
	 ListBook.push_back(Book("Piec stawow", "Sabala-Zielinska"));
	 ListBook.push_back(Book("Powrot z Bambuko", "Nosowaska"));
	 ListBook.push_back(Book("Jak pozbyc sie mendy", "Marian Pazdzioch"));
	 ListBook.push_back(Book("Jak nie przegrac wyborow", "Trump"));
	 ListBook.push_back(Book("Dzien", "Kiepski"));

	 return ListBook;
}

 Book AddBook()
 {
	 string title, author;
	 system("cls");
	 cout << "\tDodawanie ksiazki\nPodaj tytul: ";
	 cin >> title;
	 cout << "\nPodaj autora: ";
	 cin >> author;
	 return Book(title, author);
 }

 int SelectBook(list<Book>ListBook)
 {
	 system("cls");
	 int choice;
	 int LenghtList = ListBook.size();
	 cout << "\tLista dostepnych ksiazek: \n";
	 int i = 0;
	 for (std::list<Book>::iterator it = ListBook.begin(); it != ListBook.end(); ++it)
	 {
		 Book item = *it;
		 if (item.IsRent == false)
		 {
			 cout << i+1 << ". \" " << item.Title << " \" - " << item.Author << endl;
			 i++;
		 }
	 }
	 cout << "Ktora ksiazke chcesz wypozyczyc(1-" << i  << "): \n";
	 cin >> choice;
	 return choice;
 }
 int SelectReturnBook(list<Book>ListBook)
 {
	 system("cls");
	 int choice;
	 int LenghtList = ListBook.size();
	 cout << "\tLista dostepnych ksiazek: \n";
	 int i = 0;
	 for (std::list<Book>::iterator it = ListBook.begin(); it != ListBook.end(); ++it)
	 {

		 Book item = *it;
		 if (item.IsRent == true)
		 {
			 cout << i + 1 << ". \" " << item.Title << " \" - " << item.Author << endl;
			 i++;
		 }
	 }
	 cout << "Ktora ksiazke oddajesz (1-" << i << "): \n";
	 cin >> choice;
	 return choice;
 }

 list<Book> EditList(list<Book>oldlist,int choice)
 {
	 list<Book>newlist;
	 system("cls");
	 int LenghtList = oldlist.size();
	 int i = 1;
	 for (std::list<Book>::iterator it = oldlist.begin(); it != oldlist.end(); ++it)
	 {
		 Book item = *it;
		 if (choice == i)
		 {
			 item.IsRent = true;
			 newlist.push_back(item);
		 } 
		 else 
		 {
			 newlist.push_back(item);
		 }
		 i++;
	 }
	 return newlist;
 }
 list<Book> EditReturnList(list<Book>oldlist, int choice)
 {
	 list<Book>newlist;
	 system("cls");
	 int LenghtList = oldlist.size();
	 int i = 1;
	 for (std::list<Book>::iterator it = oldlist.begin(); it != oldlist.end(); ++it)
	 {

		 Book item = *it;
		 if (choice == i)
		 {
			 item.IsRent = false;
			 newlist.push_back(item);
		 }
		 else
		 {
			 newlist.push_back(item);
		 }

		 i++;

	 }

	 return newlist;

 }
 list<Book> RentBook(list<Book>books)
 {
	int choice = SelectBook(books);
	return EditList(books,choice);
 }
 list<Book> ReturnBook(list<Book>books)
 {
	 int choice = SelectReturnBook(books);
	 return EditReturnList(books, choice);
 }

int main()
{
	list<Book>CollectionOfBooks = CreateBooks();

	while (true){	
		system("cls");
		int a; // a - variable  to switch
		cout << "-*-*-*-*-*-*-*-*-*\n\tMENU\n-*-*-*-*-*-*-*-*-*\n\n1.Rejestracja studentow\n2.Rejestracja pracownikow\n3.Dodaj nowa ksiazke\n4.Wypozycz ksiazke\n5.Oddaj ksiazke\n6.Zamknij program\n\n";
		cin >> a;
		
		cin.clear();
		cin.ignore();

		switch (a)
		{
		case 1: { //Rejestracja studentow
			Student Student = RegisterStudent();
			DisplayStudent(Student);
			
		}break;
		case 2: { //Rejestracja pracownikow
			Employee Employee = RegisterEmployee();
			DisplayEmployee(Employee);

		}break;
		case 3: { //Dodaj nowa ksiazke
			CollectionOfBooks.push_back(AddBook());

		}break;
		case 4: { //Wypozycz ksiazke
			CollectionOfBooks = RentBook(CollectionOfBooks);

		}break;
		case 5: { //oddawanie ksiazek
			CollectionOfBooks = ReturnBook(CollectionOfBooks);
			
		}break;
		case 6: {
			cout << "\n\n\tDziekujemy za skorzystanie z naszych uslug!!\n\n\n\n\n";
			exit(0);
		}break;

		/*default: {
			cout << "Wybrano nie poprawna instrukcje";
		}
			   break;*/
		}

		cout << "\n\n\tDziekujemy za skorzystanie z naszych uslug!!\n\n\n\n\n";

	};
}