#include <bits/stdc++.h>
int n,m,s[1025],t[1025],mat[1025][1025],f[1025],nax;
std::ifstream fin("cmlsc.in");
std::ofstream fout("cmlsc.out");
int main()
{
    fin>>n>>m;
    for(int i=1;i<=n;i++) fin>>s[i];
    for(int i=1;i<=m;i++) fin>>t[i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(s[i]==t[j]) mat[i][j]=1+mat[i-1][j-1];
            else mat[i][j]=std::max(mat[i-1][j],mat[i][j-1]);
    for(int i=n,j=m;i;)
        if(s[i]==t[j]) f[++nax]=s[i],i--,j--;
        else if(mat[i-1][j]<mat[i][j-1]) j--;
        else i--;
    fout<<nax<<'\n';
    for (int i=nax;i>0;i--)
        fout<<f[i]<<' ';
    return 0;
}
