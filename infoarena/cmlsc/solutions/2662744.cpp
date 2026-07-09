#include<bits/stdc++.h>
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
short DP[1030][1030], A[1030],B[1030],
cop[1030],m,n;
void CMLSC(){
  int i, j;
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
int main(){
  int i, j;
  in>>n>>m;
  for(i=1;i<=n;i++)
    in>>A[i];
  for(j=1;j<=m;j++)
    in>>B[j];
  CMLSC();
  out<<DP[n][m]<<'\n';
  int l=DP[n][m];
  i=n;
  j=m;
  for(l;l;){
    if(A[i]==B[j]){
      cop[l]= A[i];
      l--;
      i--;
      j--;
    }
    else if(DP[i-1][j]>DP[i][j-1])  i--;
      else j--;
  }
  for(i=1;i<=DP[n][m];i++)
    out<<cop[i]<<' ';
  out<<'\n';
  return 0;
}
