#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
int M[1025][1025];
int s[1025];
int main()
{
    int a[1025],b[1025],i,j,m,n,mm=0,st=1025,d=1024;
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");
    f>>n>>m;
    for(i=1; i<=n; i++)
        f>>a[i];
    for(i=1; i<=m; i++)
        f>>b[i];
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
            if(a[i]==b[j])
            {
                M[i][j]=M[i-1][j-1]+1;
                if(M[i][j]>mm)
                {
                    mm=M[i][j];
                }
            }
            else
                M[i][j]=max(M[i-1][j],M[i][j-1]);
  i=n;j=m;
  while(mm)
  {
      if(M[i][j-1]<mm)
      {
          s[--st]=b[j];
          mm--;
          j--;
          i--;

      }
      else
        j--;
      if(j==0)
      {
          j++;
          i--;
      }

  }
    for(i=st;i<=d;i++)
        g<<s[i]<<" ";
    f.close();
    g.close();
    return 0;
}
