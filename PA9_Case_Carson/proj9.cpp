/* Name: proj9.cpp */
/* Purpose: Test the NodeQueue and ArrayQueue classes */
/* Author: Carson Case */

#include "ArrayQueue.h"
#include "NodeQueue.h"
using namespace std;

int main() {
	DataType dt_default;
	DataType dt_01(5, 0.5);
	cout << "\n" <<
		"////////////////////////////////\n" <<
		"/////   Project 9 Testing  /////\n" <<
		"////////////////////////////////" << endl;

	cout << "Testing Default Constructors\n";
	ArrayQueue arrayDefault;
	NodeQueue nodeDefault;
	cout << "=================== Test Complete ===================\n";

	cout << "Testing Parameterized Constructors\n";
	ArrayQueue arrayParam(5, dt_01);
	NodeQueue nodeParam(5, dt_01);
	cout << "=================== Test Complete ===================\n";

	cout << "Testing Copy Constructors\n";
	ArrayQueue arrayCopy(arrayParam);
	NodeQueue nodeCopy(nodeParam);
	cout << "=================== Test Complete ===================\n";

	cout << "Testing Destructors\n";
	ArrayQueue* arrayKill = new ArrayQueue;
	delete arrayKill;
	NodeQueue* nodeKill = new NodeQueue;
	delete nodeKill;
	cout << "=================== Test Complete ===================\n";

	cout << "Testing Assignment Operators\n";
	arrayDefault = arrayParam;
	nodeDefault = nodeParam;
	cout << "=================== Test Complete ===================\n";

	cout << "Testing Front and Back Functions\n";
	cout << "Front: \n";
	cout << arrayDefault.front();
	cout << nodeDefault.front();
	cout << "\nBack: \n";
	cout << arrayDefault.back();
	cout << nodeDefault.back();
	cout << "\n=================== Test Complete ===================\n";

	cout << "Testing Push and Pop Functions\n";
	cout << "Push:\n";
	arrayParam.push(dt_default);
	nodeDefault.push(dt_default);
	cout << "Pop:\n";
	arrayDefault.pop();
	nodeDefault.pop();
	cout << "=================== Test Complete ===================\n";

	cout << "Testing Helper Functions\n";
	cout << "ArrayQueue Size: " << arrayParam.size() << endl;
	cout << "NodeQueue Size: " << nodeParam.size() << endl;
	cout << "Clear:\n";
	arrayDefault.clear();
	nodeDefault.clear();
	cout << "ArrayQueue Empty: " << boolalpha << arrayDefault.empty() << endl;
	cout << "NodeQueue Empty: " << boolalpha << nodeParam.empty() << endl;
	cout << "ArrayQueue Full: " << arrayDefault.full() << endl;
	cout << "NodeQueue Full: " << nodeParam.full() << endl;
	cout << "=================== Test Complete ===================\n";

	cout << "\n" <<
		"////////////////////////////////\n" <<
		"/////    Tests Complete    /////\n" <<
		"////////////////////////////////" << endl;
	_Exit(0);
}