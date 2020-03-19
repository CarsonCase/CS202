#pragma once
#include "Sensor.h"
class Car
{
private:
	char m_make[256];
	char m_model[256];
	int m_year;
	Sensor m_sensors[3];
	float m_baseprice;
	float m_finalprice;
	bool m_available;
	char m_owner[256];

	void myStringCopy(char destination[256], const char source[256]);

public:
	Car();
	Car(char* make, char* model, int year, float baseprice, Sensor sensors[3]);
	Car(Car* c1);
	//Get/Set Bullshit
	char* getMake();
	char* getModel();
	int getYear();
	Sensor* getSensors();
	float getBasePrice();
	float getFinalPrice();
	bool getAvailable();
	char* getOwner();
	void setMake(char* make);
	void setModel(char* model);
	void setYear(int year);
	void setBasePrice(float basePrice);
	void setAvailable(bool available);
	void setOwner(char* owner);
	//Start of other methods
	void updatePrice();
	void print();
	float estimateCost(int days);
	// Overload
	bool operator+(Sensor s);
	void operator+(char* lease);
};

