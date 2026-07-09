#include<bits/stdc++.h>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
long long DP[1030][1030], A[1030],B[1030],
cop[1030],m,n;
void CMLSC()
{
  long long i, j;
  for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
      if(A[i]==B[j])
	DP[i][j]=DP[i-1][j-1]+1;
      else
      if(DP[i-1][j]>DP[i][j-1])
	     DP[i][j]=DP[i-1][j];
      else
	     DP[i][j]=DP[i][j-1];
}
int main()
{
  long i, j;
  fin>>n>>m;
  for(i=1;i<=n;i++)
    fin>>A[i];
  for(j=1;j<=m;j++)
    fin>>B[j];
  CMLSC();
  fout<<DP[n][m]<<'\n';
  int l=DP[n][m];
  i=n;
  j=m;
  for(l;l;)
    {
    if(A[i]==B[j]){
      cop[l]= A[i];
      l--;
      i--;
      j--;
    }
    else if(DP[i-1][j]>DP[i][j-1])
    i--;
    else
    j--;
  }
  for(i=1;i<=DP[n][m];i++)
  fout<<cop[i]<<' ';
  fout<<'\n';
  return 0;
}
