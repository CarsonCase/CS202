/*NodeStack.h file						  */
/*Provided for project (for the most part)*/
#pragma once
#include <iostream>
#ifndef NODESTACK
#define NODESTACK

//forward declaration (this thing took a solid ammount of my time so admire it)
template <class t> class NodeStack;

//Node class
template <class t> class Node {
	friend class NodeStack<t>;
private:
	Node* m_next;
	t m_data;
public:
	Node() : m_next(NULL) {}
	Node(const t data, Node<t>* next = NULL) : m_data(data), m_next(next) {}
	t data() {
		return m_data;
	}
	const t data() const {
		return m_data;
	}
};

//Node stack class (node is a friend of this)
template <class t> class NodeStack {
	template <class T>
	friend std::ostream& operator<<(std::ostream& os, const NodeStack<T>&nodeStack);
private:
	Node<t>* m_top;
public:
	NodeStack();
	NodeStack(size_t count, const t value);
	NodeStack(NodeStack<t>& other);
	~NodeStack();
	NodeStack<t>& operator=(NodeStack<t>& rhs);
	t top();
	const t top() const;
	void push(const t value);
	void pop();
	size_t size() const;
	bool empty() const;
	bool full() const;
	void clear();
	void serialize(std::ostream& os) const;
};
#endif NODESTACK

