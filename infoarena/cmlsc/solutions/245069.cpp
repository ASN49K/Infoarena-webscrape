#include <iostream>
#include <fstream>
using namespace std;
#define NMAX 1024
#define MAX(a,b) ((a>b)?a:b)

ifstream f ("cmlsc.in");
ofstream g ("cmlsc.out");

int a[NMAX],k, n,m, b[NMAX], c[NMAX][NMAX], v[NMAX];

int main()
{
    int i,j;
    f>>n>>m;
    for(i=1;i<=n;i++) f>>a[i];
    for(i=1;i<=m;i++) f>>b[i];
    for(i=1;i<=n;i++)
       for(j=1;j<=m;j++)
          if (a[i]==b[j]) c[i][j]=c[i-1][j-1]+1;
          else
            c[i][j]=MAX(c[i-1][j], c[i][j-1]);
    i=n;j=m;
    k=c[n][m];
    while(i)
      if(a[i]==b[j])
      {
        v[k]=a[i];
        k--;i--; j--;
      }
      else if(c[i][j]==c[i][j-1]) j--;
           else i--;
    g<<c[n][m]<<"\n";      
    for(i=1;i<=c[n][m];i++) g<<v[i]<<" ";
    f.close();
    g.close();
    return 0;
}
