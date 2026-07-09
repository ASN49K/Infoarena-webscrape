#include <iostream>
#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int a[1100],b[1100],m,n,i,j,d[1100][1100],sol[1100],k;
int main()
{
    f>>m>>n;
    for(i=1;i<=m;i++)
        f>>a[i];
    for(i=1;i<=n;i++)
        f>>b[i];
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
            if(a[i]==b[j])
                d[i][j]=1+d[i-1][j-1];
            else
                if(d[i-1][j]>d[i][j-1])
                    d[i][j]=d[i-1][j];
                else
                    d[i][j]=d[i][j-1];
    i=m;
    j=n;
    while(i)
    {
        if(a[i]==b[j])
        {
            sol[++k]=a[i];
            i--;
            j--;
        }
        else
            if(d[i-1][j]<d[i][j-1])
                j--;
            else
                i--;
    }
    g<<k<<'\n';
    for(i=k;i>=1;i--)
        g<<sol[i]<<' ';
    return 0;
}
