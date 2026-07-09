#include <iostream>
#include <stdio.h>

using namespace std;

FILE *f=fopen("cmlsc.in","r");
FILE *g=fopen("cmlsc.out","w");

int i,j,n,m,mx,a[1025],b[1025],v[1025][1025];

int main()
{
    fscanf(f,"%d%d",&n,&m);
    mx=0;
    v[0][0]=0;
    for(i=1;i<=n;i++) fscanf(f,"%d",&a[i]);
    for(i=1;i<=m;i++) fscanf(f,"%d",&b[i]);
    for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
    {
        if(i==j) v[i][j]=v[i-1][j-1];
        else if(v[i-1][j]>v[i][j-1]) v[i][j]=v[i-1][j];
        else v[i][j]=v[i][j-1];
      if(a[i]==b[j]) v[i][j]++;
      if(v[i][j]>mx) mx=v[i][j];
    }
    for(i=1;i<=n;i++)
    {
      for(j=1;j<=m;j++)
      fprintf(g,"%d",v[i][j]);
      fprintf(g,"\n");
    }


    fprintf(g,"%d",mx);


    fclose(g);
    return 0;
}
