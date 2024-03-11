#pragma once
#include <iostream>
#include <vector>
#include "Book.h"
#include "Member.h"

// Klasa Library zawiera dynamiczn� tablic� z wska�nikami na obiekty ksiazka (aby unikn�� ich kopiowania) i metody do zarz�dzania nimi
class Library
{
private:
	std::vector<Book*> books;

public:

	// konstruktor nie robi nic poza drobn� optymalizacj� tablicy
	Library();

	// dodanie ksiazki do bilbioteki
	void addBook(Book& b);

	// usuniecie ksiazki z biblioteki UWAGA: ksiazka istnieje i dalej nalezy do danego uzytkownika
	void removeBook(Book& b);

	// wypozyczenie ksiazki uzytkownikowi
	void borrowBook(Member& member, const std::string& isbn);

	// zwrocenie ksiazki 
	void returnBook(Member& member, const std::string& isbn);

	// wyswietlenie ksiazek
	void displayBooks() const;

};

