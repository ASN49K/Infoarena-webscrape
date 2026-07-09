#include<iostream>
using namespace std;
#include<stdio.h>
FILE *f,*g;
int a[100],b[100],n,m,i,j,c[100][100],d[100],k;
int main()
{
    f=fopen("cmlsc.in","r");
    g=fopen("cmlsc.out","w");
    fscanf(f,"%d%d\n",&n,&m);
    for(i=1;i<=n;i++)
        fscanf(f,"%d",&a[i]);
        for(j=1;j<=m;j++)
            fscanf(f,"%d",&b[j]);
        for(i=1;i<=n;i++)
          for(j=1;j<=m;j++)
          if(a[i]==b[j])
          c[i][j]=c[i-1][j-1]+1;
        else
            if(c[i][j-1]>c[i-1][j])
            c[i][j]=c[i][j-1];
        else
            c[i][j]=c[i-1][j];
     fprintf(g,"%d\n",c[n][m]);
while(i>0 && j>0)
if(a[i]==b[j]){d[k]=a[i];k++;
i--;j--;}
 else if (c[i-1][j]<c[i][j-1])
            --j;
        else
            --i;
for(i=k-1;i>=1;i--)
fprintf(g,"%d ",d[i]);}
