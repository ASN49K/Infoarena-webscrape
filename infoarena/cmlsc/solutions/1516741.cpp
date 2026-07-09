#include <fstream>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int main()
{
  int i,j,n,m,a[100],b[100],s[100][100];
  fin>>n>>m;
  for (i=1;i<=m;i++)
  {fout<<"a["<<i<<"]=";
  fin>>a[i];}
  for (i=1;i<=n;i++)
  {fout<<"b["<<i<<"]=";
  fin>>b[i];}

  for (i=1;i<=m;i++)
  for (j=1;j<=n;j++)
  fout<<endl;
  fout<<s[m][n];
  if (a[i]==b[j]) {s[i][j]=s[i-1][j-1]+1;
                   fout<<a[i]<<" ";}
  else s[i][j]=max(s[i-1][j],s[i][j-1]);


  return 0;
}
