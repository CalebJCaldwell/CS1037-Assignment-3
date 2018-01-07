#pragma once
#include "List.h"

template<class T>
class Stack {
private:
	List <T> items;

public:
	Stack();
	~Stack();
	T pop();
	T peek();
	bool isEmpty();
	void push(T item);
};

template <class T>
Stack<T>::Stack() {
}

template <class T>
Stack<T>::~Stack() {
}

template <class T>
T Stack<T>::pop() {
	return items.popBack();

}

template <class T>
T Stack<T>::peek() {
	return items.back();
}

template <class T>
void Stack<T>::push(T item) {
	items.append(item);
}

template <class T>
bool Stack<T>::isEmpty() {
	return items.isEmpty();
}
