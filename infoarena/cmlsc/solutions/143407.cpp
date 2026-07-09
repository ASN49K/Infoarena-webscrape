#include<stdio.h>
#define maxim(a,b) ((a>b)?a:b)
FILE *f,*g;
int n,m,a[200],b[200],d[100][150],sir[200],nr;
int i,j;

int main()
{

f=fopen("cmlsc.in","r");
g=fopen("cmlsc.out","w");
fscanf(f,"%d %d\n",&m,&n);
for(i=1;i<=m;i++)
fscanf(f,"%d",&a[i]);
for(i=1;i<=n;i++)
fscanf(f,"%d",&b[i]);

for(i=1;i<=m;i++)
for(j=1;j<=n;j++)
if(a[i]==b[j])
d[i][j]=1+d[i-1][j-1];
else
d[i][j]=maxim(d[i-1][j],d[i][j-1]);

for(i=m,j=n;i;)
if(a[i]==b[j])
sir[++nr]=a[i],i--,j--;
else if(d[i-1][j]<d[i][j-1])
j--;
else
i--;

fprintf(g,"%d\n",nr);
for(i=nr;i>=1;i--)
fprintf(g,"%d ",sir[i]);

fcloseall();
return 0;
}