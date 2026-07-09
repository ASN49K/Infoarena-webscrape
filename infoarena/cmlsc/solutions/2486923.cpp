#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int n,a[100],b[100],v[100][100],m;
void recons(int i,int j)
{
    if(v[i][j]!=0)
    if(v[i][j]==v[i-1][j-1]+1)
    {
        recons(i-1,j-1);
        g<<a[i]<<" ";
    }
    else if(v[i][j]==v[i-1][j])
        recons(i-1,j);
    else if(v[i][j]==v[i][j-1])
        recons(i,j-1);
}
int main()
{
    f>>n>>m;
    for(int i=1;i<=n;i++)
        f>>a[i];
    for(int i=1;i<=m;i++)
        f>>b[i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
    {
        if(a[i]==b[j])
            v[i][j]=1+v[i-1][j-1];
        else
            v[i][j]=max(v[i][j-1],v[i-1][j]);
    }
    g<<v[n][m]<<'\n';
    recons(n,m);
    return 0;
}
