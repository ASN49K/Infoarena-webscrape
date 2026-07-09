#include<fstream.h>
int x[1025],y[1025],n,m,i,j,k,lcs[100][100],h,d[1025];
int main()
{
  ifstream f("cmlsc.in");
  ofstream g("cmlsc.out");
   f>>n>>m;
  for(i=1;i<=n;i++)
   f>>x[i];
  for(j=1;j<=m;j++)
   f>>y[j];
  for(k=1;k<=n;k++)
   for(h=1;h<=m;h++)
    if(x[k]==y[h])
     lcs[k][h]=1+lcs[k-1][h-1];
   else
    if(lcs[k-1][h]>lcs[k][h-1])
     lcs[k][h]=lcs[k-1][h];
   else
    lcs[k][h]=lcs[k][h-1];
   g<<lcs[n][m]<<"\n";
   for(i=0,k=n,h=m;lcs[k][h];)
    if(x[k]==y[h])
     {
      d[i++]=x[k];
      k--;
      h--;
     }
    else
     if(lcs[k][h]==lcs[k-1][h])
      k--;
     else
      h--;
    for(k=i-1;k>=0;k--)
     g<<d[k]<<" ";
   return 0;
}
