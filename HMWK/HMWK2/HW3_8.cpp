#include <iostream>
#include "HW3_8.h"

using namespace std;

keyed_bag::keyed_bag(int cap) {
	_size = 0;
	_cap = cap;
	_hashTable = new item*[cap];
}

keyed_bag::~keyed_bag() {
	for (int i = 0; i < cap; ++i)
	{
		
	}
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

ostream& operator<<(ostream&, const keyed_bag& rhs) {

}

void keyed_bag::insert(const double& value, int key) {

}

void keyed_bag::remove(int key) {

}

bool keyed_bag::keyExist(int key) {

}