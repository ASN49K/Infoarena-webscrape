#include <iostream>
#include <fstream>

using namespace std;

ifstream f ("euclid2.in");
ofstream g ("euclid2.out");

int first, second;

int totalNumbers;

template <class someType>
someType euclid ( someType first, someType second )
{
    if ( first == second )
        return first;
    else
    {
        if ( first > second )
            euclid (first-second, second);
        else
            euclid (first, second-first);
    }
}

void readVariables()
{
    f >> totalNumbers;
    for ( ; totalNumbers ; totalNumbers-- )
    {
        f >> first >> second;
        g << euclid<int>(first, second)<< "\n" ;
    }
}

int main()
{
    readVariables();
}
