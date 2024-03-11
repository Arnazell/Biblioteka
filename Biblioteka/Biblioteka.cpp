#include <iostream>
#include "Book.h"
#include "Member.h"
#include "Library.h"


int main()
{
    Book b1("Pan Tadeusz", "Adam Mickiewicz", "11111111111");
    Book b2("1974", "George Orwell", "1111111112");
    Book b3("Trzy Stygmaty Palmera Eindricha", "Philip K. Dick", "1111111113");
    Book b4("Ubik", "Philip K. Dick", "1111111114");
    Book b5("Dzuma", "Albert Camus", "1111111115");
    Book b6("Obcy", "Albert Camus", "1111111116");

    Member m1("Janek");
    Member m2("Bartek");
    Library biblioteka;
    biblioteka.addBook(b1);
    biblioteka.addBook(b2);
    biblioteka.addBook(b3);
    biblioteka.addBook(b4);
    biblioteka.addBook(b5);
    biblioteka.addBook(b6);

    biblioteka.borrowBook(m1, "1111111116");
    std::cout << b6.getOwner();

    biblioteka.returnBook(m1, "1111111116");
    std::cout << b6.getOwner();



}

