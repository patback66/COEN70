#include <iostream>
#include "HW4_1.h"

using namespace std;

hw::string::string(const char str[ ]) {
    current_length = strlen(str);
    allocated  = current_length +1;
    characters = new char[allocated];
    strcpy(characters, str);
}

bool hw::string::operator== (const string& s1, const string& s2) {
    return (strcomp(s2.characters, s2.characters) == 0);
}