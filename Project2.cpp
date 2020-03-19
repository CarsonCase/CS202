#include <iostream>
#include <fstream>
using namespace std;

//Prints a sorted list (by size) to screen and output file
void printSortedList(char names[10][9], char out[20]);
//Prints a //Prints a sorted list (by alphabet) to screen and output file
void printAlphList(char names[10][9], char out[20]);
//Compares two strings alphabetically 
int strComp(char input[9], char input2[9]);
//Copies two strings to eachother
void myStringCopy(char destination[9], const char source[9]);
//Finds size of a char array
int sizeOf(char toFind[9]);

int main() {
	//set up all the vairables I need 
	char input[20], output[20];
	char names[10][9];
	fstream fin;

	//Get the input and output files from the lovely user
	cout << "Hey buddy. Please enter the input file name" << endl;
	cin >> input;
	cout << "Thanks bud! Now it's time to enter the output file name" << endl;
	cin >> output;
	cout << "Outstanding!" << endl;

	//read the input file
	fin.open(input);
	for (int i = 0; i < 10; i++) {
		fin >> names[i];
		//Prints the unsorted list. Is this fancy? No. Does it same room and time? Yes. So there's no specific funciton to do this
		cout << names[i] << endl;
	}
	cout << "SORTED BY LENGTH" << endl;
	printSortedList(names, output);
	cout << "SORTED BY ALPHABET" << endl;
	printAlphList(names, output);

	return 0;
}
int sizeOf(char toFind[9]) {
	int size = 0;
	while (toFind[size] != '\0' && size < 8) {
		size++;
	}
	return size;
}
void printSortedList(char names[10][9], char out[20]) {
	char list[10][9];
	fstream fout;
	fout.open(out);
	for (int i = 8; i > -1; i--) {
		for (int I = 0; I < 10; I++) {
			if (sizeOf(names[I]) == i) {
				cout << names[I] << endl;
				fout << names[I] << endl;
			}
		}
	}
	fout.close();
}

void printAlphList(char names[10][9], char out[20]) {
	fstream fout;
	//run the sort 40 times so there's no chance that something is out of order. It's lazy but it is also creative problem solving. And this class is here to teach creative problem solving. I rest my case
	for (int count = 0; count < 40; count++) {
		for (int i = 0; i < 9; i++) {
			if (strComp(names[i], names[i + 1])) {
				char temp[9];
				myStringCopy(temp, names[i]);
				myStringCopy(names[i], names[i + 1]);
				myStringCopy(names[i + 1], temp);
			}
		}
	}
	fout.open(out);
	for (int i = 0; i < 10; i++) {
		cout << names[i]<<endl;
		fout << names[i] << endl;
		
	}
	fout.close();
}

int strComp(char input[9], char input2[9]) {
	for (int i = 0; i < 9; i++) {
		if (input[i] != input2[i]) {
			if (input[i] > input2[i]) {
				return 1;
			}
			else {
				return 0;
			}
		}
	}
	return 1;
}

void myStringCopy(char destination[9], const char source[9]) {
	int count=0;
	for (int i = 0; source[i] != '\0'; i++) {
		destination[i] = source[i];
		count = i;
	}
	destination[count + 1] = '\0';
}