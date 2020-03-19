#pragma once
#include <iostream>
class Car
{
private:
	int m_year;
	char m_make[50];
	char m_model[50];
	float m_price;
	bool m_available;
	void myStringCopy(char* destination, const char* source);
public:
	Car();
	Car(int year, char* make, char* model, float price, bool available);

	int getYear();
	char* getMake();
	char* getModel();
	float getPrice();
	bool getAvailable();

	void setYear(int y);
	void setMake(char* m);
	void setModel(char* m);
	void setPrice(float p);
	void setAvailable(bool a);

	void print();
	void estimateCost(int days);
};

