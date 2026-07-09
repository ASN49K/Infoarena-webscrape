#include <fstream>
#include <bits/stdc++.h>
using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int a[1025],b[1025],sol[1025],k,n,m;
int mat[1025][1025];

int main()
{
    f>>n>>m;
    for(int i=1;i<=n;i++)
     f>>a[i];
    for(int i=1;i<=m;i++)
     f>>b[i];
    for(int i=1;i<=n;i++)
     for(int j=1;j<=m;j++)
      {if(a[i]==b[j]) mat[i][j]=mat[i-1][j-1]+1;
      else mat[i][j]=max(mat[i][j-1],mat[i-1][j]);
      }
    int i=n,j=m;
    while(i && j)
    {
     if(a[i]==b[j]) sol[++k]=a[i],i--,j--;
     else if(mat[i][j-1]>mat[i-1][j]) j--;
     else i--;
    }
    g<<k<<"\n";
    for(int i=k;i>=1;i--) g<<sol[i]<<" ";
 	return 0;
}
