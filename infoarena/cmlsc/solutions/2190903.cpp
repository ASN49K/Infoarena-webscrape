#include <fstream>
#define maxl 1024

using namespace std;

int v1[maxl+5], v2[maxl+5];
int dp[maxl+5][maxl+5]; /// subsir comun maximal care se termina la ind i in v1 si j in v2
bool viz[maxl+5][maxl+5];
int sf[maxl+5];

int mymax ( int a, int b )
{
  if ( a > b )
    return a;
  return b;
}

int calc ( int a, int b )
{
  if ( viz[a][b] == 0 )
  {
    if ( a == 0 || b == 0 )
    {
      if ( v1[a] == v2[b] )
        dp[a][b] = 1;
      else
        dp[a][b] = 0;
    }
    else if ( v1[a] == v2[b] )
      dp[a][b] = 1 + calc ( a - 1, b - 1 );
    else
      dp[a][b] = mymax ( calc ( a, b - 1 ), calc ( a - 1, b ) );
    viz[a][b] = 1;
  }
  return dp[a][b];
}

int main ()
{
  ifstream fin ( "cmlsc.in" );
  ofstream fout ( "cmlsc.out" );

  int l1, l2;

  fin >> l1 >> l2;

  int i;

  for ( i = 0; i < l1; i++ )
    fin >> v1[i];

  for ( i = 0; i < l2; i++ )
    fin >> v2[i];

  calc ( l1 - 1, l2 - 1 );
  fout << dp[l1-1][l2-1] << '\n';

  int n = 0, j;
  for ( i = l1 - 1, j = l2 - 1; i >= 0; )
  {
    if ( v1[i] == v2[j] )
    {
      sf[n++] = v1[i];
      i--;
      j--;
    }
    else if ( dp[i-1][j] < dp[i][j-1] )
      j--;
    else
      i--;
  }

  for ( i = n - 1; i >= 0; i-- )
    fout << sf[i] << ' ';

  fin.close ();
  fout.close ();

  return 0;
}
