#ifndef STRING_H
#define STRING_H

#include <string.h>
#include <iostream>

class String
{

private:
    char* m_str;
    int m_size;
    int m_lenght;

public:
    ~String();
    String();
    String( const char* t_str );
    String( String&& that );              //rvalue (move)
    String( const String& t_str );        //copy

    String& operator=( const String& t_str );
    String& operator+=( const String& t_str );

    friend String operator+( String a, String const& b );
    friend bool operator>( const String& t_str, const String& t_str2 );
    friend bool operator<( const String& t_str, const String& t_str2 );
    friend std::ostream& operator << ( std::ostream& out, const String& point );
};

#endif // STRING_H


