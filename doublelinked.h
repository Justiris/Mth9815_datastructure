#ifndef DOUBLELINKED_HPP
#define DOUBLELINKED_HPP


template <typename T>
class DNode : public Node<T> {
	template<typename T>
	friend class DoubleLinkedList;
private:
	DNode<T> * prev;
	DNode<T> * next;
public:
	DNode(T value, DNode<T>* _prev = nullptr, DNode<T>* _next = nullptr);
};

template<typename T>
class DoubleLinkedListIterator;

template <typename T>
class DoubleLinkedList : public LinkedList<T> {
private:
	DNode<T>* head;
	DNode<T>* tail;
public:
	DoubleLinkedList();
	~DoubleLinkedList();

	void Print();
	void Add(T value);
	void Insert(T value, int index);
	T Get(int index);
	int IndexOf(T value);
	T Remove(int index);
};

#endif // DOUBLELINKED_HPP
