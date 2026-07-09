#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <list>
#include <set>
#include <map>
using namespace std;

#define NMAX 1025
#define INFILE "cmlsc.in" 
#define OUTFILE "cmlsc.out"

#define max(a,b) ((a)>(b)?(a):(b))

char a[NMAX], b[NMAX];
int sub[NMAX][NMAX];

int main()
{
  freopen(INFILE, "r", stdin);
  freopen(OUTFILE, "w", stdout);

  int n, m;
  cin >> n >> m;

  for(int i=0; i<n; i++)
    cin >> a[i];

  for(int i=0; i<m; i++)
    cin >> b[i];

  memset(sub, 0, sizeof(sub));
  for(int i=0; i<n; i++)
  for(int j=0; j<m; j++)
  {
    sub[i+1][j+1] = max(sub[i][j+1], sub[i+1][j]);
    if( a[i]==b[j] )
      sub[i+1][j+1] = max(sub[i][j]+1, sub[i+1][j+1]);
  }

	cout << (int)sub[n][m] << endl;

  for(int i=0, val=1; i<=n; i++)
  for(int j=0; j<=m; j++)
    if( sub[i][j]==val )
    {
      cout << a[i-1];
      if( val<sub[n][m] ) cout << " ";
      val++;
    }

	return 0;
}
