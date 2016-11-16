#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <iostream>
using namespace std;

template<typename T>
class Node { //Node represent the data set of every element in linkedlist
	template<typename T2>
	friend class LinkedList;
	template<typename T1>
	friend class ListIterator;
	template<typename T3>
	friend class DoubleLinkedList;
private:
	T data;		//data stores the value of element in linkedlist
	Node<T>* next;		//*next is a pointer to the next element of linkedlist
public:
	Node(T _data, Node<T>* _next=NULL) :data(_data), next(_next) {}		//construct a new Node with given data
};


template <typename T1>
class ListIterator {		//ListIterator is the iterator of linkedlist
private:
	Node<T1>* p;		//*p is a pointer point to an element of linkedlist
public:
	ListIterator(Node<T1>* head);		//create an iterator point to the head of linkedlist
	bool HasNext();		//check if the next element is null
	T1 Next();		//return the data of next node
	T1 Current();		//return the data of current node
};


template<typename T2>
class LinkedList {		//linkedlist represent the "linkedlist" data structure
private:
	Node<T2>* head;		//a node pointer point to the head of linkedlist
	Node<T2>* tail;		//a node pointer point to the tail of linked list
public:
	LinkedList();		//default constructor
	~LinkedList();		//default destructor

	void Print();		//Print the element inside linkedlist
	void Add(T2 value);		//add element into the tail of linkedlist
	void Insert(T2 value, int index);		//insert element into a specific place of linkedlist
	T2 Get(int index);		//get the data of a specific index
	int IndexOf(T2 value);		//find the data and return its index
	T2 Remove(int index);		//remove node in a specific index
	int Size() const;		//return the length of linkedlist
	ListIterator<T2> Iterator();		//construct a iterator of linkedlist
};



#endif // LINKEDLIST_HPP

