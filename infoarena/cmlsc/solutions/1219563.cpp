#include <iostream>
#include <fstream>
using namespace std;
int m,n,V1[1030],V2[1030],i,j,M[1030][1030];
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int main()
{
    f>>n>>m;
    for (i=1;i<=n;i++)
        f>>V1[i];
    for (i=1;i<=m;i++)
        f>>V2[i];
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++)
        {
            if (V1[i]==V2[j]) M[i][j]=M[i-1][j-1]+1;
            else M[i][j]=max(M[i-1][j],M[i][j-1]);
        }
    g<<M[n][m];
}
