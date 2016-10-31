#pragma once
#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP
#include <iostream>
#include <vector>
#include "linkedlist.h"

template <typename K, typename V>
class HashNode {
public:
	// key-value pair
	K key;
	V value;

	HashNode(const K &key, const V &value) :key(key), value(value) {}
	K getKey() const { return key; }
	V getValue() const { return value; }
	void setValue(V value)
	{
		HashNode::value = value;
	}
};


template <typename K>
class Hasher {
public:
	virtual int HashFunction(K key) = 0;
};

template <typename K>
class EqualityPredicate {
public:
	virtual bool isEqual(const K &key1, const K &key2) = 0;
};

const int _Size = 1000;

template <typename K, typename V, typename H = Hasher<K>,
	typename E = EqualityPredicate<K>>
class HashTable {
private:
	vector<LinkedList<HashNode<K, V>>> table;
	H hasher;
	E equalpred;
	int size;

public:
	HashTable() {
		size = _Size;
		//LinkedList<HashTable<K, V>> a;
		table.resize(1000);
	};
	~HashTable(){};
	void Put(K key, V value);
	V Get(K key);
	bool ContainsKey(K key);
	int Size();
};



#endif  // hASHTABLE_HPP