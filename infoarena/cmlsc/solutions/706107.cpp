#include <iostream>
#include <fstream>
#define nmax 1030
using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int a[nmax], b[nmax], c[nmax][nmax], n, m, sol[nmax], k=0;

int main()
{
    in>>n>>m;

    for (int i=1; i<=n; ++i)
     in>>a[i];

    for (int i=1; i<=m; ++i)
     in>>b[i];

    for (int i=1; i<=n; ++i)
     for (int j=1; j<=m; ++j)
      if ( a[i] == b[j] ) c[i][j] = 1 + c[i-1][j-1];
       else c[i][j] = max( c[i-1][j], c[i][j-1] );

    int i=n, j=m;

    while ( i > 0 && j > 0 )
     {
         if (a[i] == b[j]) sol[++k] = a[i], --i, --j;
          else
           if ( c[i-1][j] < c[i][j-1] ) --j;
            else --i;
     }

     out<<k<<'\n';

     for (int i=k; i>=1; --i)
      out<<sol[i]<<" ";


}
