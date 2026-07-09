#include <bits/stdc++.h>
#define NMAX 1024
using namespace std;
int longestCS[NMAX+1][NMAX+1];
int x[NMAX], y[NMAX];
int cale[2*NMAX]
int index=0;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
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
         {
            longestCS[i][j]=longestCS[i-1][j-1]+1;
            cale[index]=x[i-1];
            index++;
         }
         else
            longestCS[i][j]=max(longestCS[i][j-1], longestCS[i-1][j]);
      }
    fout<<longestCS[m][n]<<'\n';
    for(int i=0; i<index; i++)
      fout<<cale[i]<<" ";
    return 0;
}
