#include <iostream>
#include <fstream>

using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n,m,i,j,x[1500],v[1500],mat[1026][1026];
int main()
{
    f>>n>>m;
    for(i=1;i<=n;i++) f>>v[i];
    for(i=1;i<=m;i++) f>>x[i];
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            mat[i][j]=max(mat[i-1][j-1],max(mat[i][j-1],mat[i-1][j]));
            if(v[i]==x[j]) mat[i][j]++;
        }
    }
    g<<mat[n][m]<<'\n';
    return 0;
}
