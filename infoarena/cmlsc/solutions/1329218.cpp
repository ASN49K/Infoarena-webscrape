#include <fstream>

using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int a[1025],b[1025],mat[1025][1025],i,j,n,m,v[1025],k;
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
            if(a[i]==b[j])
            {
                mat[i][j]=mat[i-1][j-1]+1;
            }
            else
            {
                mat[i][j]=max(mat[i][j-1],mat[i-1][j]);
            }
        }
    }
    g<<mat[n][m]<<'\n';
    i=n;
    j=m;
    while(i!=0 && m!=0)
    {
        if(a[i]==b[j])
        {
           v[++k]=a[i];
            i--;
            j--;
        }
        else
        {
            if(mat[i][j]==mat[i-1][j])
            {
                i--;
            }
            else
            {
                j--;
            }
        }
    }
    for(i=k;i>=1;i--)
    {
        g<<v[i]<<" ";
    }
    return 0;
}
