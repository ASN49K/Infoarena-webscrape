#include <iostream>
#include <fstream>
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int main()
{
int n, m, i, j, a[100], b[100], s[100][100];
fin>>n>>m;
for(i=1; i<=n; i++)
fin>>a[i];
for(j=1; j<=m; j++)
fin>>b[j];
for(i=1; i<=n; i++)
for(j=1; j<=m; j++)
if(a[i]==b[j])
{ s[i][j]=s[i-1][j-1]+1; fout<<a[i]<<" "; }
else s[i][j]=max(s[i-1][j], s[i][j-1]);
fout<<"\n"<<s[n][m];
return 0;
}
