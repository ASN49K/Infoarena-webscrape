#include <iostream>
#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n,m,i,j,a[1050],b[1050],c[1050],d[1050][1050];
int main()
{
    f>>n>>m;
    for(i=1;i<=n;i++)
        f>>a[i];
    for(i=1;i<=m;i++)
        f>>b[i];
    for(i=1;i<=n;i++)
     for(j=1;j<=m;j++)
      if(a[i]==b[j])
        d[i][j]=d[i-1][j-1]+1;
        else
            d[i][j]=max(d[i-1][j],d[i][j-1]);

    i=n;
    j=m;
    c[0]=0;
    while(i)
        if(a[i]==b[j])
    {
        c[0]++;
        c[c[0]]=a[i];
        i--;
        j--;
    }
    else
        if(d[i-1][j]<d[i][j-1])
            j--;
    else
        i--;
    g<<c[0]<<"\n";
    for(i=c[0];i>=1;i--)
        g<<c[i]<<" ";

    return 0;
}
