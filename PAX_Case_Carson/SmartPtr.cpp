#include "SmartPtr.h"

//Default Constructor
SmartPtr::SmartPtr() {
	//Dynamically allocate Datatype and Size_t 
	//Set Size_t = 1
	m_ptr = new DataType;
	m_refcount = new size_t;
	*m_refcount = 1;
	std::cout << "SmartPtr Default Constructor for new allocation, RefCount=" << *m_refcount << std::endl;
}

//Paramaterized Constructor
SmartPtr::SmartPtr(DataType* data) {
	m_ptr = data;
	m_refcount = new size_t;
	if (data == NULL) {
		*m_refcount = 0;
	}
	else {
		*m_refcount = 1;
	}
	std::cout << "SmartPtr Parametrized Constructor from data pointer, RefCount=" << *m_refcount << std::endl;
}

//Copy Constructor
SmartPtr::SmartPtr(const SmartPtr& other) {
	m_ptr = other.m_ptr;
	m_refcount = new size_t;
	if (other.m_refcount == NULL) {
		*m_refcount = 0;
	}
	else {
		*m_refcount = (*other.m_refcount)+1;
	}
	std::cout << "SmartPtr CopyConstructor, RefCount=" << *m_refcount << std::endl;
}

//Destructor
SmartPtr::~SmartPtr() {
	--*m_refcount;
	std::cout<<"SmartPtr Destrcutor, RefCount=" << *m_refcount << std::endl;
	if (*m_refcount == 0) {
		delete m_ptr;
	}
		delete m_refcount;
}

//Assignment operator
SmartPtr& SmartPtr::operator=(const SmartPtr& rhs) {
	--*m_refcount;
	if (*m_refcount == 0) {
		delete m_ptr;
	}
	m_ptr = rhs.m_ptr;
	if (rhs.m_refcount == NULL) {
		*m_refcount = 0;
	}
	else {
		*m_refcount = ++ * rhs.m_refcount;
	}
	std::cout << "SmartPtr CopyAssignment, RefCount=" << *m_refcount << std::endl;
	return *this;
}

//Operator * overload
DataType& SmartPtr::operator*() {
	return *m_ptr;
}

//Operator -> overload
DataType* SmartPtr::operator->() {
	return m_ptr;
}

