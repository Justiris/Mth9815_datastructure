#ifndef DOUBLELINKED_HPP
#define DOUBLELINKED_HPP


template <typename T1>
class DNode : public Node<T1> { //inheritance from linkedlist's node to represent node in doublelinkedlist
	template<typename T4>
	friend class DoubleLinkedList;
private:
	DNode<T1> * prev;	//pointer to previous node
	DNode<T1> * next;	//pointer to next node
public:
	DNode(T1 value, DNode<T1>* _prev = NULL, DNode<T1>* _next = NULL) :Node<T1>(value), prev(_prev), next(_next) {} //default constructor
};

template<typename T>
class DoubleLinkedListIterator;

template <typename T>
class DoubleLinkedList : public LinkedList<T> {
private:
	DNode<T>* head;		//pointer to head Node
	DNode<T>* tail;		//pointer to tail Node
public:
	DoubleLinkedList();		//default constructor
	~DoubleLinkedList();	//default destructor

	void Print();		//Print the element inside linkedlist
	void Add(T value);		//add element into the tail of linkedlist
	void Insert(T value, int index);		//insert element into a specific place of linkedlist
	T Get(int index);			//get the data of a specific index
	int IndexOf(T value);		//find the data and return its index
	T Remove(int index);		//remove node in a specific index
};

#endif // DOUBLELINKED_HPP
