#include <iostream>
#include "HW3_8.h"

using namespace std;

keyed_bag::keyed_bag(int cap) {
	_size = 0;
	_cap = cap;
	_hashTable = new item*[cap];

	for (int i = 0; i < cap; ++i)
	{
		_hashTable[i] = NULL;
	}
}

keyed_bag::~keyed_bag() {
	for (int i = 0; i < _cap; ++i)
	{
		deallocItems(_hashTable[i]);
	}
	delete []_hashTable;
}

keyed_bag::item::item(int inkey, double value) {
	key = inkey;
	data = value;
	next = NULL;
}

void keyed_bag::deallocItems(item* obj) {
	while(obj -> next != NULL)
		deallocItems(obj -> next);
	delete obj;
}

keyed_bag::keyed_bag(const keyed_bag& other) {

}

keyed_bag& keyed_bag::operator=(const keyed_bag& rhs) {

}

ostream& operator<<(ostream& out, const keyed_bag& rhs) {
	for (int i = 0; i < _cap; ++i)
	{
		item* p = _hashTable[i];
		while(p != NULL) {
			out << p -> data << ", ";
			p = p -> next;
		}
	}
	return out;
}

void keyed_bag::insert(const double& value, int key) {
	if (!keyExist(key))
	{
		int index = slot(key);
		if (_hashTable[index] == NULL)
		{
			item* obj = new item(key, value);
			_hashTable[index] = obj;
		} else {
			item* p = _hashTable[index];
			while (p -> next != NULL)
				p = p -> next;
			item* obj = new item(key, value);
			p -> next = obj;
		}
		_size ++;
	}
}

void keyed_bag::remove(int key) {

}

int keyed_bag::slot(int key) {
	return (key % _cap);
}

bool keyed_bag::keyExist(int key) {

}