#include "Car.h"

Car::Car(){
	Car::m_year = 0000;
	Car::m_make;
	Car::m_model;
	Car::m_price = 0;
	Car::m_available = false;
}

Car::Car(int year, char* make, char* model, float price, bool available) {
	m_year = year;
	myStringCopy(m_make, make);
	myStringCopy(m_model, model);
	m_price = price;
	m_available = available;
}
int Car::getYear() {
	return m_year;
}
char* Car::getMake() {
	return m_make;
}
char* Car::getModel() {
	return m_model;
}
float Car::getPrice() {
	return m_price;
}
bool Car::getAvailable() {
	return m_available;
}

void Car::setYear(int y) {
	m_year = y;
}
void Car::setMake(char* m) {
	myStringCopy(m_make, m);
}
void Car::setModel(char* m) {
	myStringCopy(m_model, m);
}
void Car::setPrice(float p) {
	m_price = p;
}
void Car::setAvailable(bool a) {
	m_available = a;
}

void Car::print() {
	std::cout << "Year: " << m_year << " Make: " << m_make << " Model: " << m_model << " Price: " << m_price << " Available: " << m_available << std::endl;
}
void Car::estimateCost(int days) {

}

void Car::myStringCopy(char* destination, const char* source) {
	while (*source != '\0')
		{
		*destination = *source;
		destination++;
		source++;
	}
	*destination = '\0'; 
}