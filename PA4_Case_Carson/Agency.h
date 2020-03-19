#pragma once
#include "Car.h"
class Agency
{
private:
	char m_name[256];
	const int m_zipcode;
	Car m_inventory[5];
	void myStringCopy(char destination[256], const char source[256]);
	void removeBracket(char x[256], char r[256]);

public:
	Agency();
	char* getName();
	const int getZip();
	void setName(char name[256]);
	void setInventory(Car cars[5]);
	Car operator[](int i);
	void readAllData(char* file);
	void printAllData();
	void printAvailableCars();
	void rentMostExpensive();
};

