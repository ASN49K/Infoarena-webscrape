#include <fstream>

using namespace std;

ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");

int cmmdc ( int x, int y );

int main()
{
    int t, a, b;

    fin >> t;
    while ( t-- )
    {
        fin >> a >> b;
        fout << cmmdc ( a, b ) << '\n';
    }

    return 0;
}

int cmmdc ( int x, int y )
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
