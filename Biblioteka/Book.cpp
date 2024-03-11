#include "Book.h"

// Konstruktor
Book::Book(const std::string& title, const std::string& author, const std::string& isbn)
	: m_Title(title), m_author(author), m_ISBN(isbn), m_avaliable(true), m_owner(nullptr)
{
}

// Destruktor
Book::~Book() { std::cout << "Niszcze ksiazke!" << std::endl; }

// GetInfo
void Book::getInfo() const
{
	std::cout << std::endl;
	std::cout << "---------------------------" << std::endl;
	std::cout << "Tytul: " << m_Title << std::endl;
	std::cout << "Autor: " << m_author << std::endl;
	std::cout << "Isbn: " << m_ISBN << std::endl;

	//jesli ma wlasciciela
	if (m_owner)
	{
		std::cout << "Wypozyczona przez: " << m_owner->m_name << std::endl;
	}
	else
		std::cout << "Mozliwa do wypozyczenia" << std::endl;

	std::cout << "---------------------------" << std::endl;
	
}

const Member& Book::getOwner() const
{
	return *m_owner;
}

const std::string& Book::getISBN() const
{
	return m_ISBN;
}

void Book::setOwner(Member* newOwner) 
{
	m_owner = newOwner;
}