#include "Car.h"
#include "Sensor.h"
#include <iostream>
Car::Car() {
	myStringCopy(m_make, "");
	myStringCopy(m_model, "");
	m_year = 0;
	m_baseprice = 0;
	m_finalprice = 0;
	m_available = false;
	myStringCopy(m_owner, "");
}

Car::Car(char* make, char* model, int year, float baseprice, Sensor sensors[3]) {
	myStringCopy(m_make, make);
	myStringCopy(m_model, model);
	m_year = year;
	m_baseprice = baseprice;
	for (int i = 0; i < 3; i++) {
		m_sensors[i] = sensors[i];
	}
}
Car::Car(Car* c1) {
	myStringCopy(m_make, c1->m_model);
	myStringCopy(m_model, c1->m_model);
	m_year = c1->m_year;
	m_baseprice = c1->m_baseprice;
	for (int i = 0; i < 3; i++) {
		m_sensors[i] = c1->m_sensors[i];
	}
}

char* Car::getMake() {
	return m_make;
}
char* Car::getModel() {
	return m_model;
}
int Car::getYear() {
	return m_year;
}
Sensor* Car::getSensors() {
	return m_sensors;
}
float Car::getBasePrice() {
	return m_baseprice;
}
float Car::getFinalPrice() {
	return m_finalprice;
}
bool Car::getAvailable() {
	return m_available;
}
char* Car::getOwner() {
	return m_owner;
}
void Car::setMake(char* make) {
	myStringCopy(m_make, make);
}
void Car::setModel(char* model) {
	myStringCopy(m_model, model);
}
void Car::setYear(int year) {
	m_year = year;
}
void Car::setBasePrice(float basePrice) {
	m_baseprice = basePrice;
}
void Car::setAvailable(bool available) {
	m_available = available;
}
void Car::setOwner(char* owner) {
	myStringCopy(m_owner, owner);
}

void Car::updatePrice() {
	int price=0;
	for (int i = 0; i < 3; i++) {
		char comp = *(m_sensors[i].getType());
		switch (comp) {
		case'g':
			price += 5;
		case'c':
			price += 10;
		case'l':
			price += 15;
		case'r':
			price += 20;
		}
	}
	m_finalprice = price;
}
float Car::estimateCost(int days) {
	return days * m_finalprice;
}
void Car::print() {
	std::cout << "Make: " << m_make << " Model: " << m_model << " Year: " << m_year << " Base Price: $" << m_baseprice <<" Final Price $"<< m_finalprice << " Available: " << (m_available ? "True" : "False") << " Owner: " << m_owner << std::endl;
}
bool Car::operator+(Sensor s) {
	for (int i = 0; i < 3; i++) {
		if (*(m_sensors[i].getType()) == 'n') {
			//std::cout << i << std::endl;
			m_sensors[i] = s;
			return true;
		}
	}
	return false;
}
void Car::operator+(char* lease) {
	myStringCopy(m_owner, lease);
}
void Car::myStringCopy(char destination[256], const char source[256]) {
	int count = 0;
	for (int i = 0; source[i] != '\0'; i++) {
		destination[i] = source[i];
		count = i;
	}
	destination[count + 1] = '\0';
}