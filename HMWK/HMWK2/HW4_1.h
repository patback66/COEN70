#ifndef MYSTRING_H
#define MYSTRING_H
#include <cstdlib>  // Provides size_t

namespace hw {
    
    class string
        {
        public:
            // CONSTRUCTORS and DESTRUCTOR
            string(const char str[ ] = "");
            string(const string& source);
            ~string( );
            // MODIFICATION MEMBER FUNCTIONS
            void operator +=(const string& addend);
            void operator +=(const char addend[ ]);
            void operator +=(char addend);
            void reserve(size_t n);
            void operator =(const string& source);
            // CONSTANT MEMBER FUNCTIONS
            size_t length( ) const { return current_length; }
            char operator [ ](size_t position) const;
            // FRIEND FUNCTIONS
            friend std::ostream& operator <<(std::ostream& outs, const string& source);
            friend bool operator ==(const string& s1, const string& s2);
            friend bool operator !=(const string& s1, const string& s2);
            friend bool operator >=(const string& s1, const string& s2);
            friend bool operator <=(const string& s1, const string& s2);
            friend bool operator > (const string& s1, const string& s2);
            friend bool operator < (const string& s1, const string& s2);
    
            //Extra
            string(const char = ' ');
            //Insert substring at index
            void insert(int, const string&);
            //Delete substring in range
            void deletion(int,int);
            //Replace char with char
            void replace(char, char);
            //Replace string with string
            void replace(const string&, const string&);
            //Find index of first appearance of given char
            int search(char);
            //Find index of first appearance of given substring.
            int search(const string&);
            //Find number of appearance of given char
            int appearance(char);
        private:
            char *sequence;
            size_t allocated;
            size_t current_length;
        };
    
        // NON-MEMBER FUNCTIONS for the string class
        string operator +(const string& s1, const string& s2);
        std::istream& operator >>(std::istream& ins, string& target);
        void getline(std::istream& ins, string& target, char delimiter);
}
#endif