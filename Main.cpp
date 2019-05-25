#include <iostream>
#include <process.h>
#include "HashMap.h"
#include <string>
#include <cassert>
using namespace std;
struct MyKeyHash {
	unsigned long operator()(const int &k) const {
		return k % 10;
	}
};
int main() {
	HashMap<int, string, MyKeyHash> hashMap;
	hashMap.insertNode(5, "DA");
	hashMap.insertNode(10, "NU");
	assert(hashMap.search(5) == true);
	hashMap.deleteNode(10);
	assert(hashMap.search(10) == false);
	system("pause");
	return 0;
}