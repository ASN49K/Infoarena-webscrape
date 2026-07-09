#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

const int MAX=1027;
int a[MAX],b[MAX],mat[MAX][MAX],n,m,c[MAX];

void citire()
{
    fin>>n>>m;
    for(int i=1;i<=n;i++)
        fin>>a[i];
    for(int i=1;i<=m;i++)
        fin>>b[i];
}

int submax()
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if(a[i]==b[j])
                mat[i][j]=1+mat[i-1][j-1];
            else
                mat[i][j]=max(mat[i-1][j],mat[i][j-1]);
        }
    return mat[n][m];
}

void sir()
{
    int x=n,y=m;
    while(mat[x][y]!=0)
    {
        if(a[x]==b[y])
        {
            c[mat[x][y]]=a[x];
            x--;
            y--;
        }
        else
        {
            if(mat[x][y-1]>mat[x-1][y])
                y--;
            else
                x--;
        }
    }
}

int afis()
{
    fout<<mat[n][m]<<'\n';
    for(int i=1;i<=mat[n][m];i++)
        fout<<c[i]<<' ';
}

int main()
{
    citire();
    submax();
    sir();
    afis();
}
