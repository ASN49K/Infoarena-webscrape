#include <iostream>
#include <fstream>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int c[1025][1025],a[1025],b[1025],v[1025];
int main()
{
    int n,i,m,j;
    fin>>n>>m;
     for(i=1;i<=n;i++)
          fin>>a[i];
     for(j=1;j<=m;j++)
          fin>>b[j];
     for(i=1;i<=n;i++)
          for(j=1;j<=m;j++)
               if(a[i]==b[j])
                    c[i][j]=c[i-1][j-1]+1;
               else
                    c[i][j]=max(c[i-1][j],c[i][j-1]);
     int k=0;
     fout<<c[n][m]<<'\n';
     while(n)
     {
          if(a[n]==b[m])
          {
               v[++k]=a[n];
               n--;
               m--;

          }
          else
          {
               if(c[n][m-1]>c[n-1][m])
                    m--;
               else
                    n--;
          }
     }
     for(i=k;i>=1;i--)
          fout<<v[i]<<" ";

    return 0;
}
