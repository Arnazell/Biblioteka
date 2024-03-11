#pragma once
#include <iostream>
#include "Member.h"

class Book
{
private:
	std::string m_Title;
	std::string m_author;
	std::string m_ISBN;
	Member* m_owner;
	
	bool m_avaliable;

public:

	Book(const std::string& title, const std::string& author, const std::string& isbn);

	// wypisuje napis "nieszcze ksiazke"
	~Book();
	
	//drukowanie informajci o ksiazce w konsoli
	void getInfo() const;

	//zwaca ISBN
	const std::string& getISBN() const;

	// jesli ksiazka jest wypozyczona ma ustawionego wlasciciela
	void setOwner(Member* newOwner);

	// majac ksiazke mozemy dowiedziec sie kto jest w jej posiadaniu
	const Member& getOwner() const;

	// library sprawdza czy dana ksiazka zgadza sie z
	friend class Library;
};