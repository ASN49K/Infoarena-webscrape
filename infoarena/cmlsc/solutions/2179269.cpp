#include <bits/stdc++.h>
#define F(i,a,b) for(i=a;i<=b;i++)
#define nm 1024
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int a,b,va[nm],vb[nm], ab[nm][nm], sol[nm], nr;
int main()
{
  int i,j;
  fin>>a>>b;
  F(i,1,a) fin>>va[i];
  F(i,1,b) fin>>vb[i];
  F(i,1,a)
  F(j,1,b)
  if(va[i]==vb[j]) ab[i][j]=1+ab[i-1][j-1];
  else ab[i][j]=max(ab[i-1][j],ab[i][j-1]);
  for(i=1,j=1;i;)
  if(va[i]==vb[j]) sol[++nr]=va[i], --i, --j;
  else if(ab[i-1][j]>ab[i][j-1]) i--;
  else j--;
  fout<<nr<<"\n";
  for(;nr;--nr)
  fout<<sol[nr];
}
