#pragma once
#include "LinkedList.h"

template<class T>
class Queue {
private:
	LinkedList <T> items;

public:
	Queue();
	~Queue();
	void enqueue(T item);
	T dequeue();
	T peek();
	bool isEmpty();
};

template <class T>
Queue<T>::Queue() {
}

template <class T>
Queue <T>:: ~Queue() {
}

template <class T>
void Queue<T>::enqueue(T item) {
	items.addHead(item);
}

template <class T>
T Queue<T>::dequeue() {
	return items.removeTail();
}

template <class T>
T Queue<T>::peek() {
	return items.retrieveTail();
}

template <class T>
bool Queue<T>::isEmpty() {
	return items.isEmpty();
}
