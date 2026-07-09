#include <iostream>
#include <fstream>

using namespace std;

int a[1208],b[1208],i,j,n,m,k,d[1208][1208],sir[1208];
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int main()
{
    f>>n>>m;
    for(i=1;i<=n;i++)
        f>>a[i];
    for(i=1;i<=m;i++)
        f>>b[i];
    for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
    {
        if(a[i]==b[j])
            d[i][j]=d[i-1][j-1]+1;
        else
            d[i][j]=max(d[i-1][j],d[i][j-1]);
    }
    for(i=n,j=m;i;)
    {
        if(a[i]==b[j])
        {
            k++;
            sir[k]=a[i];
            i--;
            j--;
        }
        else
        {
            if(d[i-1][j]<d[i][j-1])
                j--;
            else
                i--;
        }
    }
    g<<d[n][m]<<"\n";
    for(i=k;i>=1;i--)
        g<<sir[i]<<' ';

}
