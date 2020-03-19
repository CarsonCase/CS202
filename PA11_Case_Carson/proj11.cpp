/*=================================================================================================================*/
/*                                                   Project 11                                                    */
/*=================================================================================================================*/
/*Written by: Carson Case*/
/*For: CS202             */
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

//test print operator overload for vector
template <class t>
ostream& operator<<(ostream& os, const vector<t> v) {
	int count = 0;
	for (auto i : v) {
		os << '[' << i << ":"<<count++<<"], ";
	}
	os << endl;
	return os;
}

//Kinda a ghetto sort function but it gets the job done. Would like to fix with a proper application of quicksort 
template <class t>
void vector_resort(vector<t>& v, int count) {
	bool rec = false;
	if (count == 0) {
		return;
	}
	for (int i = --count; i >= 0; i--) {
		rec = true;
		if (v[i] > v[count]) {
			t temp = v[count];
			v[count] = v[i];
			v[i] = temp;
		}
	}
	if (rec) { vector_resort(v, count); }
	
}

//binary search function
template <class t>
int vector_research(vector<t>& v, t search, int front, int back) {
	int newParam = ((back-front)/2)+front;
	int r;

	//if newParam has not changed from last search then the search is stuck in a loop and the value it is looking for does not exist
	if (back == newParam || front == newParam) {
		r = -1;
		return r;		//force return
	}
	//if the value in the middle is greater than the search value then we call with the next back = newParam
	if (v[newParam] > search) {
		r = vector_research(v, search, front, newParam);
	}
	//if the value in the middle is less than the search value then we call with the next front = newParam
	if (v[newParam] < search) {
		r = vector_research(v, search, newParam, back);
	}
	//if newParam = search value then we return newPram
	if (v[newParam] == search) {
		r = newParam;
	}
	return r;
}
//Main Function
int main() {
	//main int vector
	vector<int> vectInt;
	//VectInt Copy
	vector<int> vectIntCopy = vectInt;

	//Read in data from text file to a vector
	fstream file;
	file.open("data.txt");
	int temp;
	while (file >> temp) {
		vectInt.emplace_back(temp);
	}

	/*PART A*/
	//print unsorted vector to screen
	cout << vectInt << endl;
	//sort vector
	vector_resort(vectInt,vectInt.size()-1);
	//print sorted vector to screen
	cout << vectInt << endl;
	
	/*PART B*/
	//binary search
	cout << vector_research(vectInt, 42, 0, vectInt.size()-1);

	return 0;
}