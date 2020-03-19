#include "ArrayList.h"
#include "DataType.h"
#include "NodeList.h"
/*TEST DRIVER for List data structure Project 8                                    */
/*PLEASE NOTE that std::cout has been replaced as LOG with a preprocessor directive*/
/*Author: Carson Case                                                              */
/*Class: CS202                                                                     */
/*Project 8                                                                        */
#define LOG(x) std::cout<<x<<std::endl

//FOR TESTING ONLY
//Sets if you run the ArrayList or not
#define RUN_ARRAY_LIST true
int main(){
	if (RUN_ARRAY_LIST) {
		DataType test(10, 10);
		DataType* testRef = &test;
		LOG("//////////////////////////////////////////////////////////");
		LOG("                 Running tests for ArrayList              ");
		LOG("//////////////////////////////////////////////////////////");
		LOG("Default Constructor");
		ArrayList a;
		LOG("Paramaterized Constructor");
		ArrayList b(10, test);
		LOG("Copy Constructor");
		ArrayList c(b);
		LOG("Assignment operator");
		a = b;
		LOG("FRONT: ");
		LOG(*b.front());
		LOG("BACK: ");
		LOG(*b.back());
		LOG("FIND");
		std::cout << *b.find(test, testRef) << std::endl;


		LOG("Destructors");
	}
	LOG("//////////////////////////////////////////////////////////");
	LOG("                 Running tests for NodeList               ");
	LOG("//////////////////////////////////////////////////////////");
	DataType test(10, .1);	//Int is set to 1 and double is set to .1; return type depends on the mood I was in while typing this 
	LOG("Default Constructor");
	NodeList a;
	LOG("Parameterized Constructor");
	NodeList b(10, test);	//size is of 10
	LOG("Copy Constructor");
	//pass
	LOG("Assignment Operator");
	//pass
	LOG("Front");
	Node* nodeTest = b.front();
	LOG(nodeTest->data().getIntVal());
	LOG("Back");
	nodeTest = b.back();
	LOG(nodeTest->data().getIntVal());
	LOG("Find");
	Node* last;
	nodeTest = b.find(test, last);
	LOG(nodeTest->data().getIntVal());
	//LOG(last->data().getIntVal());	Since this returns NULL for the first element it doesn't work searching first element
	LOG("Insert After");
	nodeTest = b.insertAfter(test, test);
	LOG("Insert Before");
	nodeTest = b.insertBefore(test, test);
	LOG("Erase");
	nodeTest = b.erase(test);
	LOG("[] Overload");
	LOG(b[3].getDoubleVal());
	LOG("Size");
	LOG(b.size());
	LOG("Empty (for a and b in order: should be true, false in order)");
	LOG(a.empty());
	LOG(b.empty());
	LOG("Clear (prints b.empty() after: should be true this time)");
	b.clear();
	LOG(b.empty());

	LOG("Destructors:");
}