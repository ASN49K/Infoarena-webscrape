#include <bits/stdc++.h>
#define NMAX 1050
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int dp[NMAX][NMAX];
int bc[NMAX][NMAX];
int a[NMAX];
int b[NMAX];
int n,m;
vector<int>sol;
void citire();
void dp1();
void rec();
int main()
{citire();
 dp1();
 fout<<dp[n][m]<<'\n';
 rec();
 for(int i=sol.size()-1;i>=0;i--)
      fout<<sol[i]<<" ";
     return 0;
}
void citire()
{int i;
  fin>>n>>m;
  for(i=1;i<=n;i++)
         fin>>a[i];

  for(i=1;i<=m;i++)
         fin>>b[i];
}
void dp1()
{
  int i,j;
  for(i=1;i<=n;i++)
     for(j=1;j<=m;j++)
         if(a[i]==b[j])
        {
         dp[i][j]=dp[i-1][j-1]+1;
         bc[i][j]=-1;

        }
        else
         {
          if(dp[i-1][j]>dp[i][j-1])
            {
             bc[i][j]=1;
             dp[i][j]=dp[i-1][j];
            }
            else
            {
             bc[i][j]=2;
             dp[i][j]=dp[i][j-1];
            }
         }

}
void rec()
{
 int i,j;
 i=n;j=m;
 while(bc[i][j])
        {
         if(bc[i][j]==-1)
            {sol.push_back( a[i] );
            i--;j--;}
            else
            {
             if(bc[i][j]==1)
                    i--;
             else
                j--;
            }

        }
}
