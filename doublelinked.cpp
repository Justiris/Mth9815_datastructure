#include "linkedlist.h"
#include "doublelinked.h"
#include <iostream>

template<typename T>
DNode<T>::DNode(T val, DNode<T>* _prev = nullptr, DNode<T>* _next = nullptr) :Node<T>(val), prev(_prev), next(_next) {}

// the constructor for initialize empty list
template<typename T>
DoublyLinkedList<T>::DoublyLinkedList() : head(NULL), tail(NULL) {}


// the destructor for initialize empty list
template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {}



// Add the specified element at the end of the list
template <typename T>
void DoublyLinkedList<T>::Add(T value) {
	DNode<T>* newNode = new DNode<T>(value);
	if (tail == NULL) {
		//it means the list empty rightnow
		head = newNode;
		tail = newNode;
		return;
	}
	tail->next = newNode;
	tail = tail->next;
}


template <typename T>
void DoublyLinkedList<T>::Print() {
	DNode<T>* temp = head;
	while (temp) {
		std::cout << temp->data << " ";
		temp = temp->next;
	}
	std::cout << std::endl;
	return;
}


// Add the specified element at the specified index
template <typename T>
void DoublyLinkedList<T>::Insert(T value, int index) {
	DNode<T>* newNode = new DNode<T>(value);
	DNode<T>* temp = head;
	DNode<T>* temp_next;
	if (index == 0) {
		head->prev = newNode;
		newNode->next = head;
		head = newNode;
		return;
	}
	int count = 0;
	while (temp) {
		if (index == count + 1) {
			temp_next = temp->next;

			temp->next = newNode;
			newNode->prev = temp;
			temp_next->prev = newNode;
			newNode->next = temp_next;
			return;
		}
		temp = temp->next;
		count++;
	}
	return;
}



// Get the element at the specified index
template <typename T>
T DoublyLinkedList<T>::Get(int index) {
	DNode<T>* temp = head;
	int count = 0;
	while (temp) {
		if (index == count)
			return temp->data;
		count++;
		temp = temp->next;
	}
}



// Retrieve the index of the specified element (-1 if it does not exist in the list
template <typename T>
int DoublyLinkedList<T>::IndexOf(T value) {
	DNode<T>* temp = head;
	int ind = 0;
	while (temp) {
		if (temp->data == value)
			return ind;
		temp = temp->next;
		ind++;
	}
	return -1;
}



// Remove the element at the specified index and return it
template <typename T>
T DoublyLinkedList<T>::Remove(int index) {
	DNode<T>* temp = head;
	if (index == 0) {
		int val = head->data;
		if (head == tail) {
			delete temp;
			head = tail = NULL;
			return val;
		}
		head = head->next;
		head->prev = NULL;
		delete temp;
		return val;
	}
	int count = 1;
	DNode<T>* prev = head;
	temp = temp->next;
	while (temp) {
		if (index == count) {
			int val = temp->data;
			prev->next = temp->next;
			delete temp;
			return val;
		}
		count++;
		temp = temp->next;
		prev = prev->next;
	}
}

