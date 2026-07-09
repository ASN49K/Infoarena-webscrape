#include <bits/stdc++.h>

using namespace std;

int v[ 1024 ][ 1024 ], a[ 1024 ], b[ 1024 ], sir[ 1024 ], bst;

int main()
{
  ifstream cin("cmlsc.in");
  ofstream cout("cmlsc.out");
  int n, m;
  cin >> n >> m;
   for (int i = 1; i <= n; i++)
      cin >> a[ i ];
   for (int j = 1; j <= m; j++)
      cin >> b[ j ];
   for (int i = 1; i <= n; i++)
     for (int j = 1; j <= m; j++)
       if (a[ i ] == b[ j ])
        v[ i ][ j ] = 1 + v[ i - 1 ][ j - 1 ];
       else
        v[ i ][ j ] = max(v[ i - 1 ][ j ], v[ i ][ j - 1]);
   for (int i = n,j = m; i;){
       if (a[ i ] == b[ j ]){
        sir[ bst++ ] = a[ i ];
        i--; j--;
       }
       else if (v[ i - 1 ][ j ] < v[ i ][ j - 1 ])
         j--;
       else
        i--;
   }
   cout << v[ n ][ m ] << '\n';
   for (int i = bst - 1; i >= 0; i--)
     cout << sir[ i ] << " ";
}



