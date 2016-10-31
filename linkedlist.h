#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <iostream>
using namespace std;

template<typename T>
class Node {
public:
	T data;
	Node<T>* next;
	Node(T _data, Node<T>* next=nullptr);

};


template <typename T>
class ListIterator {
private:
	Node<T>* p;
public:
	ListIterator(Node<T>* head);
	bool HasNext();
	T Next();
	Node<T> operator *(const ListIterator &iter) { return *p; }
};


template<typename T>
class LinkedList {
private:
	Node<T>* head;
	Node<T>* tail;
public:
	LinkedList();
	~LinkedList();

	void Print();
	void Add(T value);
	void Insert(T value, int index);
	T Get(int index);
	int IndexOf(T value);
	T Remove(int index);
	int Size() const;
	ListIterator<T> Iterator();
};



#endif // LINKEDLIST_HPP

