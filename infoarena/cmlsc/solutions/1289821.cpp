#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;
int n,m,d[260][260],ma[300];
short a[300],b[300],r[300],u;
bool k=1;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int main()
{
    in>>m>>n;
    int i,j;
    for(i=1;i<=m;i++) in>>a[i];
    for(i=1;i<=n;i++) in>>b[i];

    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
    {
        if(a[i]==b[j])
        {
            d[i][j]=1+d[i-1][j-1];
        }
        else
        {
            d[i][j]=max(d[i-1][j],d[i][j-1]);
        }
        if(d[i][j]>ma[i]) ma[i]=d[i][j];
    }
    out<<d[m][n]<<'\n';
    int q=1;
    for(i=1;i<=m;i++)
    {
        if(ma[i]==q) out<<a[i]<<' ',q++;
    }
}
