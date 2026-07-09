#include <iostream>
#include <fstream>

using namespace std;

int a[1026],b[1026];
int t[1026][1026],ras[1026];

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int main()
{
    int i,j,m,n,lg;

    fin>>n>>m;
    for(i=1; i<=n; i++)
        fin>>a[i];
    for(j=1; j<=m; j++)
        fin>>b[j];
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
            if(a[i]==b[j])
                t[i][j]=t[i-1][j-1]+1;
            else t[i][j]=max(t[i-1][j],t[i][j-1]);

    fout<<t[n][m]<<'\n';
    lg=0;
    while(m && n)
        if(a[n]==b[m])
        {
            ras[lg++]=a[n];
            m--;
            n--;
        }
        else if(t[n-1][m]<t[n][m-1])
            m--;
        else n--;
    for(i=1; i<lg; i++)
        fout<<ras[lg-i]<<" ";
    fout<<'\n';
}
