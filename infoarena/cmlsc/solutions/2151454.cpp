#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int main()
{
    int a[1024],b[1024],m,n,ct=0,i,j,x,c[256]={0};
    fin>>m>>n;
    for (i=1;i<=m;i++)
        fin>>a[i];
    for (i=1;i<=n;i++)
        fin>>b[i];
    for(i=1;i<=m;i++)
        for (j=1;j<=n;j++)
            if (a[i]==b[j])
            {
                ct++;
                c[a[i]]++;
                x=b[j];
            }
    fout<<ct<<"\n";
    for (i=0;i<=x;i++)
        if (c[i]!=0)
            fout<<i<<" ";
    return 0;
}
