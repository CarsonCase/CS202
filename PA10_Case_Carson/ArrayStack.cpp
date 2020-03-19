/*ArrayStack cpp file        */
/*contains a lot of neat code*/
#include "ArrayStack.h"

/*Constructor and Destructors*/
template<typename t>
ArrayStack<t>::ArrayStack() {
	m_top = 0;
}
template<typename t>
ArrayStack<t>::ArrayStack(size_t count, const t value) {
	m_top = count;
	for (int i = 0; i < m_top; i++) {
		m_container[i] = value;
	}
}
template<typename t>
ArrayStack<t>::ArrayStack(const ArrayStack& other) {
	m_top = other.m_top;
	for (int i = 0; i < m_top; i++) {
		m_container[i] = other.m_container[i];
	}
}
template<typename t>
ArrayStack<t>::~ArrayStack() {
	std::cout << "Array Object Deleted" << std::endl;
}

/*Assignment operator*/
template<typename t>
ArrayStack<t>& ArrayStack<t>::operator=(const ArrayStack<t>& rhs) {
	m_top = rhs.m_top;
	for (int i = 0; i < m_top; i++) {
		m_container[i] = rhs.m_container[i];
	}
	return *this;
}

/*get size*/
template<typename t>
size_t ArrayStack<t>::size() const {
	return m_top;
}

/*Test if full or empty*/
template<typename t>
bool ArrayStack<t>::full() const {
	if (m_top == MAX_STACKSIZE) {
		return true;
	}
	else {
		std::cerr << "Stack is Full" << std::endl;
		return false;
	}
}
template<typename t>
bool ArrayStack<t>::empty() const {
	if (m_top == 0) {
		return true;
	}
	else {
		std::cerr << "Stack is Empty" << std::endl;
		return false;
	}
}

/*Utility functions to use the stack*/
template<typename t>
t ArrayStack<t>::top() {
	if (!empty()) {
		return m_container[m_top-1];
	}
}
template<typename t>
const t ArrayStack<t>::top() const {
	return top();
}
template<typename t>
void ArrayStack<t>::push(const t value) {
	if (!full()) {
		m_top++;
		m_container[(m_top-1)] = value;
	}
}

template<typename t>
void ArrayStack<t>::pop() {
	if (!empty()) {
		m_top--;
	}
}

/*clear stack*/
template<typename t>
void ArrayStack<t>::clear() {
	m_top = 0;
}

/*iostream functions*/
//reads bottom up
template<typename t>
void ArrayStack<t>::serialize(std::ostream& os) const {
	for (int i = 0; i < m_top; i++) {
		os <<"["<< m_container[i]<<"], ";
	}
}

template<typename t>
std::ostream& operator<< (std::ostream& os, const ArrayStack<t>& arrayStack) {
	arrayStack.serialize(os);
	return os;
}