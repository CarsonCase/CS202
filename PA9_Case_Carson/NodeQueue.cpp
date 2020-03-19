#include "NodeQueue.h"

/*Constructors*/
NodeQueue::NodeQueue() {
	m_front = NULL;
	m_back = NULL;
}
NodeQueue::NodeQueue(size_t size, const DataType& value) {
	Node* temp = new Node(value);
	m_back = temp;
	m_back->m_data = value;
	m_back->m_next = NULL;
	m_front = m_back;
	for (int i = 0; i < size; i++) {
		temp->m_next = m_front;
		m_front = temp;
	}
}NodeQueue::NodeQueue(const NodeQueue& other) {
	//If I am thinking right this should not requre any other gimmics as both objecs will be pointing to the same memory
	m_back = other.m_back;
	m_front = other.m_front;
	std::cout << m_front->m_next << std::endl;
}
/*Destructor*/
NodeQueue::~NodeQueue() {
	Node* temp = new Node;
	temp = m_front;
	if (temp == NULL) {
		delete temp;
	}
	else {
		while (temp->m_next != NULL) {
			temp = m_front;
			m_front = temp->m_next;
			delete temp;
		}
	}
}
/*Assignment operator*/
NodeQueue& NodeQueue::operator= (const NodeQueue& rhs) {
	m_back = rhs.m_back;
	m_front = rhs.m_front;

	return *this;
}
/*Get functions for front and back*/
DataType& NodeQueue::front() {
	return m_front->data();
}
const DataType& NodeQueue::front()const {
	return front();
}
DataType& NodeQueue::back() {
	return m_back->data();
}
const DataType& NodeQueue::back() const{
	return back();
}
/*Push and pop functions*/
void NodeQueue::push(const DataType& value) {
	//create new node, make the last back point to it, then set the new node to the back
	Node* toInsert = new Node(value);
	m_back->m_next = toInsert;
	m_back = toInsert;
}
void NodeQueue::pop() {
	//set front to the node it points to
	m_front = m_front->m_next;
}
/*Get function for size*/
size_t NodeQueue::size() const {
	size_t count = 0;
	Node* temp;
	temp = m_front;
	while (temp->m_next != NULL) {
		count++;
		temp = temp->m_next;
	}
	return count;
}

/*Bool get functions*/
bool NodeQueue::empty() const {
	if (size() == 0) {
		return true;
	}
	else {
		return false;
	}
}
bool NodeQueue::full() const {
	return false;
}
void NodeQueue::clear() {
	//destructor copy
	Node* temp = new Node;
	temp = m_front;
	while (temp->m_next != NULL) {
		temp = m_front;
		m_front = temp->m_next;
		delete temp;
	}
	m_front = NULL;
	m_back = NULL;
}
void NodeQueue::serialize(std::ostream& os) const {
	//same as size it just prints instead
	Node* temp;
	temp = m_front;
	while (temp->m_next != NULL) {
		os <<"["<< temp->m_data.getIntVal() << ", " << temp->m_data.getDoubleVal() << "], ";
		temp = temp->m_next;
	}
}
std::ostream& operator<<(std::ostream& os, const NodeQueue& nodeQueue) {
	nodeQueue.serialize(os);
	return os;
}