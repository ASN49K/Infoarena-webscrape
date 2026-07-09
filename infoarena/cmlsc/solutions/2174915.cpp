#include <iostream>
#include <fstream>

#define lim 1025

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int m,n;
int a[lim],b[lim];
int lsmax[lim][lim];

void showpath(int i,int j)
{
    if(lsmax[i][j]==0)
        return;
    if(a[i]==b[j])
    {
        showpath(i-1,j-1);
        fout<<a[i]<<" ";
        return;
    }
    if(lsmax[i-1][j]>lsmax[i][j-1])
    {
        showpath(i-1,j);
        return;
    }
    else
    {
        showpath(i,j-1);
        return;
    }
}

int main()
{
    fin>>m>>n;
    for(int i=1;i<=m;i++)
        fin>>a[i];
    for(int i=1;i<=n;i++)
        fin>>b[i];
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(a[i]==b[j])
                lsmax[i][j]=lsmax[i-1][j-1]+1;
            else
                lsmax[i][j]=max(lsmax[i][j-1],lsmax[i-1][j]);
        }
    }

    fout<<lsmax[m][n]<<"\n";
    showpath(m,n);
    return 0;
}
