#include <iostream>
#include<fstream>
using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int  a[1025], b[1025],n,m,i,j,mat[1025][1025],maxx,cmax;
int main()
{
    f>>n>>m;
    for(i=1;i<=n;++i) f>>a[i];
    for(i=1;i<=m;++i) f>>b[i];
    for(i=1;i<=n;i++)
        for(j=1;j<=m;++j)
            {if(a[i]==b[j])
                mat[i][j]=max(max(mat[i-1][j],mat[i][j-1]),mat[i-1][j-1])+1;
            else mat[i][j]=max(max(mat[i-1][j],mat[i][j-1]),mat[i-1][j-1]);
            if(maxx<mat[i][j]) maxx=mat[i][j];
            }
    g<<maxx<<'\n';
    i=m; cmax=maxx;
    while(maxx>=1)
    {
        while(mat[n][i]==maxx)  i--;
          a[maxx]=b[i+1];
          maxx--;
          n--;
    }
    for(i=1;i<=cmax;++i) g<<a[i]<<" ";
    f.close();
    g.close();
    return 0;
}
