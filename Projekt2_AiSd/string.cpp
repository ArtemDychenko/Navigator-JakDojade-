#pragma warning(disable : 4996)
#include "string.h"



myString& myString::operator=(const myString& rhs)
{
    if (this == &rhs)
        return *this;
    delete[] str;
    str = new char[strlen(rhs.str) + 1];
    strcpy(str, rhs.str);
    return *this;
}

// Overloading the plus operator
myString operator+(const myString& lhs, const myString& rhs) 
{
    int length = strlen(lhs.str) + strlen(rhs.str);

    char* buff = new char[length + 1];

    strcpy(buff, lhs.str);
    strcat(buff, rhs.str);
    buff[length] = '\0';

    myString temp{ buff };

    delete[] buff;

    return temp;
}
// Overloading the stream
// extraction operator
istream& operator>>(istream& is, myString& obj) 
{
    char* buff = new char[1000];
    memset(&buff[0], 0, sizeof(buff));
    is >> buff;
    obj = myString{ buff };
    delete[] buff;
    return is;
}



// Overloading the stream
// insertion operator
ostream& operator<<(ostream& os, const myString& obj) 
{
    os << obj.str;
    return os;
}

// Function for swapping string
void myString::swp(myString& rhs)
{
    myString temp{ rhs };
    rhs = *this;
    *this = temp;
}

// Function to copy the string
void myString::copy(char s[], int len, int pos) 
{
    for (int i = 0; i < len; i++) {
        s[i] = str[pos + i];
    }
    s[len] = '\0';
}

// Function to implement get_length
int myString::get_length() 
{
    int k = strlen(str);
    return k;
}

bool operator==(const myString& lhs, const myString& rhs) 
{
    int i = 0;
    while (lhs.str[i] != '\0' && rhs.str[i] != '\0') {
        if (lhs.str[i] != rhs.str[i]) {
            return false;
        }
        i++;
    }
    return lhs.str[i] == '\0' && rhs.str[i] == '\0';
}


myString::myString()  
{
    str = new char[1];
    str[0] = '\0';
}


myString::myString(char* val) 
{
    if (val == nullptr) {
        str = new char[1];
        str[0] = '\0';
    }
    else {
        str = new char[strlen(val) + 1];
        strcpy(str, val);
        str[strlen(val)] = '\0';
    }
}

char* myString::appendBack(char val) {
    int len = get_length();
    char* newStr = new char[len + 2];

    for (int i = 0; i < len; i++) {
        newStr[i] = str[i];
    }

    newStr[len] = val;
    newStr[len + 1] = '\0';

    return newStr;
}

myString::myString(const char* val)
{
    str =  new char[strlen(val) + 1];
    strcpy(str, val);
    str[strlen(val)] = '\0';
}


myString::myString(const myString& source) {
    str = new char[strlen(source.str) + 1];
    strcpy(str, source.str);
}

  
myString::myString(myString&& source) {
    str = source.str;
    source.str = nullptr;
}