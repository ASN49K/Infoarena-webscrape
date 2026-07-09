#include <iostream>
#include <fstream>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n,m,i,j,a[10026],b[10026],c[10026][10026],d[10026],cnt=0,poz=0;

int main()
{
    fin>>n>>m;
    for(i=1; i<=n; i++)
        fin>>a[i];
    for(i=1; i<=m; i++)
        fin>>b[i];

    for (i=1; i<=m; i++)
    {
        for (j=1; j<=n; j++)
        {
            c[i][j]=max(c[i-1][j],c[i][j-1]);
            if (a[j]==b[i])
            {
                c[i][j]++;
                if(a[j]!=d[poz])
                {
                    poz++;
                    d[poz]=a[j];
                }
            }
        }
    }
    fout<<c[m][n]<<"\n";
    for (i=1; i<=poz; i++)
        fout<<d[i]<<" ";
}
