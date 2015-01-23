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

hw::string& hw::string::operator =(const hw::string& source) {
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
    return *this;
}

char hw::string::operator [ ](size_t position) const {
    assert(position < current_length);
    return sequence[position];
}

std::ostream& hw::operator <<(std::ostream& outs, const hw::string& source) {
    outs << source.sequence;
    return outs;
}

bool hw::operator !=(const hw::string& s1, const hw::string& s2) {
    return !(s1 == s2);
}

bool hw::operator >=(const hw::string& s1, const hw::string& s2) {
    return (strcmp(s1.sequence, s2.sequence) >= 0);
}

bool hw::operator <=(const hw::string& s1, const hw::string& s2) {
    return (strcmp(s1.sequence, s2.sequence) <= 0);
}

bool hw::operator > (const hw::string& s1, const hw::string& s2) {
    return s2 < s1;
}

bool hw::operator < (const hw::string& s1, const hw::string& s2) {
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
    if (index < current_length) {
        int finalLength = current_length + aStr.current_length;
        if ((finalLength + 1) > allocated) {
            char* newSeq = new char[finalLength + 1];
            strcpy(newSeq, sequence);
            delete []sequence;
            sequence = newSeq;
        }
        for (int i = current_length;i >= index; i--) {
            sequence[i + aStr.current_length] = sequence[i];
        }
        for (int i = 0; i < aStr.current_length;i++) {
            sequence[index + i] = aStr.sequence[i];
        }
        current_length = finalLength;
    }
}

void hw::string::deletion(int index, int length) {
    if (length <= current_length - index) {
        if (index + length == current_length - 1) {
            sequence[index] = '\0';
            current_length = current_length - length;
            return;
        }
        for (int i = index; i <= current_length ; i++) {
            sequence[i] = sequence[i+length];
        }
        current_length = current_length - length;
    }
}

void hw::string::replace(char oChar, char tChar) {
    for(int i = 0; i < current_length; i++) {
        if(sequence[i] == oChar)
            sequence[i] = tChar;
    }
}

void hw::string::replace(const hw::string& oStr, const hw::string& tStr) {
    int currentIndex = 0;
    while (true) {
        int begin = this -> search(oStr, currentIndex);
        
        currentIndex = begin;
        
        if (currentIndex == -1) {
            break;
        }
        deletion(currentIndex, oStr.current_length);
        insert(currentIndex, tStr);
        
        currentIndex += tStr.current_length;
    }
}

int hw::string::search(char aChar) {
    for (int i = 0; i < current_length; i++) {
        if (sequence[i] == aChar) {
            return i;
        }
    }
    return -1;
}

int hw::string::search(const hw::string& tStr, int pos) {
    if ((current_length - pos) < tStr.current_length) {
        return -1;
    }

    int targetEnd = current_length - tStr.current_length;
    for (int i = pos; i <= targetEnd; i++) {
        if (sequence[i] == tStr.sequence[0]) {
            for (int v = 1; v < tStr.current_length; v++) {
                if (sequence[i+v] != tStr.sequence[v]) {
                    return -1;
                }
            }
            return i;
        }
    }
    
    return -1;
}

int hw::string::search(const hw::string& tStr) {
    return this -> search(tStr, 0);
}

int hw::string::appearance(char aChar) {
    int count = 0;
    for (int i = 0 ;i < current_length;i++) {
        if (sequence[i] == aChar) {
            count++;
        }
    }
    return count;
}

bool hw::operator== (const hw::string& s1, const hw::string& s2) {
    return (strcmp(s1.sequence, s2.sequence) == 0);
}