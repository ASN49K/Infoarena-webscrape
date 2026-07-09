#include <bits/stdc++.h>
using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int n,m,a[1028],b[1028],harta[1028][1028];

void solve(int i,int j)
{
    if(harta[i][j]==0) return;
    else if(harta[i][j]>harta[i-1][j] && harta[i][j]>harta[i][j-1] && harta[i][j]==harta[i-1][j-1]+1 )solve(i-1,j-1),out<<a[i]<<' ';
    else {
        if(harta[i][j-1]>harta[i-1][j])solve(i,j-1);
        else solve(i-1,j);
    }
}

int main()
{
in>>n>>m;
for(int i=1;i<=n;i++)in>>a[i];
for(int i=1;i<=m;i++)in>>b[i];

for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
        if(a[i]==b[j])harta[i][j]=harta[i-1][j-1]+1;
        else harta[i][j]=max(harta[i-1][j],harta[i][j-1]);
    }
}

out<<harta[n][m]<<'\n';
solve(n,m);
    return 0;
}
