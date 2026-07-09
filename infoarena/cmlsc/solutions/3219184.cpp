
#include <bits/stdc++.h>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int i,j,n,m,a[200005],b[200005],mat[1001][1001];
int v[200005],numara=0;
int main()
{
   fin>>n>>m;
   for(i=1;i<=n;++i)
   {
       fin>>a[i];
   }
   for(j=1;j<=m;++j)
   {
       fin>>b[j];
   }
   for(i=1;i<=n;++i)
   {
       for(j=1;j<=m;++j)
       {
           if(a[i]==b[j])
           {
               mat[i][j]=mat[i-1][j-1]+1;
           }
           else{
               mat[i][j]=max(mat[i-1][j],mat[i][j-1]);
           }
       }
   }
   fout<<mat[n][m]<<endl;
   i=n;
   j=m;
   while(i>=1 && j>=1)
   {
       if(a[i]==b[j])
       {
           v[numara++]=a[i];
           i--;
           j--;
       } 
       else if(mat[i-1][j]<mat[i][j-1])
       {
           j--;
       }
       else{
           i--;
       }
   }
   for(i=numara-1;i>=0;--i)
   {
       fout<<v[i]<<" ";
   }

    return 0;
}