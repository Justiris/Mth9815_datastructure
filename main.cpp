#include <iostream>
#include "linkedlist.h"
#include "linkedlist.cpp"
#include "doublelinked.h"
#include "doublelinked.cpp"
#include "HashTable.h"
#include "HashTable.cpp"
using namespace std;


int main() {
	LinkedList<int> a;
	a.Add(2);
	a.Add(4);
	cout<<"my linkedlist contains: ";
	a.Print();
	cout <<"size of linkedlist"<< a.Size() << endl;
	auto iter = a.Iterator();
	cout << "after removing the element 1, my linkedlist contains: "; 
	a.Remove(1);
	a.Print();
	cout << "if head of my linkedlist has next element, print 1 else print 0. result: ";
	cout << iter.HasNext()<<"\n";

	cout << endl << endl;

	DoubleLinkedList<int> b;
	cout << "test double linked list" << endl;
	b.Add(5);
	b.Add(3);
	cout << "my doublelinkedlist contains: ";
	b.Print();
	b.Insert(12,1);
	cout << "after inseting 12 into slot 1, my linkedlist contains: ";
	b.Print();
	b.Remove(2);
	cout << "after removing the element 1, my linkedlist contains: ";
	b.Print();

	cout << endl << endl;

	HashTable<int, int> mytable;
	cout << "test Hashtable" << endl;
	mytable.Put(4, 10);
	mytable.Put(12, 25);
	mytable.Put(17, 3);
	mytable.Put(20, 96);
	cout << "if mytable contains key 12, print 1 else print 0. result: "<<mytable.ContainsKey(12) << '\n';
	cout << "if mytable contains key 5, print 1 else print 0. result: "<<mytable.ContainsKey(5) << endl;
	cout << "get the value of key 17:  "<<mytable.Get(17) << '\n';
	return 0;
}
