#include <iostream>
#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n,m,i,j,q[1026][1026],a[1026],b[1026],v[10000000];
int main()
{
    f>>m>>n;
    for(i=1;i<=m;i++)
    f>>a[i];

    for(j=1;j<=n;j++)
        f>>b[j];

    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
         {
        if(a[i]==b[j]) q[i][j]=q[i-1][j-1]+1;
           else q[i][j]=max(q[i-1][j],q[i][j-1]);}

    i=m;
    j=n;
    while(i>=1&&j>=1)
    {
        if(a[i]==b[j]){v[q[i][j]]=a[i]; i--;j--;}
        else if(q[i-1][j]>q[i][j-1]) i--;
        else j--;
    }
    g<<q[m][n]<<'\n';
      for(i=1;i<=q[m][n];i++) g<<v[i]<<" ";
    return 0;
}
