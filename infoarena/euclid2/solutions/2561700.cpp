// Solutie de 100 de puncte
#include <fstream>

using namespace std;

ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");

int cmmdc1 ( int x, int y );
int cmmdc2 ( int x, int y );

int main()
{
    int t, a, b;

    fin >> t;
    while ( t-- )
    {
        fin >> a >> b;
        fout << cmmdc2 ( a, b ) << '\n';
    }

    return 0;
}

int cmmdc1 ( int x, int y )
{
    int r = x % y;

    while ( r )
    {
        x = y;
        y = r;
        r = x % y;
    }

    return y;
}

int cmmdc2 ( int x, int y )
{
    if ( y == 0 ) return x;
    else return cmmdc2 ( y, x % y );
}
