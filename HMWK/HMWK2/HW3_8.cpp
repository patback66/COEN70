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
	for (int i = 0; i < rhs._cap; ++i)
	{
		keyed_bag::item* p = rhs._hashTable[i];
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
	if (keyExist(key))
	{
		int index = slot(key);
		item* p = _hashTable[index];
		if (p -> key == key)
		{
			_hashTable[index] = p -> next;
		} else {
			item* old = p;
			p = p -> next;
			while (p != NULL) {
				if (p -> key == key)
				{
					old -> next = p -> next;
					break;
				}
				old = p;
				p = p -> next;
			}
		}

		delete p;
		_size --;
	}
}

int keyed_bag::slot(int key) {
	return (key % _cap);
}

/*
True if the key is found to be used in the hash table, else false.
*/
bool keyed_bag::keyExist(int key) {
    int index = slot(key);
    if(_hashTable[index]==NULL)
        return false;
    else {
        item* p = _hashTable[index];
        
        while(p != NULL) {
            if(p->key == key)
                return true;
            p = p->next;
        }
    }
    return false;
}
