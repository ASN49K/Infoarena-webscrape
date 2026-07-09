#include <iostream>
#include <fstream>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n,m,i,j,a[1026],b[1026],c[1026][1026],d[1026],cnt=0,poz=1;

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
                c[i][j]=c[i-1][j]+1;
        }
    }
    fout<<c[m][n]<<"\n";
    i=m;
    j=n;
    while(i && j)
    {
        if(a[i]==b[j]){
            d[poz]=a[i];
            --i;--j;
            poz++;
        }
        else if(c[i][j]==c[i][j-1])
            j--;
        else i--;
    }
    for(i=poz;i>=1;i--)
        cout<<d[i];
}
