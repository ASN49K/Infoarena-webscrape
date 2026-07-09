#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int main()
{
    int T, a, b;

    f >> T;

    while( T )
    {
        f >> a >> b;

        while( b )
        {
            int rest = a % b;
            a = b;
            b = rest;
        }
        T--;
        g << a << "\n";
    }

    return 0;
}
