#include <fstream>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int main()
{
  int i,j,n,m,a[100],b[100],s[100][100];
  fin>>n>>m;
  for (i=1;i<=n;i++)
  {fout<<"a["<<i<<"]=";
  fin>>a[i];}
  for (i=1;i<=m;i++)
  {fout<<"b["<<i<<"]=";
  fin>>b[i];}

  for (i=1;i<=n;i++)
  for (j=1;j<=m;j++)
  if (a[i]==b[j]) {s[i][j]=s[i-1][j-1]+1;
                   fout<<a[i]<<" ";}
  else s[i][j]=max(s[i-1][j],s[i][j-1]);
  fout<<endl;
  fout<<s[n][m];

  return 0;
}
