/*=================================================================================================================*/
/*                                               Test Driver for Project 10                                        */
/*=================================================================================================================*/
/*Written by: Carson Case*/
/*For: CS202             */
#include <iostream>
#include "ArrayStack.h"
#include "ArrayStack.cpp"
#include "NodeStack.h"
#include "NodeStack.cpp"
/*NOTE: Preprocessor declaration here is to simplify the cout/endl statement to LOG*/
#define LOG(x) std::cout<<x<<std::endl

/*Main loop*/
int main() {
	LOG("Testing Array Stack");
	LOG("Default Constructor");
	ArrayStack<int> defaultCstr;
	LOG("Parameterized Constructor");
	ArrayStack<int> paramCstr(10, 1);
	LOG("Copy Constructor");
	ArrayStack<int> copyOfParam(paramCstr);
	LOG("Top of param Stack:");
	LOG(paramCstr.top());
	LOG("Push");
	defaultCstr.push(5);
	LOG("Pop (done on empty stack. Should return error)");
	defaultCstr.pop();
	LOG("Serialize param");
	std::cout << paramCstr;
	LOG("");
	LOG("Destructors:");

	LOG("Testing Node Stack");
	LOG("Default Constrsuctor");
	NodeStack<int> defNode;
	LOG("Parameterized Constructor");
	NodeStack<int> paramNode(10, 1);
	LOG("Copy Constructor");
	NodeStack<int> copy = paramNode;
	LOG("Size");
	LOG(paramNode.size());
	LOG("Push");
	paramNode.push(2);
	LOG("Serialize");
	std::cout << paramNode<<std::endl;
	LOG("Clear");
	paramNode.clear();
	LOG("Destructors:");
	
	return 0;
}