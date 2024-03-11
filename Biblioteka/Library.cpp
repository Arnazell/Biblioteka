#include "Library.h"


Library::Library()
{
	// aby uniknac kopiowania w przypadku zbyt wczesnego braku miejsca
	books.reserve(15);
}

void Library::addBook(Book& b)
{
	books.emplace_back(&b);
}

void Library::removeBook(Book& b)
{
	// szukamy ksiazki ktora ma ISBN ktory chcemy usunac
	for (int i = 0; i < books.size(); i++)
	{
		if (books[i]->getISBN() == b.getISBN())
		{
			// usuwamy ksiazke
			books.erase(books.begin() + i);
			return;
		}
	}
	// jesli nie znajdziemy zwracamy informacje
	std::cout << "Nie znaleziono takiej ksiazki" << std::endl;
}

void Library::borrowBook(Member& member, const std::string& isbn)
{
	// szukamy ksiazki ktora ma ISBN ktory chcemy wypozyczyc
	for (int i = 0; i < books.size(); i++)
	{
		if (books[i]->getISBN() == isbn)
		{
			// jesli sie da to wypozyczamy
			if (books[i]->m_avaliable == true)
			{
				books[i]->m_avaliable = false;
				member.borrowBook();
				books[i]->setOwner(&member);
			}
			// w przeciwnym przypadku wyswietl komunikat
			else
			{
	
				std::cout << std::endl << "Ksiazka nie jest dostepna do wypozyczenia" << std::endl;
				std::cout << "Obecnie jest w posiadaniu: " << books[i]->getOwner();
			}
			return;
		}
	}
	// jesli nie znalesiono ksiazki zwracamy informacje
	std::cout << "Nie znaleziono takiej ksiazki" << std::endl;
}

void Library::returnBook(Member& member, const std::string& isbn)
{
	// szukamy ksiazki
	for (int i = 0; i < books.size(); i++)
	{
		// znaleslizmy
		if (books[i]->getISBN() == isbn)
		{
			// jesli jej wlascicielem byla podana osoba
			if ((books[i]->m_avaliable == false) && (books[i]->getOwner().m_name == member.m_name))
			{
				books[i]->m_avaliable = true;
				books[i]->setOwner(nullptr);
				member.returnBook();
			}
			// w przeciwnym przypadku wyswietl komunikat ze jej wlascicielem nie jest podana osoba
			else
			{
				std::cout << std::endl << "Sprawdz czy na pewno ta osoba wypozyczyla ta ksiazke" << std::endl;
			}
			return;
		}
	}
	// jesli nawet nie znajdziemy ksazki
	std::cout << "Nie znaleziono takiej ksiazki" << std::endl;
}
void Library::displayBooks() const
{
	for (int i = 0; i < books.size(); i++)
	{
		books[i]->getInfo();
	}
}
