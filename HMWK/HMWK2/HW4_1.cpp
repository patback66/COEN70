#include <iostream>
#include <assert.h>
#include "HW4_1.h"

using namespace std;

/*
Constructor
*/
hw::string::string(const char str[ ]) {
    current_length = strlen(str);
    allocated  = current_length + 1;
    sequence = new char[allocated];
    strcpy(sequence, str);
}

/*
Copy constructor
*/
hw::string::string(const hw::string& source) {
    sequence = NULL;
    *this = source;
}

/*
Destructor
*/
hw::string::~string() {
    if (sequence != NULL) {
        delete []sequence;
    }
}

/*
Overload operator +=
*/
void hw::string::operator +=(const hw::string& addend) {
    int finalLength = current_length + addend.current_length;
    //check if need to allocate more memory
    if (finalLength > allocated) {
        char* temp = new char[finalLength + 1];
        strcpy(temp, sequence);
        delete []sequence;
        sequence = temp;
        allocated = finalLength + 1;
    }
    //add addend to the end of this
    for (int i = 0; i < addend.current_length; i++) {
        sequence[current_length + i] = addend.sequence[i];
    }
    sequence[finalLength] = '\0';
    current_length = finalLength;
}

/*
Overlaod operator += for c string
*/
void hw::string::operator +=(const char addend[ ]) {
    string str = string(addend);
    *this += str;
}

/*
Overload operator += for char
*/
void hw::string::operator +=(char addend) {
    string str = string(addend);
    *this += str;
}

/*
Reserve n memory for the string. No new memory will be allocated until this is
exceded.
*/
void hw::string::reserve(size_t n) {
    if (n > allocated) {
        char* temp = new char[n];
        strcpy(temp, sequence);
        delete []sequence;
        sequence = temp;
        allocated = n;
    }
}

/*
Overload operator =
*/
hw::string& hw::string::operator =(const hw::string& source) {
    if(this != &source) {
        if(this -> sequence != NULL) {
                delete[] this -> sequence;
                this -> sequence = NULL;
        }
        
        //use already implemented functions to allocate and copy the sequence
        allocated = source.allocated;
        current_length = source.current_length;
        sequence = new char[allocated];
        strcpy(sequence, source.sequence);
    }
    return *this;
}

/*
Overload operator []
*/
char hw::string::operator [ ](size_t position) const {
    assert(position < current_length);
    return sequence[position];
}

/*
Overload operator <<
*/
std::ostream& hw::operator <<(std::ostream& outs, const hw::string& source) {
    outs << source.sequence;
    return outs;
}

/*
Overload operator !=
*/
bool hw::operator !=(const hw::string& s1, const hw::string& s2) {
    return !(s1 == s2);
}

/*
Overload operator >=
*/
bool hw::operator >=(const hw::string& s1, const hw::string& s2) {
    return (strcmp(s1.sequence, s2.sequence) >= 0);
}

/*
Overload operator <=
*/
bool hw::operator <=(const hw::string& s1, const hw::string& s2) {
    return (strcmp(s1.sequence, s2.sequence) <= 0);
}

/*
Overload operator >
*/
bool hw::operator > (const hw::string& s1, const hw::string& s2) {
    return s2 < s1;
}

/*
Overload operator <
*/
bool hw::operator < (const hw::string& s1, const hw::string& s2) {
    return (strcmp(s1.sequence, s2.sequence) < 0);
}

/*
Constructor using char
*/
hw::string::string(const char aChar) {
    current_length = 1;
    allocated = current_length + 1;
    sequence = new char[allocated];
    sequence[0] = aChar;
    sequence[1] = '\0'; //make sure null terminated
}

/*
Insert aStr at index 
*/
void hw::string::insert(int index, const hw::string& aStr) {
    if (index < current_length) {
        int finalLength = current_length + aStr.current_length;
        //ensure enough memory is allocated
        if ((finalLength + 1) > allocated) {
            char* newSeq = new char[finalLength + 1];
            strcpy(newSeq, sequence);
            delete []sequence;
            sequence = newSeq;
        }
        //move over existing chars
        for (int i = current_length;i >= index; i--) {
            sequence[i + aStr.current_length] = sequence[i];
        }
        //add in the new chars
        for (int i = 0; i < aStr.current_length;i++) {
            sequence[index + i] = aStr.sequence[i];
        }
        current_length = finalLength;
    }
}

/*
Delete starting at index for given length
*/
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

/*
Replace all occurrences of oChar with tChar
*/
void hw::string::replace(char oChar, char tChar) {
    for(int i = 0; i < current_length; i++) {
        if(sequence[i] == oChar)
            sequence[i] = tChar;
    }
}

/*
Replace all sequences of oStr with tStr
*/
void hw::string::replace(const hw::string& oStr, const hw::string& tStr) {
    int currentIndex = 0;
    //continue while there are occurrences
    while (true) {
        int begin = this -> search(oStr, currentIndex);
        
        currentIndex = begin;
        
        //exit when there are no more occurrences
        if (currentIndex == -1) {
            break;
        }
        //delete the occurence
        deletion(currentIndex, oStr.current_length);
        //insert the new string
        insert(currentIndex, tStr);
        
        currentIndex += tStr.current_length;
    }
}

/*
Returns first occurrence of aChar, else -1
*/
int hw::string::search(char aChar) {
    for (int i = 0; i < current_length; i++) {
        if (sequence[i] == aChar) {
            return i;
        }
    }
    return -1;
}

/*
Returns the start index of tStr or -1, search starts at pos
*/
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

/*
Search for first sequence tStr, starting from the beginning
*/
int hw::string::search(const hw::string& tStr) {
    return this -> search(tStr, 0);
}

/*
Counts how many times aChar occurs in the sequence
*/
int hw::string::appearance(char aChar) {
    int count = 0;
    for (int i = 0 ;i < current_length;i++) {
        if (sequence[i] == aChar) {
            count++;
        }
    }
    return count;
}

/*
Overload operator ==
*/
bool hw::operator== (const hw::string& s1, const hw::string& s2) {
    return (strcmp(s1.sequence, s2.sequence) == 0);
}