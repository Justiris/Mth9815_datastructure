#include "linkedlist.h"
#include "HashTable.h"

using namespace std;

template <typename K, typename V, typename H = Hasher<K>,
	typename E = EqualityPredicate<K>>
void HashTable<K, V,H,E>::Put(K key, V value) {
	int hash = hasher.HashFunction(key);
	if (!ContainsKey(key)) table[hash].Add(HashNode<K, V>(key, value));
}

template <typename K, typename V, typename H = Hasher<K>,
	typename E = EqualityPredicate<K>>
V HashTable<K, V, H, E>::Get(K key) {
	if (ContainsKey(key))
	{
		int hash = hasher.HashFunction(key);
		auto iter = table[hash].Iterator();
		while (iter.HasNext())
		{
			if (iter.Next().getKey() == key)
			{
				return iter.Next().getValue();
			}
		}
	}
	else return 0;
}

template <typename K, typename V, typename H = Hasher<K>,
	typename E = EqualityPredicate<K>>
bool HashTable<K, V, H, E>::ContainsKey(K key){
	int hash = hasher.HashFunction(key);
	auto iter = table[hash].Iterator();
	while (iter.HasNext())
	{
		if (iter.Next().getKey() == key)
		{
			return 1;
		}
	}
	return 0;
}


template <typename K, typename V, typename H = Hasher<K>,
	typename E = EqualityPredicate<K>>
int HashTable<K, V, H, E>::Size() {
	return size;
}