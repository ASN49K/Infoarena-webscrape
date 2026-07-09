#include <iostream>
#include <fstream>

using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n,m,i,j,x[1500],v[1500],mat[1026][1026],val;

void refac(int i, int j)
{
    if(i==0 || j==0)
    {
        return;
    }
    else if(v[i]==x[j])
    {
        refac(i-1,j-1);
        g<<v[i]<<' ';
    }
    else
    {
        if(mat[i-1][j]>mat[i][j-1]) refac(i-1,j);
        else refac(i,j-1);
    }
}

int main()
{
    f>>n>>m;
    for(i=1;i<=n;i++) f>>v[i];
    for(i=1;i<=m;i++) f>>x[i];
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(v[i]==x[j]) val=1;
            else val=0;
            mat[i][j]=max(mat[i-1][j-1]+val,max(mat[i][j-1],mat[i-1][j]));
        }
    }
    g<<mat[n][m]<<'\n';
    refac(n,m);
    return 0;
}
