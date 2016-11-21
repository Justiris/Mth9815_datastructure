#include "linkedlist.h"
#include "doublelinked.h"
#include <iostream>



// the constructor for initialize empty list
template<typename T>
DoubleLinkedList<T>::DoubleLinkedList() : head(NULL), tail(NULL) {}


// the destructor for initialize empty list
template<typename T>
DoubleLinkedList<T>::~DoubleLinkedList() {}



// Add the specified element at the end of the list
template <typename T>
void DoubleLinkedList<T>::Add(T value) {		//create a node contains the value
	DNode<T>* newNode = new DNode<T>(value);
	if (tail == NULL) {				//if linkedlist is empty, create a head node with provided value
		//it means the list empty rightnow
		head = newNode;
		tail = newNode;
		return;
	}
	tail->next = newNode;
	tail = tail->next;
}


template <typename T>
void DoubleLinkedList<T>::Print()	 // traverse the linkedlist and print every element's data
{
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
void DoubleLinkedList<T>::Insert(T value, int index) {			//first find the element with index = provided index-1
	DNode<T>* newNode = new DNode<T>(value);			//create a node to contain the data
	DNode<T>* temp = head;
	DNode<T>* temp_next;
	if (index == 0) {
		head->prev = newNode;
		newNode->next = head;
		head = newNode;
		return;
	}
	int count = 0;							//put the newnode inside them
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
T DoubleLinkedList<T>::Get(int index) {					//treverse the linkedlist to find the element with provide index
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
int DoubleLinkedList<T>::IndexOf(T value) {								//treverse the linkedlist to check if contains the element	
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
T DoubleLinkedList<T>::Remove(int index) {				//if index == 0, means want to remove current head
	DNode<T>* temp = head;
	if (index == 0) {							//then first get head->next, then delete the head and put a new head
		int value = head->data;
		if (head == tail) {
			delete temp;
			head = tail = NULL;
			return value;
		}
		head = head->next;
		head->prev = NULL;
		delete temp;
		return value;
	}
	int count = 1;
	DNode<T>* prev = head;
	temp = temp->next;
	while (temp) {
		if (index == count) {
			int value = temp->data;
			prev->next = temp->next;
			delete temp;
			return value;
		}
		count++;
		temp = temp->next;
		prev = prev->next;
	}
}

