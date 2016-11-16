#ifndef LINKEDLIST_CPP
#define LINKEDLIST_CPP
#include "linkedlist.h"
#include <iostream>



template <typename T1>
ListIterator<T1>::ListIterator(Node<T1>* head) : p(head) {} //create an iterator point to the head of linkedlist


//check if the next element is null
template <typename T1>
bool ListIterator<T1>::HasNext() {		
	if (!p) return 0;		//if p is NULL then definitely no next element
	return (p->next != NULL);		//otherwise check if next node is null
}

//return the data of next node
template <typename T1>
T1 ListIterator<T1>::Next() {		
	if (p->next != NULL) return p->next->data;		//if next node isn't null, then return its data
}

//return the data of current node
template <typename T1>
T1 ListIterator<T1>::Current() {
	if (p != NULL) return p->data;		//if current node isn't null, then return its data
}
#endif // linkedLIST_CPP

// the constructor for initialize empty list
template<typename T2>
LinkedList<T2>::LinkedList() : head(NULL), tail(NULL) {}

// the destructor for initialize empty list
template<typename T2>
LinkedList<T2>::~LinkedList() {
	Node<T2>* temp = head;		//delete every pointer in turns
	while (head) {
		head = head->next;
		delete temp;
		temp = head;
	}
}


// Add the specified element at the end of the list
template <typename T2>
void LinkedList<T2>::Add(T2 value) {
	Node<T2>* newNode =new Node<T2>(value);		//create a node contains the value
	if (head == NULL)		//if linkedlist is empty, create a head node with provided value
	{
		head = newNode;
		head->next = tail;
	}
	else      
	{											//otherwise find the node before tail, and put newnode inside it
		Node<T2>* temp = head;
		while (temp->next != tail)
		{
			temp = temp->next;
		}
		temp->next = newNode;
		newNode->next = tail;
	}

}

//print the whole list
template <typename T2>
void LinkedList<T2>::Print() {			//traverse the linkedlist and print every element's data
	Node<T2>* temp = head;
	while (temp) {
		std::cout << temp->data << " ";
		temp = temp->next;
	}
	std::cout << std::endl;
	return;
}

// Add the specified element at the specified index
template <typename T2>
void LinkedList<T2>::Insert(T2 value, int index) {			//first find the element with index = provided index-1

	Node<T2>* newNode = new Node<T2>(value);				//create a node to contain the data
	Node<T2>* temp = head;
	Node<T2>* temp_next;
	if (index == 0) {
		newNode->next = head;
		head = newNode;
		return;
	}
	int count = 0;											//put the newnode inside them
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
template <typename T2>
T2 LinkedList<T2>::Get(int index) {								//treverse the linkedlist to find the element with provide index
	Node<T2>* temp = head;
	int count = 0;
	while (temp) {
		if (index == count)
			return temp->data;
		count++;
		temp = temp->next;
	}
}


// Retrieve the index of the specified element (-1 if it does not exist in the list
template <typename T2>
int LinkedList<T2>::IndexOf(T2 value) {					//treverse the linkedlist to check if contains the element
														//return the index of first found element		
	Node<T2>* temp = head;		
	int ind = 0;
	while (temp) {
		if (temp->data == value)
			return ind;
		temp = temp->next;
		ind++;

	}
	return -1;										//if linkedlist doesn;t contains this value, return -1

}



// Remove the element at the specified index and return it
template <typename T2>
T2 LinkedList<T2>::Remove(int index) {

	Node<T2>* temp = head;												//if index == 0, means want to remove current head
	if (index == 0) {													//then first get head->next, then delete the head and put a new head
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
	Node<T2>* prev = head;
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
template<typename T2>
int LinkedList<T2>::Size()const							//treverse the linkedlist and count the number of element
{
	int count = 0;
	Node<T2>* temp = head;
	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	return count;
}

// Return an iterator on this list
template <typename T2>
ListIterator<T2> LinkedList<T2>::Iterator() {			
	return ListIterator<T2>(head);
}



