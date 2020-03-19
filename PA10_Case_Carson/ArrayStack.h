/*Header file for ArrayStack object*/
#pragma once
#include <iostream>
const size_t MAX_STACKSIZE = 1000;

template<class t> class ArrayStack {

	template <class T>
	friend std::ostream& operator<< (std::ostream& os, const ArrayStack<T>& arrayStack);
private:
	t m_container[MAX_STACKSIZE];
	size_t m_top;
public:
	ArrayStack();
	ArrayStack(size_t count, const t value);
	ArrayStack(const ArrayStack<t>& other);
	~ArrayStack();
	ArrayStack<t>& operator=(const ArrayStack<t>& rhs);
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
