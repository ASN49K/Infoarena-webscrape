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
        int x;
        while ( b != 0)
        {
            x = b;
            b = a%b;
            a = x;
        }
        g << a << endl;
    }

    return 0;
}
