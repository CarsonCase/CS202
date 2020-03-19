#include "MyString.h"
MyString::MyString() {
	buffer_allocate(0);			//Allocate 0 memory
	m_size = 0;
}
MyString::MyString(const char* str) {
	m_size = strlen(str);
	buffer_allocate(m_size + 1);		//Set the allocated memory to the size of the string
	strcpy(m_buffer, str);			
}
MyString::MyString(const MyString& other) {
	m_size = other.m_size;
	buffer_allocate(m_size + 1);		//Allocate the same ammount of memory that other has
	strcpy(m_buffer, other.m_buffer);
}
MyString::~MyString() {
	buffer_deallocate();
}

size_t MyString::size() const{
	return m_size+1;
}
size_t MyString::length() const {
	return m_size;
}
const char* MyString::c_str() const{
	return m_buffer;
}

bool MyString::operator==(const MyString& other) const {
	if (strcmp(other.m_buffer, m_buffer)==0) {
		return true;
	}
	else {
		return false;
	}
}
MyString& MyString::operator= (const MyString& other) {
	m_size = other.m_size;
	buffer_deallocate();
	buffer_allocate(m_size+1);
	strcpy(m_buffer, other.m_buffer);
	return *this;
}
MyString MyString::operator+ (const MyString& other_myStr) const {
	//Creates a temp c-string that has the current buffer coppied to it. Then the other_myStr buffer is concated on top of it
	char* temp;		//Max size is set to 256. Will work to make this dynamic
	temp = new char[m_size + other_myStr.m_size+1];
	strcpy(temp, m_buffer);
	strcat(temp, other_myStr.m_buffer);
	MyString output(temp);
	delete[] temp;
	return output;
}

char& MyString::operator[] (size_t index) const {
	return m_buffer[index];
}
std::ostream& operator<< (std::ostream& os, const MyString& myStr) {
	os << myStr.m_buffer;
	return os;
}

//Buffer allocate/deallocate functions 

void MyString::buffer_allocate(size_t size) {
	try {
		m_buffer = new char[size];
	}
	catch (std::exception& e) {
		std::cout << e.what();
	}
}
void MyString::buffer_deallocate() {
	delete[] m_buffer;
}