#include <iostream>
#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int mat[1024][1024], v1[1024], v2[1024], i,j, n, m,sir[1024],k;
int main()
{
    f>>n>>m;
    for(i=1;i<=n;i++)
        f>>v1[i];
    for(j=1;j<=m;j++)
        f>>v2[j];
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {
            if(v1[i]==v2[j])
                mat[i][j]=mat[i-1][j-1]+1;
            else
                mat[i][j]=max(mat[i-1][j],mat[i][j-1]);
        }
    g<<mat[n][m]<<'\n';
    for (i=n,j=m; i; )
        if (v1[i]==v2[j])
            sir[++k] = v1[i], --i, --j;
        else if (mat[i-1][j]<mat[i][j-1])
            --j;
        else
            --i;
    for(i=k;i>0;i--)
        g<<sir[i]<<" ";
    return 0;
}
