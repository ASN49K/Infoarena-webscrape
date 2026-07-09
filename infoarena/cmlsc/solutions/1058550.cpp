#include<iostream>
#include<fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n,m,a[1025][1025],v[1025],k,x[1025],y[1025];
int main()
{
    f>>n>>m;
    int i,j;
    for(i=1;i<=n;i++)f>>x[i];
    for(i=1;i<=m;i++)f>>y[i];
    for(i=1;i<=n;i++)
       for(j=1;j<=m;j++)
          if(x[i]==y[j])
             a[i][j]=a[i-1][j-1]+1;
          else a[i][j]=max(a[i-1][j],a[i][j-1]);
    g<<a[n][m]<<"\n";
    i=n;j=m;
    while(i!=0&&j!=0)
    {
        if(x[i]==y[j])
           {
               v[++k]=x[i];
               i--;j--;
           }
        else if(a[i][j]==a[i-1][j])i--;
             else j--;
    }
    for(i=k;i>=1;i--)
       g<<v[i]<<" ";
    f.close();
    return 0;
}
