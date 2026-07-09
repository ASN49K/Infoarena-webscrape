#include <bits/stdc++.h>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n,m,v[2000],w[2000];
int f[1025][2],k[1025];
void F(int);
int main()
{
    fin>>n>>m;
    int nax=0,inax=-1;
    for(int i=1;i<=n;i++) fin>>v[i];
    for(int i=1;i<=m;i++) fin>>w[i];
    F(n);
    for(int i=1;i<=n;i++)
    {
        if(f[i][0]>nax) nax=f[i][0],inax=i;
    }
    fout<<nax<<'\n';
    if(inax>-1) fout<<v[inax]<<' ';
    for(int i=inax+1;i<=n;i++)
    {
        if(f[i][0]==nax-1) {fout<<v[i]<<' '; nax--;}
    }
    return 0;
}
void F(int x)
{
    bool ok=0,h=0;
    for(int i=m;i>0 && !ok;i--)
    {
        if(v[x]==w[i] && !k[i])
        {
            f[x][1]=i; ok=1; k[i]=1;
            if(x==n) f[x][0]=1;
            for(int j=x+1;j<=n;j++)
            {
                if(f[j][1]>i && f[j][0]>f[x][0]) h=1,f[x][0]=f[j][0]+1;
            }
            if(!h) f[x][0]=1;
        }
    }
    if(x!=1) F(x-1);
}
