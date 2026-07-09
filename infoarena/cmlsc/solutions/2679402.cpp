#include <bits/stdc++.h>
#define NMAX 1024
using namespace std;
int longestCS[NMAX+1][NMAX+1], dir[NMAX+1][NMAX+1];
int x[NMAX], y[NMAX];
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
void scrieCale(int m, int n)
{
  if(m==0||n==0)
    return;
  if(dir[m][n]==0)
  {
     scrieCale(m-1, n-1);
     fout<<x[m-1]<<" ";
  }
  else if(dir[m][n]==-1)
    scrieCale(m-1, n);
  else
    scrieCale(m, n-1);
}
int main()
{
    int m, n; fin>>m>>n;
    for(int i=0; i<m; i++)
       fin>>x[i];
    for(int i=0; i<n; i++)
       fin>>y[i];
    for(int i=1; i<=m; i++)
      for(int j=1; j<=n; j++)
      {
         if(x[i-1]==y[j-1])
            longestCS[i][j]=longestCS[i-1][j-1]+1;
         else
         {
            longestCS[i][j]=max(longestCS[i][j-1], longestCS[i-1][j]);
            if(longestCS[i][j-1]>longestCS[i-1][j])
               dir[i][j]=1;
            else
               dir[i][j]=-1;
         }
      }
    fout<<longestCS[m][n]<<"\n";
    scrieCale(m, n);
    fin.close();
    fout.close();
    return 0;
}
