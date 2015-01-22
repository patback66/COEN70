#include <iostream>
#include "HW4_1.h"

using namespace std;

hw::string::string(const char str[ ]) {
    current_length = strlen(str);
    allocated  = current_length +1;
    sequence = new char[allocated];
    strcpy(sequence, str);
}

bool hw::operator== (const hw::string& s1, const hw::string& s2) {
    return (strcmp(s1.sequence, s2.sequence) == 0);
}