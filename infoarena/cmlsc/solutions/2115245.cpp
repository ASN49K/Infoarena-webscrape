#include<fstream>
#include<algorithm>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int a[1040],b[1040],d[1040][1040],i,j,n,m,sir[1040],nr;
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
            d[i][j]=1+d[i-1][j-1];
        else
            d[i][j]=max(d[i-1][j],d[i][j-1]);
    }
    i=n;
    j=m;
    while(i!=0&&j!=0)
    {
        if(a[i]==b[j])
        {
        sir[++nr]=a[i];
        i--;
        j--;
        }
        else
        {
            if (d[i-1][j] < d[i][j-1])
                j--;
            else
                i--;
        }
    }
    g<<nr<<'\n';
    for(i=nr;i>=1;i--)
        g<<sir[i]<<' ';
    return 0;
}
