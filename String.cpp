
#include "String.h"
#include <string.h>

String::String()
{
    m_str = nullptr;
    m_size = 0;
    m_lenght = 0;
}

String::~String()
{
    delete[] m_str;
    m_str = nullptr;
}

String::String( const String& t_str )
{
    this->m_lenght = t_str.m_lenght;
    this->m_size = t_str.m_size;
    this->m_str = new char[ this->m_size ];
    strcpy_s( this->m_str, this->m_size, t_str.m_str );
}

String::String( const char* t_str )
{
    m_lenght = strlen( t_str );
    m_size = m_lenght + 1;
    m_str = new char[ m_size ];
    strcpy_s( m_str, m_size, t_str );
}

String::String( String&& t_str )  
{
    this->m_str = t_str.m_str;
    this->m_size = t_str.m_size;
    this->m_lenght = t_str.m_lenght;
    t_str.m_str = nullptr;
}

String& String::operator=( const String& t_str )
{
    if ( this != &t_str )
    {
        m_lenght = t_str.m_lenght;
        m_size = t_str.m_size;
        m_str = new char[ m_size ];

        strcpy_s( m_str, m_size, t_str.m_str );
    }

    return *this;
}

String& String::operator+=( const String& t_str )
{
    m_lenght = m_lenght + t_str.m_lenght;
    m_size = m_lenght + 1;

    char* buffer = new char[ m_size ];
    strcpy_s( buffer, m_size, m_str );
    strcat_s( buffer, m_size, t_str.m_str );

    delete[] m_str;
    m_str = buffer;

    return *this;
}

//friends
std::ostream& operator<< ( std::ostream& out, const String& t_str )
{
    out << t_str.m_str;
    return out;
}

String operator+( String a, String const& b ) {
    a += b;
    return a;
}

bool operator > ( const String& t_str1, const String& t_str2 )
{
    return _stricmp( t_str1.m_str, t_str2.m_str ) > 0;
}

bool operator < ( const String& t_str1, const String& t_str2 )
{
    return _stricmp( t_str1.m_str, t_str2.m_str ) < 0;
}
