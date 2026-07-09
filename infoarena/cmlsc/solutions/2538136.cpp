#include <iostream>
#include <fstream>
using namespace std;
int v[10000],z[10000],i,n,j,m,pas,sol[10000];
int d[10000][10000];
int main()
{
    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");
    fin>>n>>m ;
    for(i=1; i<=n; i++)
        fin>>v[i];

    for(i=1; i<=m; i++)
        fin>>z[i];
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
        {
            if(v[i]==z[j])
                d[i][j]=1+d[i-1][j-1];
            else
                d[i][j]=max(d[i-1][j],d[i][j-1]);
        }


    fout<<d[n][m]<<"\n";


    i = n;
    j = m;
    pas = d[n][m];
    while (pas > 0) {
        if (v[i] == z[j]) {
            sol[pas--] = v[i];
            i--;
            j--;
        } else
            if (d[i-1][j] > d[i][j-1])
                i--;
            else
                j--;

    }
    for(i=1;i<=d[n][m];i++)
        fout<<sol[i]<<' ';


    return 0;
}
