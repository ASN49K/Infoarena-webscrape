#include <fstream>
#include <iostream>
using namespace std;
int c[1024][1024];
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int main()
{
    int i,s[1024],a[1024],b[1024],n,m,j;

    fin>>n>>m;

    for(i=1;i<=n;i++) fin>>a[i];
    for(j=1;j<=m;j++) fin>>b[j];
    fin.close();
    for(i=1;i<=n;i++)
     for(j=1;j<=m;j++)
        if(a[i]==b[j]){ s[i][j]=s[i-1][j-1]+1; fout<<a[i]<<" "; }
else s[i][j]=max(s[i-1][j], s[i][j-1]);
fout<<"\n"<<s[n][m];

return 0;
}
