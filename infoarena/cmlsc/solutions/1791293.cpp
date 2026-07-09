#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n, m, a[1040], b[1040], i, j, rez[1040], nr, c[1040][1040];
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
            else c[i][j]=c[i-1][j-1];
            c[i][j]=max(max(c[i][j],c[i-1][j]),c[i][j-1]);
        }
    /*for(i=1;i<=n;i++)
        {for(j=1;j<=m;j++)
            cout<<c[i][j]<<' '; cout<<endl;}*/

    int val=c[0][0];
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(c[i-1][j]!=c[i][j] && c[i][j-1]!=c[i][j])
            {
                nr++;
                rez[nr]=a[i];
            }
    fout<<c[n][m]<<'\n';
    for(i=1;i<=c[n][m];i++)
        fout<<rez[i]<<' ';
    return 0;
}
