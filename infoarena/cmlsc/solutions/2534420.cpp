#include <bits/stdc++.h>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n,m,i,j,a[1001],b[1001],c[1001][1001],d[101],cnt=0,poz=0;

int main()
{
    fin>>n;
    for(i=1; i<=n; i++)
        fin>>a[i];
    fin>>m;
    for(i=1; i<=m; i++)
        fin>>b[i];

    for (i=1; i<=m; i++)
    {
        for (j=1; j<=n; j++)
        {
            c[i][j]=max(c[i-1][j],c[i][j-1]);
            if (a[j]==b[i]){
                c[i][j]++;
                poz++;
                d[poz]=a[j];
            }
        }
    }
    fout<<c[m][n]<<"\n";
    for (i=1; i<=poz; i++)
        fout<<d[i]<<" ";
}
