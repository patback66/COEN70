#include <iostream>
#include <assert.h>
#include "HW4_1.h"

using namespace std;

hw::string::string(const char str[ ]) {
    current_length = strlen(str);
    allocated  = current_length + 1;
    sequence = new char[allocated];
    strcpy(sequence, str);
}

hw::string::string(const hw::string& source) {
    sequence = NULL;
    *this = source;
}

hw::string::~string() {
    if (sequence != NULL) {
        delete []sequence;
    }
}

void hw::string::operator +=(const hw::string& addend) {
    int finalLength = current_length + addend.current_length;
    if ((finalLength + 1) > allocated) {
        char* temp = new char[finalLength + 1];
        strcpy(temp, sequence);
        delete []sequence;
        sequence = temp;
        allocated = finalLength + 1;
    }
    for (int i = 0; i < addend.current_length; i++) {
        sequence[current_length + i] = addend.sequence[i];
    }
    sequence[finalLength] = '\0';
    current_length = finalLength;
}

void hw::string::operator +=(const char addend[ ]) {
    string str = string(addend);
    *this += str;
}

void hw::string::operator +=(char addend) {
    string str = string(addend);
    *this += str;
}

void hw::string::reserve(size_t n) {
    if (n > allocated) {
        char* temp = new char[n];
        strcpy(temp, sequence);
        delete []sequence;
        sequence = temp;
        allocated = n;
    }
}

void hw::string::operator =(const hw::string& source) {
    if(this != &source) {
        if(this -> sequence != NULL) {
                delete[] this -> sequence;
                this -> sequence = NULL;
        }
        
        allocated = source.allocated;
        current_length = source.current_length;
        sequence = new char[allocated];
        strcpy(sequence, source.sequence);
    }
}

char hw::string::operator [ ](size_t position) const {
    assert(position < current_length);
    return sequence[position];
}

std::ostream& hw::operator <<(std::ostream& outs, const hw::string& source) {
    outs << source.sequence;
    return outs;
}

bool operator !=(const hw::string& s1, const hw::string& s2) {
    return !(s1 == s2);
}

bool operator >=(const hw::string& s1, const hw::string& s2) {
    return (strcmp(s1.sequence, s2.sequence) >= 0);
}

bool operator <=(const hw::string& s1, const hw::string& s2) {
    return (strcmp(s1.sequence, s2.sequence) <= 0);
}

bool operator > (const hw::string& s1, const hw::string& s2) {
    return s2 < s1;
}

bool operator < (const hw::string& s1, const hw::string& s2) {
    return (strcmp(s1.sequence, s2.sequence) < 0);
}

hw::string::string(const char aChar) {
    current_length = 1;
    allocated = current_length + 1;
    sequence = new char[allocated];
    sequence[0] = aChar;
    sequence[1] = '\0';
}

void hw::string::insert(int index, const hw::string& aStr) {
    
}

void hw::string::deletion(int begin, int end) {
    
}

void hw::string::replace(char oChar, char tChar) {
    
}

void hw::string::replace(const hw::string& oStr, const hw::string& tStr) {
    
}

int hw::string::search(char aChar) {
    
}

int hw::string::search(const hw::string& tStr) {
    
}

int hw::string::appearance(char aChar) {
    
}

bool hw::operator== (const hw::string& s1, const hw::string& s2) {
    return (strcmp(s1.sequence, s2.sequence) == 0);
}