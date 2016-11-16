#pragma once
#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP
#include <iostream>
#include <vector>
#include "linkedlist.h"

template <typename K, typename V>
class HashNode {// key-value pair
	template<typename K,typename V>
	friend class HashTable;
private:
	K key;
	V value;
public:
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
	virtual int operator () (K key, int size) = 0;
};

template <typename K>
class EqualityPredicate{
public:
	virtual bool operator()(K key1, K key2) = 0;
};

template <typename K>
class Hash_mod :public Hasher<K> {
public:
	virtual int operator () (K key, int size) override {
		return key%size;}
};

template <typename K>
class isEqual :public EqualityPredicate<K> {
public:
	virtual bool operator ()(K key1, K key2) {
		return key1 == key2;}
};

const int _Size = 1000;

template <typename K, typename V>
class HashTable {
private:
	vector<LinkedList<HashNode<K, V>>> table;
	int size;

public:
	HashTable() {
		size = _Size;
		table.resize(1000);
	};
	~HashTable(){};
	void Put(K key, V value);
	V Get(K key);
	bool ContainsKey(K key);
	int Size();
	void Print(int id);
};



#endif  // hASHTABLE_HPP