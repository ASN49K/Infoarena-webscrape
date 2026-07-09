#include <fstream>

using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int i,j,n,m,ok,a[1100],v[1100],k,b[1100],mat[1100][1100];
int main()
{
    f>>n>>m;
    for(i=1;i<=n;i++)
        f>>a[i];
    for(i=1;i<=m;i++)
        f>>b[i];
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(a[i]==b[j])
            {
                mat[i][j]=mat[i-1][j-1]+1;
            }
            else
            {
                mat[i][j]=max(mat[i-1][j],mat[i][j-1]);
            }
        }
    }
    /*for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            g<<mat[i][j]<<" ";
        }
        g<<'\n';
    }*/
    i=n;
    j=m;
    g<<mat[i][j]<<'\n';
    while(mat[i][j])
    {
        if(a[i]==b[j])
        {
            v[++k]=a[i];
            i--;
            j--;
        }
        if(mat[i-1][j]==mat[i][j])
            i--;
        if(mat[i][j-1]==mat[i][j])
            j--;
    }
    for(i=k;i>=1;i--)
        g<<v[i]<<" ";
    g<<'\n';
    return 0;
}
