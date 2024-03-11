#pragma once
#include <iostream>

class Member
{
public:
	std::string m_name;
	unsigned int m_booksBorrowed;

public:
	Member(const std::string& name);
	void borrowBook();
	void returnBook();

	friend std::ostream& operator<<(std::ostream& os, const Member& other);
};