#include <iostream>
#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int main()
{
    int t, a, b;
    f >> t ;

    for ( int i = 0 ; i < t ; ++i )
    {
        f >> a >> b;
        while ( b )
        {
            int x = b;
            b = a%b;
            a = x;
        }
        g << a << "\n";
    }

    return 0;
}
