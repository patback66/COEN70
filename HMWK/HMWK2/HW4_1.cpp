#include <iostream>
#include "HW4_1.h"

using namespace std;

hw::string::string(const char str[ ]) {
    current_length = strlen(str);
    allocated  = current_length +1;
    sequence = new char[allocated];
    strcpy(sequence, str);
}

hw::string::string(const hw::string& source) {
    
}

hw::string::~string() {
    
}

void hw::string::operator +=(const hw::string& addend) {
    
}

void hw::string::operator +=(const char addend[ ]) {
    
}

void hw::string::operator +=(char addend) {
    
}

void hw::string::reserve(size_t n) {
    
}

void hw::string::operator =(const hw::string& source) {
    
}

char hw::string::operator [ ](size_t position) const {
    
}

std::ostream& operator <<(std::ostream& outs, const hw::string& source) {
    
}

bool operator !=(const hw::string& s1, const hw::string& s2) {
    
}

bool operator >=(const hw::string& s1, const hw::string& s2) {
    
}

bool operator <=(const hw::string& s1, const hw::string& s2) {
    
}

bool operator > (const hw::string& s1, const hw::string& s2) {
    
}

bool operator < (const hw::string& s1, const hw::string& s2) {
    
}

hw::string::string(const char aChar = ' ') {
    
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