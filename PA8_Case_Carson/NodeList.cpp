#include "NodeList.h"

//Default Ctr
NodeList::NodeList() {
	m_head = NULL;
}
//Parameterized Ctr
NodeList::NodeList(size_t count, const DataType& value) {
	//adds a node of value value for each of size_t count
	for (int i = 0; i < count; i++) {
		Node* temp = new Node;
		temp->m_data = value;
		//If first node set new val to head and point to null
		if (m_head == NULL) {
			temp->m_next = NULL;
			m_head = temp;
			temp = NULL;
		}
		//if not first node point to last head then set new node as the head
		else {
			temp->m_next = m_head;
			m_head = temp;
			temp = NULL;
		}
		delete temp;
	}
}
//Copy Ctr
NodeList::NodeList(const NodeList& other) {
	//Come back to this. I bet there's a utility function that could make this easier...
}
//Destructor (fun stuff)
NodeList::~NodeList() {
	//if first node then simply delete head and move on
	Node* temp = m_head;
	if (m_head == NULL) {

	}
	else {
		//otherwise loop through each node and delete em
		while (temp->m_next != NULL) {
			Node* next = temp->m_next;
			//Prints out each node for testing
			std::cout << "NODE DELETED WITH VALUE:: " << temp->m_data.getDoubleVal() << std::endl;
			delete temp;
			temp = next;
		}
	}
	//delete last node
	std::cout << "FINAL NODE DELETED" << std::endl;
	delete temp;
}

//Assignment operator
NodeList& NodeList::operator= (const NodeList& rhs){
	//explicitly call destructor to clear memory;
	rhs.~NodeList();

	//Same shit we have yet to do in the copy constructor::
	return *this;
}

//Returns the head
Node* NodeList::front() {
	return m_head;
}

Node* NodeList::back() {
	//Bassic cycling function. Copy and paste this at leisure
	Node* temp = m_head;
	while (temp->m_next != NULL && m_head!=NULL) {
		Node* next = temp->m_next;
		temp = next;
	}
	return temp;

}
Node* NodeList::find(const DataType& target,
	Node*& previous,
	const Node* start) {

	Node* temp = m_head;
	DataType lookFor = target;
	//test first node
	if ((temp->data()) == target) {
		previous = NULL;
		return temp;
	}
	while (temp->m_next != NULL && m_head != NULL) {
		if (temp->m_next->data() == target) {
			previous = temp;
			return temp->m_next;
		}
		Node* next = temp->m_next;
		temp = next;
	}
	previous = NULL;
	return temp;
}
Node* NodeList::insertAfter (const DataType& target,
	const DataType& value) {
	Node* prev;
	Node* insert = this->find(target, prev);

	Node* temp = new Node;
	temp->m_data = value;
	//if first node just insert the same was as we create the list
	if (insert == NULL) {
		temp->m_next = NULL;
		m_head = temp;
	}
	//else if target is the head we just add it on to the end
	else if(insert == m_head){
		temp->m_next = m_head;
		m_head = temp;
	}//lastly we add it in between by setting temp to point to target and previous to point to temp
	else {
		temp->m_next= insert;
		prev-> m_next = temp;
	}
	//does not delete. No time to worry about that
	return temp;
}

Node* NodeList::insertBefore(const DataType& target,
	const DataType& value) {
	Node* prev;
	Node* insert = this->find(target, prev);

	Node* temp = new Node;
	temp->m_data = value;
	//if first node just insert the same was as we create the list
	if (insert == NULL) {
		temp->m_next = NULL;
		m_head = temp;
	}//lastly we add it in between by setting temp to point to next and target to point to temp
	else {
		temp->m_next = insert->m_next;
		insert->m_next = temp;
	}
	//does not delete. No time to worry about that
	return temp;
}

Node* NodeList::erase(const DataType& target) {
	Node* prev;
	Node* erase = this->find(target, prev);
	Node* r = erase->m_next;
	//if node is the first one simply delete and set previous next to point to NULL
	if (erase == NULL) {
		delete erase;
		prev->m_next = NULL;
	}
	//else if the node is the very last node, simply delete it and set head = the next value head points to
	else if (erase == m_head) {
		m_head = m_head->m_next;
		delete erase;
	}
	//lastly if anywhere else set the previous node's next to the next pointer of insert and delete
	else {
		prev->m_next = erase->m_next;
		delete erase;
	}
	return r;
}
DataType& NodeList::operator[] (size_t position) {
	Node* temp = m_head;
	try {
		if (m_head == NULL) {
			throw "ERROR YOU HAVE FUCKED UP";
		}
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	for (int i = 0; i < position; i++) {
		if (temp->m_next != NULL && m_head != NULL) {
			Node* next = temp->m_next;
			temp = next;
		}
	}
	return temp->data();
}
const DataType& NodeList::operator[] (size_t position) const {
	Node* temp = m_head;
	try {
		if (m_head == NULL) {
			throw "ERROR YOU HAVE FUCKED UP";
		}
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	for (int i = 0; i < position; i++) {
		if (temp->m_next != NULL && m_head != NULL) {
			Node* next = temp->m_next;
			temp = next;
		}
	}
	return temp->data();
}
size_t NodeList::size() const {
	//Bassic cycling function. Copy and paste this at leisure
	Node* temp = m_head;
	size_t count = 0;
	while (temp->m_next != NULL && m_head != NULL) {
		Node* next = temp->m_next;
		temp = next;
		count++;
	}
	return count;
}
bool NodeList::empty() const {
	if (m_head == NULL) {
		return true;
	}
	else {
		return false;
	}
}
void NodeList::clear() {
	//if first node then simply move on
	if (m_head == NULL) {
		return;
	}
	//otherwise loop through each node and delete em (except head)
	Node* temp = m_head;
	while (temp->m_next != NULL) {
		Node* next = temp->m_next;
		//Prints out each node for testing
		delete temp;
		temp = next;
	}
	m_head = NULL;
}

std::ostream& operator<<(std::ostream& os,	  //(i)
	const NodeList& nodeList) {
	size_t size = nodeList.size();
	for (int i=0; i < size; i++) {
		os << nodeList[i];
	}
	return os;
}