#ifndef LINKEDLIST_CPP
#define LINKEDLIST_CPP
#include "linkedlist.h"
#include <iostream>

template<typename T>
Node<T>::Node(T _data, Node<T>* next = nullptr) :data(_data), next(next) {}


// the constructor for initialize empty list
template<typename T>
LinkedList<T>::LinkedList() : head(nullptr), tail(nullptr) {}

// the destructor for initialize empty list
template<typename T>
LinkedList<T>::~LinkedList() {
	Node<T>* temp = head;
	while (head) {
		head = head->next;
		delete temp;
		temp = head;
	}
}


// Add the specified element at the end of the list
template <typename T>
void LinkedList<T>::Add(T value) {
	Node<T>* newNode =new Node<T>(value);
	if (head == nullptr)
	{
		head = newNode;
		head->next = tail;
	}
	else
	{
		Node<T>* temp = head;
		while (temp->next != tail)
		{
			temp = temp->next;
		}
		temp->next = newNode;
		newNode->next = tail;
	}

}

//print the whole list
template <typename T>
void LinkedList<T>::Print() {
	Node<T>* temp = head;
	while (temp) {
		std::cout << temp->data << " ";
		temp = temp->next;
	}
	std::cout << std::endl;
	return;
}

// Add the specified element at the specified index
template <typename T>
void LinkedList<T>::Insert(T value, int index) {

	Node<T>* newNode = new Node<T>(value);
	Node<T>* temp = head;
	Node<T>* temp_next;
	if (index == 0) {
		newNode->next = head;
		head = newNode;
		return;
	}
	int count = 0;
	while (temp) {
		if (index == count + 1) {
			temp_next = temp->next;
			temp->next = newNode;
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
T LinkedList<T>::Get(int index) {
	Node<T>* temp = head;
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
int LinkedList<T>::IndexOf(T value) {

	Node<T>* temp = head;
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
T LinkedList<T>::Remove(int index) {

	Node<T>* temp = head;
	if (index == 0) {
		int val = head->data;
		if (head == tail) {
			delete temp;
			head = tail = NULL;
			return val;
		}
		head = head->next;
		delete temp;
		return val;
	}
	int count = 1;
	Node<T>* prev = head;
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

//Return size of the list
template<typename T>
int LinkedList<T>::Size()const
{
	int count = 0;
	Node<T>* temp = head;
	while (temp != nullptr)
	{
		count++;
		temp = temp->next;
	}
	return count;
}

// Return an iterator on this list
template <typename T>
ListIterator<T> LinkedList<T>::Iterator() {
	return ListIterator<T>(head);
}

template <typename T>
ListIterator<T>::ListIterator(Node<T>* head) : p(head) {}


// Return whether there is another element to return in this iterator
template <typename T>
bool ListIterator<T>::HasNext() {
	if (!p) return 0;
	return (p->next != nullptr);
}

// Return the next element in this iterator
template <typename T>
T ListIterator<T>::Next() {
	if(p->next != nullptr) return p->next->data;
}

// Return the current element in this iterator
template <typename T>
T ListIterator<T>::Current() {
	if(p != nullptr) return p->data;
}
#endif // linkedLIST_CPP

