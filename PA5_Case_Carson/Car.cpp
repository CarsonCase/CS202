#include "Car.h"
#include <iostream>
Car::Car() {
	std::cout << "Car#"<<m_vin<<": Default-ctor" << std::endl;
	m_throttle = 0;
}
Car::Car(char* plates, const int vin, float* lla) :Vehicle(vin,lla) {
	m_plates = plates;
	m_throttle = 0;
	m_lla[0] = *lla++;
	m_lla[1] = *lla++;
	m_lla[2] = *lla++;
	std::cout << "Car#"<<m_vin<<": Parametrized-ctor" << std::endl;
}
Car::Car(Car& copy) {
	strCopy(m_plates, copy.m_plates);
	m_throttle = copy.m_throttle;
}
Car::~Car() {
	delete this;
}
Car Car::operator =(Car& copy) {
	strCopy(m_plates, copy.m_plates);
	m_throttle = copy.m_throttle;
}
void Car::setPlates(char* plates) {
	strCopy(plates, m_plates);
}
void Car::setThrottle(int throttle) {
	m_throttle = throttle;
}
char* Car::getPlates() {
	return m_plates;
}
int Car::getThrottle() {
	return m_throttle;
}

void Car::drive(int throttle) {
	m_throttle = throttle;
}

void Car::move(float* lla) {
	m_lla[0] = lla[0];
	m_lla[1] = lla[1];
	m_lla[2] = lla[2];
	std::cout << "Car#"<<m_vin<<": DRIVE to destination, with throttle @ "<<m_throttle << std::endl;
}

void Car::operator>>(Car& copy) {
	std::cout << "Car#"<<m_vin<<" Plates : "<<m_plates<<", Throttle : "<<m_throttle<<" @["<<m_lla[0]<<", "<<m_lla[1]<<", "<<m_lla[2]<<"]" << std::endl;
}

//Utility string copy function
void Car::strCopy(char* destination, const char* source) {
	while (*source != '\0')
	{
		*destination = *source;
		destination++;
		source++;
	}
	*destination = '\0';
}
