#include <fstream>
#include <queue>
#include <vector>
#include <iostream>
using namespace std;

ifstream f ("nim.in");
ofstream g ("nim.out");

int t, n, s, a;

int main()
{
    f>>t;

    while ( t-- )
    {
        f>>n;

        f>>s;
        n--;

        while ( n-- )
        {
            f>>a;

            s = s xor a;

        }

        if ( s == 0 )
        {
            g<<"NU\n";
        }
        else
        {
            g<<"DA\n";
        }

    }

    return 0;
}
