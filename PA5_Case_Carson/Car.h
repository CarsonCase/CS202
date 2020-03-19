#pragma once
#ifndef CAR_H
#define CAR_H
#include "Vehicle.h"
//Derived class
class Car : public Vehicle
{
private:
	//private members
	char* m_plates;
	int m_throttle;
	//Utility myStringCopy function
	void strCopy(char* destination, const char* source);

public:
	//Constructors/Destructors
	Car();
	Car(char* plates, int vin, float * lla);
	Car(Car& copy);
	~Car();
	//assignment operator
	Car operator =(Car &copy);
	//get/set methods
	void setPlates(char* m_plates);
	void setThrottle(int throttle);
	char* getPlates();
	int getThrottle();
	//functional methods
	void drive(int throttle);
	void move(float* lla);
	void operator>>(Car& copy);
};
#endif CAR_H
