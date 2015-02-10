#include "Pair.h"
#include <list>
#include <iostream>

using namespace std;

template<typename K, typename V>
class map {
public:
    /**
     Inserts a value into the map.
     @param key the key to insert
     @param	value the value	to insert
     */
    void insert(K key, V value) {
        if(!contains_key(key)) {
            data.push_back(*new Pair<K, V>(key, value));
        }
    }
    /**
     Determines	whether	the	map	contains a given key.
     @param	key	the	key	to	check	for
     */
    bool contains_key(K	key) {
        //construct iterator of pair type for data, iterate through
        for (typename list<Pair<K,V>>::iterator it = data.begin(); it != data.end(); it++) {
            if(it->get_first() == key)
                return true;
        }
        return false;
    }
    /**
     Retrieves the value of a given	key.
     @param	key	the	key	to find
     @return the value, NULL if not found.
     */
    V value_of(K key) {
        for (typename list<Pair<K,V>>::iterator it=data.begin(); it != data.end(); it++) {
            if(it->get_first() == key)
                return it->get_second();
        }
        //return NULL if not found
        cout << "Not found" << endl;
        return NULL;
    }
    /**
     Removes the key and value.
     @param	key	the	key	to	find
     */
    void remove_key(K key) {
        for (typename list<Pair<K,V>>::iterator it=data.begin(); it != data.end(); it++) {
            if(it->get_first() == key) {
                data.erase(it);
                return;
            }
        }
    }
private:
    list<Pair<K,V>>	data;
};