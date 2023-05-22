#ifndef STRING_H
#define STRING_H
#include <iostream>

using namespace std;

class myString {
    friend ostream& operator<< (ostream& os, const myString& obj);
 
    friend istream& operator>> (istream& is, myString& obj);

    char& operator[](int i) {
        return str[i];
    }

    friend bool operator==(const myString& lhs, const myString& rhs);

    friend myString operator+(const myString& lhs, const myString& rhs);
    char* str;


public:
    myString();
    int get_length();
    void copy(char s[], int len, int pos);
    void swp(myString& rhs);
    myString(char* val);
    char* appendBack(char val);
    myString(const char *val);
    myString(const myString& source);
    myString(myString&& source);
    myString& operator=(const myString& rhs);
  
    ~myString() { delete this->str; }
};

#endif