#pragma once
#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP
#include <iostream>
#include <vector>
#include "linkedlist.h"

template <typename K1, typename V1>				//represent the node in hashtable
class HashNode {// key-value pair
	template<typename K,typename V>
	friend class HashTable;
private:
	K1 key;			//store the key
	V1 value;		//store the value
public:
	HashNode(const K1 &key, const V1 &value) :key(key), value(value) {}		//constructor
	K1 getKey() const { return key; }			//get the key of hashnode
	V1 getValue() const { return value; }		//get the value of this node
	void setValue(V1 value)				//change the value of this node
	{
		HashNode::value = value;
	}
};


template <typename K>
class Hasher {				//represent the hash function
public:
	virtual int operator () (K key, int size) = 0;		//virtual operator to perform the hash function
};

template <typename K>
class EqualityPredicate{			//represent the function dealing with collision
public:
	virtual bool operator()(K key1, K key2) = 0;			//virtual operator to perform the check collision function
};

template <typename K>
class Hash_mod :public Hasher<K> {			//derived mod hash function
public:
	virtual int operator () (K key, int size) override {			//return mod of the size
		return key%size;}
};

template <typename K>
class isEqual :public EqualityPredicate<K> {		//derived equality function
public:
	virtual bool operator ()(K key1, K key2) {			//return if two keys are equal
		return key1 == key2;}
};

const int _Size = 1000;			//default hash table size

template <typename K, typename V>
class HashTable {				//represent the hashtable
private:
	vector<LinkedList<HashNode<K, V> > > table;			//use a linkedlist of hashnode as every storage blcok
	int size;					//present current maximum size

public:
	HashTable() {			//consturctor
		size = _Size;
		table.resize(1000);		//create a new table
	};
	~HashTable(){};			//default destructor
	void Put(K key, V value);		//put a pair into the hashtable
	V Get(K key);			//get the value using key
	bool ContainsKey(K key);		//return if contains this key
	int Size();			//return current maximum size
	void Print(int id);			//print all pairs stored in the block with provided index 
};



#endif  // hASHTABLE_HPP