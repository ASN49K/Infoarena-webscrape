#include <fstream>

using namespace std;
int n,m,i,j,Max,nr,a[1026],b[1026],c[1026][1026],sol[1026];
bool x;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
bool cmp()
{
    g<<c[n][m]<<'\n';
    i=n;
    j=m;
    while(i>=1 && j>=1)
    {
        if(a[i]==b[j])
        {
            sol[++nr]=a[i];
            i--;
            j--;
        }
        else
        {
            if(c[i][j-1]>c[i-1][j])
            {
                j--;
            }
            else
            {
                i--;
            }
        }
    }
    for(i=nr;i>=1;i--)
    {
        g<<sol[i]<<' ';
    }
}
int main()
{
    f>>n>>m;
    for(i=1;i<=n;i++)
    {
        f>>a[i];
    }
    for(i=1;i<=m;i++)
    {
        f>>b[i];
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(a[i]==b[j])c[i][j]=c[i-1][j-1]+1;
            else c[i][j]=max(c[i-1][j],c[i][j-1]);
        }
    }
    x=cmp();
    return 0;
}
