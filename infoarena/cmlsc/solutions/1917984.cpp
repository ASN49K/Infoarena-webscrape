#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n, m, a[1040], b[1040], i, j, rez[1040], rezl, nr, c[1040][1040];
int main()
{
    fin>>n>>m;
    for(i=1;i<=n;i++)
        fin>>a[i];
    for(i=1;i<=m;i++)
        fin>>b[i];
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {
            if(a[i]==b[j])
                c[i][j]=c[i-1][j-1]+1;
            else c[i][j]=max(c[i-1][j],c[i][j-1]);
        }

    fout<<c[n][m]<<'\n';

    return 0;
}
