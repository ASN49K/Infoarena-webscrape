#include <bits/stdc++.h>
#define mod 777013
using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int n,m,ma[1030][1030],v1[1030],v2[1030],sir,sol[1030];

int main()
{
    f>>n>>m;
    for(int i=1;i<=n;++i)f>>v1[i];
    for(int j=1;j<=m;++j)f>>v2[j];
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
    {
        if(v1[i]==v2[j])ma[i][j]=ma[i-1][j-1]+1;
        else ma[i][j]=max(ma[i-1][j],ma[i][j-1]);

    }
    int i=n,j=m;
    while(i&&j)
    {
        if(v1[i]==v2[j])i--,j--,sol[++sir]=v1[i+1];
        if(ma[i-1][j]<ma[i][j-1])j--;
        else i--;
    }
    g<<ma[n][m]<<'\n';
    for(int k=sir;k>=1;--k)g<<sol[k]<<" ";
//    for(int i=1;i<=n;++i){
//        for(int j=1;j<=m;++j)
//        g<<ma[i][j]<<" ";g<<'\n';
//    }
    return 0;
}
