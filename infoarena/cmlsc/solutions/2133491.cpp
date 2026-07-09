#include <bits/stdc++.h>

using namespace std;

const int mxn = 1024 + 10;

int dp[ mxn ][ mxn ];
int v1[ mxn ], v2[ mxn ];

int n, m;
stack< int > s;

int main()
{
    ios_base::sync_with_stdio( false );
    cin.tie( 0 );
    ifstream cin("cmlsc.in");
    ofstream cout("cmlsc.out");
    cin>> n >> m;
    for(int i = 1; i <= n; i++)
        cin>> v1[ i ];
    for(int i = 1; i <= m; i++)
        cin>> v2[ i ];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            if(v1[ i ] == v2[ j ])
                dp[ i ][ j ] = dp[ i - 1 ][ j - 1 ] + 1;
            else
                dp[ i ][ j ] = max(dp[ i - 1 ][ j ], dp[ i ][ j - 1 ]);
    cout<< dp[ n ][ m ] << '\n';
    int i = n, j = m;
    while (i && j){
        if (v1[ i ] == v2[ j ]){
            s.push(v1[ i ]);
            i--;
            j--;
        }
        else
            if(dp[ i ][ j - 1 ] > dp[ i - 1 ][ j ])
                j--;
            else
                i--;
    }
    while(!s.empty()){
        cout<< s.top() << ' ';
        s.pop();
    }
    return 0;
}
