#include "linkedlist.h"
#include "HashTable.h"

using namespace std;

//put a pair into the hashtable
template <typename K, typename V>
void HashTable<K, V>::Put(K key, V value) {			//put<key,value>into the hashtable
	Hash_mod<K> Hash_Func;
	int hash = Hash_Func(key, size);		//calculate its hash value
	if (!ContainsKey(key)) table[hash].Add(HashNode<K, V>(key, value));		//put <key,value> into table[hash]
}

//get the value using key
template <typename K, typename V>
V HashTable<K, V>::Get(K key) {			//using key to get the paired value
	if (ContainsKey(key))			//first check if contains this key. if so find the block
	{
		Hash_mod<K> Hash_Func;
		int hash = Hash_Func(key, size);
		auto iter = table[hash].Iterator();
		if (iter.Current().getKey() == key)
		{
			return iter.Current().getValue();
		}
		while (iter.HasNext())			//treverse the linkedlist to find the pair has the same key 
		{
			if (iter.Next().getKey() == key)
			{
				return iter.Next().getValue();
			}
		}
	}
}

//return if contains this key
template < typename K, typename V >
bool HashTable<K, V>::ContainsKey(K key){			//first calculate the hash value of given key
	Hash_mod<K> Hash_Func;				
	int hash = Hash_Func(key, size);
	auto iter = table[hash].Iterator();
	if (iter.Current().getKey() == key)
	{
		return 1;
	}
	while (iter.HasNext())			//check if the linkedlist has a node containing the same key
	{
		if (iter.Next().getKey() == key)
		{
			return 1;
		}
	}
	return 0;
}

//return current maximum size
template <typename K, typename V>
int HashTable<K, V>::Size() {			//return the current maximum size
	return size;
}

//print all pairs stored in the block with provided index 
template <typename K, typename V>
void HashTable<K, V>::Print(int id) {			//treverse the specific block to print all the element
	auto iter = table[id].Iterator();
	while (iter.HasNext())
	{
		cout << iter.Current().getKey() << '\t' << iter.Current().getValue() << "\n";
	}
	cout << iter.Current().getKey() << '\t' << iter.Current().getValue() << "\n";
}