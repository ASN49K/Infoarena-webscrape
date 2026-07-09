#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second

ifstream fin( "nim.in" );
ofstream fout( "nim.out" );

int t,i,n,x,ans;

int main()
{
    fin>>t;
    while( t-- )
    {
        fin>>n;
        for( i = 1 ; i <= n ; i++ )
        {
            fin>>x;
            ans ^= x;
        }
        if( ans == 0 )
            fout<<"DA\n";
        else
            fout<<"NU\n";
        ans = 0;
    }

return 0;
}
