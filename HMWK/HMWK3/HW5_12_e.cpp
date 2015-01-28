#include <iostream>
#include "HW5_12_e.h"

using namespace std;

/*
Constructor
*/
keyed_bag::keyed_bag(int cap) {
	_size = 0;
	_cap = cap;
	_hashTable = new item*[cap];

	for (int i = 0; i < cap; ++i)
	{
		_hashTable[i] = NULL;
	}
}

/*
Destructor
*/
keyed_bag::~keyed_bag() {
	for (int i = 0; i < _cap; ++i)
	{
		if (_hashTable[i] != NULL) {
			deallocItems(_hashTable[i]);
		}
	}
	delete []_hashTable;
}

/*
Creates an item for a keyed bag
*/
keyed_bag::item::item(int inkey, double value) {
	key = inkey;
	data = value;
	next = NULL;
}

/*
Destructor for item
*/
void keyed_bag::deallocItems(item* obj) {
	while(obj -> next != NULL)
		deallocItems(obj -> next);
	delete obj;
}

/*
Copy constructor
*/
keyed_bag::keyed_bag(const keyed_bag& other) {
	_cap = 0;
	_size = 0;
	*this = other;
}

/*
Overload the e operator
*/
keyed_bag& keyed_bag::operator=(const keyed_bag& rhs) {
	if (this != &rhs)
	{
		//clear
		for (int i = 0; i < _cap; i++)
		{
			if (_hashTable[i] != NULL) {
				deallocItems(_hashTable[i]);
			}
		}
		
		if (_cap == 0) {
			_hashTable = new item*[rhs._cap];
		}
		
		//copy everything
		for (int i = 0; i < rhs._cap; ++i)
		{
			if (rhs._hashTable[i] != NULL)
			{
				item *head = rhs._hashTable[i];
				_hashTable[i] = new item(head -> key, head -> data);
				item *p = _hashTable[i];
				head = head -> next;
				while(head != NULL) {
					item *obj = new item(head -> key, head -> data);
					p -> next = obj;
					p = obj;
					head = head -> next;
				}
			}
		}
		_size = rhs._size;
		_cap = rhs._cap;
	}
	return *this;
}

/*
Overload teh << operator
*/
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

/*
Insert a value with the given key. Only one value per key
*/
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

/*
Remove the item with key "key"
*/
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

/*
Return the slot for the item with the key "key"
*/
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
