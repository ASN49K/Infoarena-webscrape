#include <iostream>
#include <fstream>

using namespace std;
const int NMAX = 1 << 10;

int a[NMAX+1], b[NMAX+1];
int dp[NMAX+1][NMAX+1];
int sir[NMAX+1];

ifstream fin ( "cmlsc.in" );
ofstream fout ( "cmlsc.out" );

int main()
{
   int n, m;
   int i, j;
   int k;

   fin >> n >> m;
   for ( i = 1; i <= n; i ++ )
      fin >> a[i];
   for ( i = 1; i <= m; i ++ )
      fin >> b[i];

   for ( i = 1; i <= n; i ++ ){
      for ( j = 1; j <= m; j ++ ){

         if ( a[i] == b[j] )
           dp[i][j] = dp[i-1][j-1] + 1;
         else
           dp[i][j] = max ( dp[i-1][j], dp[i][j-1] );
      }
   }

   fout << dp[n][m] << '\n';

   i = n, j = m;
   k = 0;
   while ( i ){
      if ( a[i] == b[j] ){
        sir[++k] = a[i];
        i --, j --;
      }
      else if ( dp[i-1][j] > dp[i][j-1] )
        i --;
      else
        j --;
   }

   for ( i = dp[n][m]; i; i -- )
      fout << sir[i] << ' ';
    return 0;
}
