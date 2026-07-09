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

  cin>>a>>b;

  F(i,1,a) cin>>va[i];

  F(i,1,b) cin>>vb[i];

  F(i,1,a)
  F(j,1,b)
  if(va[i]==vb[j]) ab[i][j]=1+ab[i-1][j-1];
  else ab[i][j]=max(ab[i-1][j],ab[i][j-1]);

  for(i=a,j=b;i;)
  if(va[i]==vb[j]) sol[++nr]=va[i], --i, --j;
  else if(ab[i-1][j]<ab[i][j-1]) j--;
  else i--;

  cout<<nr<<"\n";

  for(;nr;--nr)
  cout<<sol[nr]<<" ";
}
