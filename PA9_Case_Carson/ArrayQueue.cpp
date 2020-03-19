#include "ArrayQueue.h"

/*Constructors*/
ArrayQueue::ArrayQueue() {
	m_front = 0;
	m_back = 0;
	m_size = 0;
}
ArrayQueue::ArrayQueue(size_t count, const DataType& value) {
	m_front = 0;
	m_back = count;
	m_size = count;
	for (int i = 0; i < count; i++) {
		m_array[i] = value;
	}
}
ArrayQueue::ArrayQueue(const ArrayQueue& other) {
	m_front = other.m_front;
	m_back = other.m_back;
	m_size = other.m_size;
	for (int i = 0; i < m_size; i++) {
		m_array[i] = other.m_array[i];
	}
}
/*Destructor*/
ArrayQueue::~ArrayQueue() {
	
}
/*Insertion operator*/
ArrayQueue& ArrayQueue::operator= (const ArrayQueue& rhs) {
	m_front = rhs.m_front;
	m_back = rhs.m_back;
	m_size = rhs.m_size;
	for (int i = 0; i < m_size; i++) {
		m_array[i] = rhs.m_array[i];
	}
	return *this;
}
/*get functions*/
DataType& ArrayQueue::front() {
	return m_array[m_front];
}
const DataType& ArrayQueue::front() const {
	return front();
}
DataType& ArrayQueue::back() {
	return m_array[m_back];
}
const DataType& ArrayQueue::back() const{
	return back();
}
size_t ArrayQueue::size() const {
	return m_size;
}
/*Bool gets (returns true or false information about the queue*/
bool ArrayQueue::empty() const {
	if (m_back == m_front) {
		return true;
	}
	else {
		return false;
	}
}
bool ArrayQueue::full() const{
	if (m_back == m_size) {
		return true;
	}
	else {
		return false;
	}
}
/*Push/Pop (iserting and removing data from the queue)*/
void ArrayQueue::push(const DataType& value) {
	if (!full()) {
		m_back++;
		m_size++;
		m_array[m_back] = value;
	}
	else {
		std::cerr << "Queue is full for the ArrayQueue List"<<std::endl;
	}
}
void ArrayQueue::pop() {
	if (!empty()) {
		for (int i = 1; i < m_size; i++) {
			m_array[i - 1] = m_array[i];
		}
		m_back--;
		m_size--;
	}
	else {
		throw "Queue is empty";
	}
}
/*clear the queue*/
void ArrayQueue::clear() {
	m_size = 0;
	m_back = 0;
	m_front = 0;
}
/*stream output functions*/
void ArrayQueue::serialize(std::ostream & os) const{
	os << "[";
	for (int i = 0; i < m_size; i++) {
		os << m_array[i] << ", ";
	}
	os << "]";
}
/*Friend Function*/
std::ostream& operator<<(std::ostream& os, const ArrayQueue& arrayQueue) {
	arrayQueue.serialize(os);
	return os;
}