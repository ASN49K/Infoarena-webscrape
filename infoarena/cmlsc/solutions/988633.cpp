#include <fstream>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int i,j,n,m,k,a[1100],b[1100],mat[1100][1100];
void afisare()
{
    int ii,jj;
    for(ii=1;ii<=n;ii++)
    {
        for(jj=1;jj<=m;jj++)
        {
            g<<mat[ii][jj]<<" ";
        }
        g<<'\n';
    }
}
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
                mat[i][j]=mat[i-1][j-1]+1;
            else
                mat[i][j]=max(mat[i-1][j],mat[i][j-1]);
        }
    }
    k=mat[n][m];
    g<<mat[n][m]<<'\n';
    i=n;
    j=m;
    while(k!=0)
    {
        while(mat[i][j-1]==k)
            j--;
        while(mat[i-1][j]==k)
            i--;
        g<<a[i]<<" ";
        k--;
    }
    g<<'\n';
    return 0;
}
