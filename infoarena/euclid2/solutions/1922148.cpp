#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second

ifstream fin( "euclid2.in" );
ofstream fout( "euclid2.out" );

int x,y,t;

int euclid( int x, int y )
{
    int r = x % y;
    while( r )
    {
        x = y;
        y = r;
        r = x % y;
    }
    return y;
}

int main()
{

    fin>>t;
    while( t-- )
    {
        fin>>x>>y;
        fout<<euclid( x , y )<<'\n';
    }

return 0;
}
