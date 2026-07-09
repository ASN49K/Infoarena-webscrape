#include<fstream.h>
#include<stdio.h>
#include<iostream.h>
#define MAX 1024
  ifstream f("cmlsc.in");
  ofstream g("cmlsc.out");
 int d[MAX],lcs[MAX][MAX],x[MAX],y[MAX],n,m,k,h,i;
 int main() 
 {  f>>n>>m; 
 for(k=1;k<=n;k++) f>>x[k];
    for(h=1;h<=m;h++) f>>y[h];
    for(k=1;k<=n;k++)
    for(h=1;h<=m;h++)
  if(x[k]==y[h])
  lcs[k][h]=1+lcs[k-1][h-1];
     else 
  if(lcs[k-1][h]>lcs[k][h-1])
   lcs[k][h]=lcs[k-1][h];
      else 
    lcs[k][h]=lcs[k][h-1];
    for(i=0,k=n,h=m;lcs[k][h];)
       if(x[k]==y[h])
      {  d[i++]=x[k];k--;h--; }      
         else 
      if(lcs[k][h]==lcs[k-1][h])
      k--;
         else 
      h--;
      g<<i<<endl;
      for(k=i-1;k>=0;k--) g<<d[k]<<' ';
      return 0;    
    }
