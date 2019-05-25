#ifndef HASH_MAP_H
#define HASH_MAP_H
#include "HashNode.h"
#include <iostream>
using namespace std;
template <typename K>
struct KeyHash {
	unsigned long operator () (const K &key) const {
		return reinterpret_cast<unsigned long>(&key) % 111;
	}
};
template <typename K, typename V, typename F = KeyHash<K>>
class HashMap {
private:
	HashNode<K, V> **table;
	F hashFunc;
public:
	HashMap();
	void insertNode(const K &key, const V &value);
	void deleteNode(const K &key);
	bool search(const K &key) const;
	friend ostream& operator << (ostream &out, const HashMap<K, V, F> &hashMap);
};
template <typename K, typename V, typename F>
HashMap<K, V, F>::HashMap() {
	table = new HashNode<K, V>*[111]();
}
template <typename K, typename V, typename F>
void HashMap<K, V, F>::insertNode(const K &key, const V &value) {
	int hashValue = hashFunc(key);
	HashNode<K, V>* prev = NULL;
	HashNode<K, V>* entry = table[hashValue];
	while (entry != NULL && entry->getKey() != key) {
		prev = entry;
		entry = entry->getNext();
	}
	if (entry == NULL) {
		entry = new HashNode<K, V>(key, value);
		if (prev == NULL) {
			table[hashValue] = entry;
		}
		else {
			prev->setNext(entry);
		}
	}
	else {
		entry->setValue(value);
	}
}
template <typename K, typename V, typename F>
void HashMap<K, V, F>::deleteNode(const K &key) {
	int hashValue = hashFunc(key);
	HashNode<K, V>* prev = NULL;
	HashNode<K, V>* entry = table[hashValue];
	while (entry != NULL && entry->getKey() != key) {
		prev = entry;
		entry = entry->getNext();
	}
	if (entry == NULL) {
		return;
	}
	else {
		if (prev == NULL) {
			table[hashValue] = entry->getNext();
		}
		else {
			prev->setNext(entry->getNext());
		}
		delete entry;
	}
}
template <typename K, typename V, typename F>
bool HashMap<K, V, F>::search(const K &key) const {
	int hashValue = hashFunc(key);
	HashNode<K, V>* entry = table[hashValue];
	while (entry != NULL) {
		if (entry->getKey() == key) {
			return true;
		}
		entry = entry->getNext();
	}
	return false;
}
template <typename K, typename V, typename F>
ostream& operator << (ostream &out, const HashMap<K, V, F> &hashMap) {
	for (int i = 0; i < 111; i++) {
		while (hashMap.table[i] != NULL) {
			out << "key = " << hashMap.table[i]->getKey() << " value = " << hashMap.table[i]->getValue() << "\n";
		}
	}
	return out;
}
#endif