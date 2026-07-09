#include <fstream>
#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n,m;
int nrc;
int ma[1030][1030];
int v1[2000];
int v2[2000];

int main()
{
   fin>>n>>m;
   for(int i=1;i<=n;i++) {

      fin>>v1[i];

   }
   for(int j=1;j<=m;j++) {

      fin>>v2[j];

   }

   for(int i=1;i<=n;i++)
      for(int j=1;j<=m;j++) {

      if(v1[i]==v2[j]) ma[i][j]=1+ma[i-1][j-1];
      else ma[i][j] = max(ma[i-1][j],ma[i][j-1]);

      }
   int k=1;
   fout<<ma[n][m]<<'\n';
   for(int i=1;i<=n;i++)
      for(int j=1;j<=m;j++)
   if(ma[i][j]==k) {fout<<v1[i]<<" ";k++;}


}

