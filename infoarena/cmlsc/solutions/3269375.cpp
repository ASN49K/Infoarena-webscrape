#include <bits/stdc++.h>

using namespace std;

char a[1025], b[1025], rasp[1025];
short ans[ 1025 ][ 1025 ], father_l[1025][1025], father_c[1025][1025];


int main()
{
    short n, m, i, j, l, c;
    ifstream fin ( "cmlsc.in");
    ofstream fout ( "cmlsc.out" );

    fin >> n >> m;
    for ( i = 1; i <= n; i ++ )
      fin >> a[i];
    for ( i = 1; i <= m; i ++ )
      fin >> b[i];

    for ( i = 1; i <= n; i ++ ) {
      for ( j = 1; j <= m; j ++ ) {
        if ( a[i] == b[j] ) {
          ans[i][j] = ans[i - 1][j - 1] + 1;
          father_l[i][j] = i -1;
          father_c[i][j] = j - 1;
        }
        else {
          if ( ans[i][j - 1] > ans[i - 1][j] ) {
            ans[i][j] = ans[i][j-1];
            father_l[i][j] = i;
            father_c[i][j] = j - 1;
          } else {
            ans[i][j] = ans[i - 1][j];
            father_l[i][j] = i - 1;
            father_c[i][j] = j;
          }
        }
      }
    }
    fout << ans[n][m] << "\n";
    l = n;
    c = m;
    short cnt = 0;
    while ( l != 0 && c != 0 ) {
      if ( a[l] == b[c] ) {
        rasp[cnt] = a[l];
        cnt ++;
      }
      i = l;
      l = father_l[l][c];
      c = father_c[i][c];
    }
    for ( i = cnt - 1; i >=0; i -- )
      fout << rasp[i] - '0' << " ";
    fout.close();
    fin.close();
    return 0;
}
