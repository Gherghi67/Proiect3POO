#ifndef HASH_NODE_H
#define HASH_NODE_H
#include <iostream>
template <typename K, typename V>
class HashNode {
private:
	K key;
	V value;
	HashNode* next;
public:
	HashNode();
	HashNode(const K &key, const V &value);
	K getKey() const;
	V getValue() const;
	void setValue(const V &value);
	HashNode* getNext() const;
	void setNext(HashNode* next);
};
template <typename K, typename V>
HashNode<K, V>::HashNode() {
	this->key = NULL;
	this->value = NULL;
	next = NULL;
}
template <typename K, typename V>
HashNode<K, V>::HashNode(const K &key, const V &value) {
	this->key = key;
	this->value = value;
	next = NULL;
}
template <typename K, typename V>
K HashNode<K, V>::getKey() const {
	return key;
}
template <typename K, typename V>
V HashNode<K, V>::getValue() const {
	return value;
}
template <typename K, typename V>
void HashNode<K, V>::setValue(const V &value) {
	this->value = value;
}
template <typename K, typename V>
HashNode<K, V>* HashNode<K, V>::getNext() const {
	return next;
}
template<typename K, typename V>
void HashNode<K, V>::setNext(HashNode* next) {
	this->next = next;
}
#endif