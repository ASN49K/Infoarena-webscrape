#include <iostream>
#include <fstream>
using namespace std;
ifstream f ( "nim.in" );
ofstream g ( "nim.out" );
int main()
{
    int T;
    f >> T;

    while ( T-- )
    {
        int nr, n, S = 0;
        f >> n;

        for ( int i = 1; i <= n; i++ )
        {
            f >> nr;
            S ^= nr;
        }

        if ( S != 0 )
            g << "DA\n";
        else g << "NU\n";
    }

    return 0;
}
