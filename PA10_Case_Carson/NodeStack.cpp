/*NodeStack cpp file           */
/*Pretty self explanatory stuff*/
#include "NodeStack.h"
/*Constructors and Destructor*/
template <typename t>
NodeStack<t>::NodeStack() {
	m_top = NULL;
}
template <typename t>
NodeStack<t>::NodeStack(size_t count, const t value) {
	
	m_top = NULL;
	for (int i = 0; i < count; i++) {
		Node<t>* temp = new Node<t>(value);
		temp->m_next = m_top;
		m_top = temp;
	}
}
template <typename t>
NodeStack<t>::NodeStack(NodeStack<t>& other) {
	Node<t>* otherI = other.m_top;
	Node<t>* selfI = other.m_top;
	while (otherI != NULL) {
		selfI = otherI;
		otherI = otherI->m_next;
	}

}
template <typename t>
NodeStack<t>::~NodeStack() {
	Node<t>* temp = m_top;
	Node<t>* next;
	while (temp != NULL) {
		next = temp->m_next;
		delete temp;
		temp = next;
	}
	if (m_top == NULL) { delete m_top; }
	std::cout << "Node Object Deleted" << std::endl;
}
template <typename t>
NodeStack<t>& NodeStack<t>::operator=(NodeStack<t>& rhs) {
	Node<t>* otherI = rhs.m_top;
	Node<t>* selfI = rhs.m_top;
	while (otherI != NULL) {
		selfI = otherI;
		otherI = otherI->m_next;
	}
	return *this;
}

/*get functions*/
template <typename t>
t NodeStack<t>::top() {
	return m_top->m_data;
}
template <typename t>
const t NodeStack<t>::top()const{
	return top();
}
template <typename t>
size_t NodeStack<t>::size() const {
	size_t count=0;
	Node<t>* temp = m_top;
	while (temp != NULL) {
		count++;
		temp = temp->m_next;
	}
	return count;
}
template <typename t>
bool NodeStack<t>::empty() const {
	if (m_top == NULL) {
		std::cerr << "Node Stack is Empty" << std::endl;
		return true;
	}
	else {
		return false;
	}
}
template <typename t>
bool NodeStack<t>::full() const { return false; }
/*Functions to interact with the stack*/
template <typename t>
void NodeStack<t>::push(const t value) {
	Node<t>* next = new Node<t>(value);
	next->m_next = m_top;
	m_top = next;
}
template <typename t>
void NodeStack<t>::pop() {
	m_top = m_top->m_next;
}

template <typename t>
void NodeStack<t>::clear() {
	Node<t>* temp = m_top;
	Node<t>* next;
	while (temp != NULL) {
		next = temp->m_next;
		delete temp;
		temp = next;
	}
	m_top = NULL;
}
/*iostream functions*/
//reads from the top down
template <typename t>
void NodeStack<t>::serialize(std::ostream& os) const {
	Node<t>* temp = m_top;
	while (temp != NULL) {
		os <<"["<< temp->m_data<<"], ";
		temp = temp->m_next;
	}
}
template <typename t>
std::ostream& operator<<(std::ostream& os, const NodeStack<t>& nodeStack) {
	nodeStack.serialize(os);
	return os;
}