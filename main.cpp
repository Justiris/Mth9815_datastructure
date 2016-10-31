#include <iostream>
#include "linkedlist.h"
#include "linkedlist.cpp"
#include "doublelinked.h"
#include "doublelinked.cpp"
#include "HashTable.h"
#include "HashTable.cpp"
using namespace std;

class MyHasher : Hasher<int> {
public:
	int HashFunction(int v) {
		int _v = (v > 0 ? v : -v);
		return _v % _Size;
	}
};

class MyEqual : EqualityPredicate<int> {
public:
	bool isEqual(const int &a, const int &b) { return a == b; }
};



int main() {

	LinkedList<int> a;
	cout << "test Linkedlist" << endl;
	a.Add(5);
	a.Add(1);
	a.Add(4);
	a.Insert(3,1);
	a.Print();
	cout <<a.IndexOf(1) << endl;
	a.Remove(1);
	a.Print();
	auto iter = a.Iterator();
	std::cout << iter.HasNext() << std::endl;
	std::cout << iter.Next() << std::endl;

	
	DoublyLinkedList<int> b;
	cout << "test double linked list" << endl;
	b.Add(5);
	b.Add(3);
	b.Insert(12,1);
	b.Add(8);
	b.Print();
	b.Remove(1);
	b.Print();

	/*
	HashTable<int, int, MyHasher, MyEqual> mytable;
	cout << "test Hashtable" << endl;
	for (int i = 0; i < 1000; ++i) {
		mytable.Put(i, i+10);
	}
	cout << "The value of key 2 is: " << mytable.Get(2) << endl;
	cout << "Is key 0 in this HashTable? " << mytable.ContainsKey(0) << endl;
	cout << "Is key -1 in this HashTable? " << mytable.ContainsKey(-1) << endl;
	cout << "Now, the size of the HashTable is: " << mytable.Size() << endl;

	cout << "key 999 has been removed from the HashTable." << endl;
	cout << "Now, the size of the HashTable is: " << mytable.Size() << endl;

	cout << "Tried to remove key -1 which did not exsit in the Hash Table."
		<< endl;
	cout << "Now, the size of the HashTable is: " << mytable.Size() << endl;
	*/
	return 0;
}
