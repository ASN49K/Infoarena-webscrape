#include <fstream>
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int a[1024], b[1024], n, m;
int dp[1024][1024],k;

int main()
{
     in >> n >> m;
     for(int i=1; i<=n; i++) in >> a[i];
     for(int j=1; j<=m; j++) in >> b[j];

     for(int i=n; i>0; i--)
     for(int j=m; j>0; j--)
     {
        if( a[i] == b[j] ) dp[i][j] = 1 + dp[i-1][j-1], k++;
        if( a[i]!= b[j]) dp[i][j] = max( dp[i-1][j], dp[i][j-1] );
     }

     out << k << '\n';
     for(int i=1; i<=n; i++)
          for(int j=1; j<=m; j++)
          if( dp[i][j] ) out << a[i] << ' ';
    return 0;
}
