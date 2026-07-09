#include <iostream>
#include <fstream>

using namespace std;
int s[1200][1200];
int a[1200],b[1200];
int n,m;
ofstream fout("cmlsc.out");
void chestie()
{
    for(int i=1; i<=n; i++)
        if(a[i]==b[1] || s[i-1][1]==1) s[i][1]=1;

    for(int i=1; i<=m; i++)
        if(a[1]==b[i]|| s[1][i-1]==1) s[1][i]=1;

    for(int i=2; i<=n; i++)
        for(int j=2; j<=m; j++)
            if(a[i]==b[j]) s[i][j]=1+s[i-1][j-1];
            else  if(s[i-1][j]>s[i][j-1]) s[i][j]=s[i-1][j];
            else s[i][j]=s[i][j-1];
}
void rec(int i,int j)
{
    if(i==0||j==0) return;
    if(s[i][j]==s[i-1][j]) {rec(i-1,j); return;}
    if(s[i][j]==s[i][j-1]) {rec(i,j-1); return;}
    if(s[i][j]==s[i-1][j-1]+1) {rec(i-1,j-1); fout<<a[i]<<" "; return;}
}
int main()
{
ifstream fin("cmlsc.in");
fin>>n>>m;
for(int i=1; i<=n; i++)
    fin>>a[i];
for(int i=1; i<=m; i++)
    fin>>b[i];
chestie();
fout<<s[n][m]<<endl;
rec(n,m);


    return 0;
}
