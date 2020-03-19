#include "Agency.h"
#include <iostream>
#include <fstream>

Agency::Agency(): m_zipcode(89502) {
	
	myStringCopy(m_name, "");
}
const int Agency::getZip() {
	return m_zipcode;
}
void Agency::setName(char name[256]) {
	myStringCopy(m_name, name);
}
char* Agency::getName() {
	return m_name;
}
void Agency::setInventory(Car cars[5]) {
	for (int i = 0; i < 5; i++) {
		m_inventory[i] = cars[i];
	}
}
Car Agency::operator[](int i) {
	return m_inventory[i];
}
void Agency::readAllData(char* file) {
	int temp;
	std::fstream fileIn;
	fileIn.open(file);
	fileIn >> m_name;
	fileIn >> temp;
	for (int i=0; i < 5; i++) {
		int year;
		char make[256];
		char model[256];
		char type[256];
		char owner[256];
		float price;
		char x;
		Sensor s;
		fileIn >> year >> make >> model >> price;
		m_inventory[i].setYear(year);
		m_inventory[i].setMake(make);
		m_inventory[i].setModel(model);
		m_inventory[i].setBasePrice(price);

		fileIn >> type;
		while (type[0] != '0' && type[0] != '1') {
			char stype[256];
			removeBracket(type, stype);
			s.setType(stype);
			m_inventory[i] + s;
			fileIn >> type;
		}
		if (type[0] == '0') {
			m_inventory[i].setAvailable(false);
			fileIn >> owner;
			m_inventory[i]+owner;
		}
		else {
			m_inventory[i].setAvailable(true);
		}
		
	}
}
void Agency::printAllData() {
	std::cout << "Name: " << m_name << " Zip: " << m_zipcode<< " Inventory: " << std::endl;
	for (int i = 0; i < 5; i++) {
		std::cout << "Make: " << m_inventory->getMake() << " Model: " << m_inventory[i].getModel() << " Year: " << m_inventory[i].getYear() << " Available: " << m_inventory[i].getAvailable() << " Owner(If aplicable): " << m_inventory[i].getOwner() << std::endl;
	}
}
void Agency::printAvailableCars() {
	for (int i = 0; i < 5; i++) {
		if (m_inventory[i].getAvailable()) {
			std::cout << "Make: " << m_inventory->getMake() << " Model: " << m_inventory[i].getModel() << " Year: " << m_inventory[i].getYear() << " Available: " << m_inventory[i].getAvailable() << " Owner(If aplicable): " << m_inventory[i].getOwner() << std::endl;
		}
	}
}

void Agency::rentMostExpensive() {
	float most = 0;
	int winner;
	for (int i = 0; i < 5; i++) {
		m_inventory[i].updatePrice();
		if (m_inventory[i].getFinalPrice() > most) {
			most = m_inventory[i].getFinalPrice();
			winner = i;
		}
	}
	std::cout << "Here is the most expensive car: " << m_inventory[winner].getMake() << " " << m_inventory[winner].getModel() << "\nThe price is: $" << m_inventory[winner].getFinalPrice() << "per Day. Would you like to rent this car? (y/n?)" << std::endl;
	char u;
	std::cin >> u;
	if (u == 'y'|| u == 'Y') {
		std::cout << "How many days?" << std::endl;
		int ui;
		std::cin >> ui;
		std::cout << "The Cost Due Is: $" <<m_inventory[winner].estimateCost(ui)<<std::endl;
		m_inventory[winner].setAvailable(false); 
	}
}

void Agency::myStringCopy(char destination[256], const char source[256]) {
	int count = 0;
	for (int i = 0; source[i] != '\0'; i++) {
		destination[i] = source[i];
		count = i;
	}
	destination[count + 1] = '\0';
}

//Str copy but removes brackets
void Agency::removeBracket(char x[256], char r[256]) {
	int count = 0;
	for (int i = 0; x[i] != '\0'; i++) {
		if (x[i] != '{' && x[i] != '}') {
			char c = x[i];
			r[count++] = c;
		}
	}
	r[count] = '\0';
}