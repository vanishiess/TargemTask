#include <iostream>
#include "String.h"
#include <vector>
#include <algorithm>
#include <conio.h>

bool comparator( const String& t_str1, const String& t_str2 )
{
    return t_str1 > t_str2;
}

int main( int argc, char* argv[] )
{
    if ( argc == 1 )
    {
        std::cout << "no arguments";
    }
    else
    {
        std::cout << "arguments: ";
        std::vector<String>mas;
        for ( int i = 1; i < argc; i++ )
        {
            mas.push_back( String( argv[ i ] ) );
        }
        std::sort( mas.begin(), mas.end(), comparator );
        for ( const String& item : mas )
        {
            std::cout << item << " ";
        }
    }
    getch();
    return 0;
}