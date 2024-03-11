#include "Member.h"

Member::Member(const std::string& name)
{
	m_name = name;
	m_booksBorrowed = 0;
}

void Member::borrowBook()
{
	m_booksBorrowed++;
}

void Member::returnBook()
{
	if (m_booksBorrowed > 0)
		m_booksBorrowed--;
	else
		std::cout << "Brak wypozyczonych ksiazek";
}

std::ostream& operator<<(std::ostream& os, const Member& other)
{
	if (&other)
	{
		std::cout << std::endl;
		std::cout << "---------------------------" << std::endl;
		os << "Member name: " << other.m_name << std::endl;
		os << "Member books borrowed: " << other.m_booksBorrowed << std::endl;
		std::cout << "---------------------------" << std::endl;
	}
	else
	{
		std::cout << "---------------------------" << std::endl;
		os << "Brak wlasciciela" <<std::endl;
		std::cout << "---------------------------" << std::endl;
	}
	
	return os;
}
