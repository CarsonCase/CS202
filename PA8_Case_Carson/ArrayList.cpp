/*CPP file for ArrayList            */
/*File is likely riddled with errors*/
/*More explained in documentation   */

#include "ArrayList.h"

/*Constructors/Destructor*/
ArrayList::ArrayList(){
	m_array= new DataType;
	m_size = 0;
	m_maxsize = 0;
}
ArrayList::ArrayList(size_t count, const DataType& value) {
	//increase the size
	m_size = count;
	m_maxsize = count;
	try {
		m_array = new (std::nothrow) DataType[count];
		if (!m_array) {
			throw "memory allocation has failed for the ArrayList paramaterized constructor";
		}
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	//copy dataTypes
	for (size_t i=0; i < count; i++) {
		DataType temp(value);
		m_array[i] = temp;
	}
}
ArrayList::ArrayList(const ArrayList& other):ArrayList(other.m_size,other.m_array[0]) {
	//Array copied using parameterized cstr. Prone to errors I suppose but it saves time
}
ArrayList::~ArrayList() {
	delete[] m_array;
}

ArrayList& ArrayList::operator= (const ArrayList& rhs) {
	//resize
	resize(rhs.m_size);
	//copy in the new data
	for (int i = 0; i < rhs.m_size; i++) {
		m_array[i] = rhs.m_array[i];
	}
	return *this;
}

void ArrayList::resize(size_t count) {
	//create a temp array;
	DataType* temp = new DataType[count];
	int I = 0;
	for (int i = 0; i < count; i++) {
		temp[I++] = m_array[i];
	}
	//delete the old array and make a new one with data in temp
	delete[] m_array;
	m_array = new DataType[I];
	for (int i = 0; i < I; i++) {
		m_array[i] = temp[i];
	}
	//delete temp
	delete[] temp;

}
DataType* ArrayList::front() {
	if (&m_array[0]) {
		return &m_array[0];
	}
}
DataType* ArrayList::back() {
	if (&m_array[m_size]) {
		return &m_array[m_size-1];
	}
}

DataType* ArrayList::find(const DataType& target,
	DataType*& previous,
	const DataType* start) {
	for (int i = 0; i < m_size; i++) {
		if (target == m_array[i]) {
			*previous = target;
			return &m_array[i];
		}
	}
	previous = NULL;
	return NULL;
}
DataType* ArrayList::insertAfter(const DataType& target,
	const DataType& value) {
	int i;
	if (m_size == 0) {
		m_array[0] = value;
		return &m_array[0];
	}
	else {
		for (int i = 0; i < m_size; i++) {
			if (m_array[i] == target) {
				resize(m_size + 1);
				DataType temp = m_array[i];
				m_array[i] = value;
				for (int I = i; I < m_size; ++I) {
					temp = m_array[I - 1];
					m_array[I] = temp;
				}
				return &m_array[i];
			}
		}
	}
}

DataType* ArrayList::insertBefore(const DataType& target,  	
	const DataType& value) {
	int i;
	if (m_size == 0) {
		m_array[0] = value;
		return &m_array[0];
	}
	else {
		for (int i = 0; i < m_size; i++) {
			if (m_array[i] == target) {
				resize(m_size + 1);
				DataType temp = m_array[i-1];
				m_array[i-1] = value;
				for (int I = i; I < m_size; I++) {
					temp = m_array[I - 1];
					m_array[I] = temp;
				}
				return &m_array[i];
			}
		}
	}
}
DataType* ArrayList::erase(const DataType& target) {
	int index;
	for (int i = 0; i < m_size; i++) {
		if (m_array[i] == target) {
			DataType empty;
			m_array[i] = empty;
			index = i;
		}
		resize(m_size - 1);
	}
	return &m_array[index];
}
DataType& ArrayList::operator[] (size_t position) {
	return m_array[position];
}
size_t ArrayList::size() const {
	return m_size;
}
bool ArrayList::empty() const {
	if (m_size == 0) {
		return true;
	}
	else {
		return false;
	}
}
void ArrayList::clear() {
	delete[] m_array;
}

std::ostream& operator<<(std::ostream& os,		//(friend function)
	const ArrayList& arrayList) {
	size_t size = arrayList.size();
	ArrayList copyThatsNotConst = arrayList;
	for (size_t i = 0; i < size; i++) {
		os <<" " << copyThatsNotConst[i]<<" ";
	}
	return os;
}