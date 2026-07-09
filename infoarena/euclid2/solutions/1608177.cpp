#include <iostream>
#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int cmmdc( long long int x, long long int y )
{
    if( y == 0 )
        return x;
    return cmmdc(y, x % y);
}

int main()
{
    long long int x, y;
    int n;

    f>>n;

    for( int i = 1; i <= n; i ++ )
    {
        f>>x>>y;
        g<<cmmdc(x,y)<<'\n';
    }

    f.close();
    g.close();
    return 0;
}
