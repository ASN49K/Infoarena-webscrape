#include <bits/stdc++.h>

using namespace std;

short n, m;
short a[ 1030 ], b[ 1030 ];
short v[ 1030 ][ 1030 ];
vector< int > p;

int main()
{
    ifstream cin("cmlsc.in");
    ofstream cout("cmlsc.out");
    cin>> n >> m;
    for(short i = 1; i <= n; i++)
        cin>> a[ i ];
    for(short i = 1; i <= m; i++)
        cin>> b[ i ];
    for(short i = 1; i <= n; i++)
    for(short j = 1; j <= m; j++)
        if(a[ i ] == b[ j ]){
            v[ i ][ j ] = 1 + v[ i - 1 ][ j - 1 ];
            p.push_back(a[ i ]);
        }
        else
            v[ i ][ j ] = max(v[ i - 1 ][ j ], v[ i ][ j - 1 ]);
    cout<< v[ n ][ m ] << '\n';
    for(short i = 0; i < p.size(); i++)
        cout<< p[ i ] << ' ';
    return 0;
}
