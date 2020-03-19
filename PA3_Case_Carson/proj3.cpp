/*
This program simulates a rental car site in that there are three agencies each containing 5 cars that you can rent. 
They have a price as well that can be estimated for any number of days you rent them
*/
#include <iostream>
#include <fstream>
#include "Car.h"
using namespace std;
//struct
struct agency {
	char name[256];
	//Make Array if you wanna
	int zip;
	Car cars[5];
};

//Function prototypes
void readCars(agency agencies[3]);


//main UwU
int main() {
	//Initialize file pointer and other variables
	agency agencies[3];
	int userIn;
	//Mainloop user interface
	cout << "Welcome to the Rental car place! We have lots of wacky rental cars available for a low price from various agencies.";
	do {
		cout << "\nPress a button bellow to get started!";
		cout << "\n1).Enter File\n2).Print Data\n3).Estimate Cost\n4).Print Most Expensive Car\n5).Print Available to File\n6).Quit\n";
		cin >> userIn;
		switch (userIn) {
		case 1:
			readCars(agencies);
			break;
		case 2:
			for (int i = 0; i < 3; i++) {
				cout << "AGENCY: " << agencies[i].name << "\tZIP: " << agencies[i].zip << endl;
				for (int I = 0; I < 5; I++) {
					agencies[i].cars[I].print();
				}
			}
			break;
		case 3:
			int a, c, days;
			cout << "From what agency would you like to rent? (enter an interger)" << endl;
			cin >> a;
			cout << "What car would you like to rent? (enter an interger)" << endl;
			cin >> c;
			cout << "For how man days?" << endl;
			cin >> days;
			cout <<"COST: $"<< agencies[a].cars[c].getPrice() * days << endl;

			break;
		case 4:
			float most;
			most = 0;
			int mosta, mostc;
			for (int i = 0; i < 3; i++) {
				for (int I = 0; I < 5; I++) {
					if (agencies[i].cars[I].getPrice() > most) {
						most = agencies[i].cars[I].getPrice();
						mosta = i;
						mostc = I;
					}
				}
			}
			cout << "Most Expensive Car: " << agencies[mosta].name << "'s " << agencies[mosta].cars[mostc].getMake() <<" " << agencies[mosta].cars[mostc].getModel() << "at a price of: $" << agencies[mosta].cars[mostc].getPrice() << endl;
			break;

		case 5:
			char output[50];
			cout << "What is the name of the file you would like to write to?" << endl;
			cin >> output;
			ofstream ofp;
			ofp.open(output);
			for (int i = 0; i < 3; i++) {
				for (int I = 0; I < 5; I++) {
					if (agencies[i].cars[I].getAvailable()) {
						ofp << agencies[i].cars[I].getMake() << " " << agencies[i].cars[I].getModel() << "\n";
					}
				}
			}
			ofp.close();
			cout << "File written successfully" << endl;
			break;
		}
	} while (userIn != 6);


	return 0;

}

void readCars(agency agencies[3]) {
	char file[50];
	cout << "Enter the name of the file to use"<<endl;
	cin >> file;
	fstream fp;
	fp.open(file);
	for (int i = 0; i < 3; i++) {
		fp >> agencies[i].name >> agencies[i].zip;
		for (int I = 0; I < 5; I++) {
			int year;
			char make[50];
			char model[50];
			float price;
			bool available;
			fp >> year >> make >> model >> price >> available;
			agencies[i].cars[I].setYear(year);
			agencies[i].cars[I].setMake(make);
			agencies[i].cars[I].setModel(model);
			agencies[i].cars[I].setPrice(price);
			agencies[i].cars[I].setAvailable(available);		
		}
	}
}