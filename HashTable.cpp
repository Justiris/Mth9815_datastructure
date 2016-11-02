#include "linkedlist.h"
#include "HashTable.h"

using namespace std;

template <typename K, typename V>
void HashTable<K, V>::Put(K key, V value) {
	Hash_mod<K> Hash_Func;
	int hash = Hash_Func(key, size);
	if (!ContainsKey(key)) table[hash].Add(HashNode<K, V>(key, value));
}

template <typename K, typename V>
V HashTable<K, V>::Get(K key) {
	if (ContainsKey(key))
	{
		Hash_mod<K> Hash_Func;
		int hash = Hash_Func(key, size);
		auto iter = table[hash].Iterator();
		if (iter.Current().getKey() == key)
		{
			return iter.Current().getValue();
		}
		while (iter.HasNext())
		{
			if (iter.Next().getKey() == key)
			{
				return iter.Next().getValue();
			}
		}
	}
}

template <typename K, typename V>
bool HashTable<K, V>::ContainsKey(K key){
	Hash_mod<K> Hash_Func;
	int hash = Hash_Func(key, size);
	auto iter = table[hash].Iterator();
	if (iter.Current().getKey() == key)
	{
		return 1;
	}
	while (iter.HasNext())
	{
		if (iter.Next().getKey() == key)
		{
			return 1;
		}
	}
	return 0;
}


template <typename K, typename V>
int HashTable<K, V>::Size() {
	return size;
}

template <typename K, typename V>
void HashTable<K, V>::Print(int id) {
	auto iter = table[id].Iterator();
	while (iter.HasNext())
	{
		cout << iter.Current().getKey() << '\t' << iter.Current().getValue() << "\n";
	}
	cout << iter.Current().getKey() << '\t' << iter.Current().getValue() << "\n";
}