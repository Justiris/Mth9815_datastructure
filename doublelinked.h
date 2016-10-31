#ifndef DOUBLELINKED_HPP
#define DOUBLELINKED_HPP


template <typename T>
class DNode : public Node<T> {
public:
	DNode(T, DNode<T>* _prev = nullptr, DNode<T>* _next = nullptr);
	DNode<T> * prev;
	DNode<T> * next;

};

template<typename T>
class DoublyLinkedListIterator;

template <typename T>
class DoublyLinkedList : public LinkedList<T> {
private:
	DNode<T>* head;
	DNode<T>* tail;
public:
	DoublyLinkedList();
	~DoublyLinkedList();

	void Print();
	void Add(T value);
	void Insert(T value, int index);
	T Get(int index);
	int IndexOf(T value);
	T Remove(int index);
};

#endif // DOUBLELINKED_HPP
