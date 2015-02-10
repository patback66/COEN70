//
//  main.cpp
//  lab6
//
//  Created by matthew alexander koken on 2/9/15.
//  Copyright (c) 2015 matthew alexander koken. All rights reserved.
//

#include <iostream>
#include "map.h"

int main(int argc, const char * argv[])
{
    map<string, int> m;
    //case: insert
    m.insert("first", 1);
    //case: insert duplicate key
    m.insert("first", 3);
    m.insert("second", 2);
    
    //case: check contains existing key
    m.contains_key("first");
    //case: check contains nonexistant key
    m.contains_key("third");
    
    //case: get value of existing key
    cout << m.value_of("first") << endl; //expected: 1
    //case: get value of nonexistant key
    cout << m.value_of("third") << endl; //expected: not found, \n 0
    
    m.remove_key("first"); //case: remove existing key
    m.remove_key("third"); //case: remove key that doesn't exist
}

