#include <bits/stdc++.h>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int dp[1005][1005];
int ia,ib;
int A[1005],B[1005];
int nA,nB,out;
int Out[1005];

int main()
{
 fin>>nA>>nB;
 for (ia=1;ia<=nA;ia++)
  fin>>A[ia];
 for (ib=1;ib<=nB;ib++)
  fin>>B[ib];
 for (ia=1;ia<=nA;ia++)
  for (ib=1;ib<=nB;ib++)
  {
   if (A[ia]==B[ib])
    dp[ia][ib]=dp[ia-1][ib-1]+1;
   else
    dp[ia][ib]=max(dp[ia-1][ib],dp[ia][ib-1]);
  }
 fout<<dp[nA][nB]<<"\n";
 ia=nA;
 ib=nB;
 while (ia!=0||ib!=0)
 {
  if (A[ia]==B[ib])
  {
   out++;
   Out[out]=A[ia];
   ia--;
   ib--;
  }
  else
  {
   if (dp[ia-1][ib]>=dp[ia][ib-1])
    ia--;
   else
    ib--;
  }
 }
 for (ia=out;ia>0;ia--)
  fout<<Out[ia]<<" ";
 return 0;
}
