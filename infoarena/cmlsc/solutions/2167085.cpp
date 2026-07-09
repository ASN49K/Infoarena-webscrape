#include <fstream>
#define N 1025

using namespace std;

ifstream fin( "cmlsc.in" );
ofstream fout( "cmlsc.out" );

int a[N], b[N];
int n, m;
int d[N][N], sir[N], best;

void read()
{
    int i;
    fin >> n >> m;
    for ( i = 1; i <= n; ++i )
         fin >> a[i];
    for ( i = 1; i <= n; ++i )
         fin >> b[i];
    fin.close();
}

void cmlsc()
{
    int i, j;
    for ( i = 1; i <= n; ++i )
         for ( j = 1; j <= m; ++j )
              if ( a[i] == b[j] )
                  d[i][j] = 1 + d[i-1][j-1];
              else d[i][j] = max( d[i-1][j], d[i][j-1] );
    for ( i = n, j = m; i; )
         { if ( a[i] == b[j] )
               { sir[++best] = a[i];
                 i--; j--;
               }
           else if ( d[i-1][j] < d[i][j-1] ) --j;
                else --i;
         }
    fout << best << '\n';
    for ( i = best; i; --i )
         fout << sir[i] << ' ';
}

int main()
{   read();
    cmlsc();
    fout.close();
    return 0;
}
