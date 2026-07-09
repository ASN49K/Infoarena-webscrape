#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int main()
{
    int a[1025],b[1025],m,n,ct=0,i,j,x=0,c[256]={0};
    fin>>m>>n;
    for (i=1;i<=m;i++)
        fin>>a[i];
    for (i=1;i<=n;i++)
        fin>>b[i];
    for(i=1;i<=m;i++)
        for (j=1;j<=n;j++)
        {
            if (a[i]==b[j] && c[a[i]]==0)
            {
                ct++;
                c[a[i]]=1;
            }
            if (a[i]==b[j] && b[j]>x)
                x=b[j];
        }
    fout<<ct<<" ";
    for (i=0;i<=x;i++)
        if (c[i]==1)
            fout<<i<<" ";
    return 0;
}
