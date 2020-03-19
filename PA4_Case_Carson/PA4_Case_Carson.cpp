#include <iostream>
#include <fstream>
#include "Car.h"
#include "Sensor.h"
#include "Agency.h"
using namespace std;
//main UwU
int main() {
	Agency a;
	Sensor count;
	char file[256];
	a.printAvailableCars();

	int userIn = 0;
	cout << "Welcome to the Rental Car Agency! We pride ourselves on our computer system. Because I spent like a lot of time on it." << endl;
	while (userIn != 5) {
		cout << "Chose a menu option below: \n1).Read All Data From File\n2).Print All Data\n3).Print Total Number of Sensors\n4).Rent Most Expensive Car\n5).Quit" << endl;
		cin >> userIn;

		switch (userIn) {
		case 1:
			cout << "Enter the File Name: " << endl;
			cin >> file;
			a.readAllData(file);
			cout << "Read Complete" << endl;
			break;
		case 2:
			a.printAllData();
			break;
		case 3:
			cout << "Gps: " << count.getGps() - 1 << " Camera: " << count.getCamera() - 1 << " Lidar: " << count.getLidar() - 1 << " Radar: " << count.getRadar() - 1 << endl;
			break;
		case 4:
			a.rentMostExpensive();
		case 5:
			break;
		}
	}


	return 0;

}
