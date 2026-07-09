#include<bits/stdc++.h>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n,m,x[1025],y[1025],lcs[1025][1025];
int main()
{
    fin>>n>>m;
    for(int i=1;i<=n;i++) fin>>x[i];
    for(int j=1;j<=m;j++) fin>>y[j];
    for(int k=1;k<=n;k++)
    {
        for(int h=1;h<=m;h++)
            {if(x[k]==y[h]) lcs[k][h]=1+lcs[k-1][h-1];
            else lcs[k][h]=max(lcs[k-1][h],lcs[k][h-1]);}
    }
    fout<<lcs[n][m]<<'\n';
    int d[1025],i,k,h;
    for(i=0,k=n,h=m;lcs[k][h];)
    {
        if(x[k]==y[h])
        {
            d[i++]=x[k];
            k--;
            h--;
        }
        else{
            if(lcs[k][h]==lcs[k-1][h]) k--;
            else h--;
        }
    }
    for(k=i-1;k>=0;k--)fout<<d[k]<<' ';
    fin.close();
    fout.close();
    return 0;
}
