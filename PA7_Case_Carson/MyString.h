#pragma once
#include <fstream>
#include <iostream>
#include <cstring>
class MyString
{
public:
	MyString();
	MyString(const char* str);
	MyString(const MyString& other);
	~MyString();

	size_t size() const;
	size_t length() const;
	const char* c_str() const;
	bool operator== (const MyString& other) const;
	MyString & operator= (const MyString& other);
	MyString operator+ (const MyString& other_myStr) const;
	char& operator[] (size_t index) const;

friend std::ostream& operator<< (std::ostream& os, const MyString& myStr);

private:
	void buffer_deallocate();
	void buffer_allocate(size_t size);

	char* m_buffer;
	size_t m_size;
};

