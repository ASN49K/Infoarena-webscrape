#include<stdio.h>
#include<algorithm>
using namespace std;
FILE *f=fopen("cmlsc.in","r"),*g=fopen("cmlsc.out","w");
int m,n,a[1025],b[1025],d[1025][1025];
void Citire()
{int i,j;
fscanf(f,"%d %d",&m,&n);
for (i=1;i<=m;i++) fscanf(f,"%d",&a[i]);
for (i=1;i<=n;i++) fscanf(f,"%d",&b[i]);
}
void Dinamic()
{int i,j;
for (i=1;i<=m;i++)
for (j=1;j<=n;j++)
if (a[i]==b[j]) d[i][j]=d[i-1][j-1]+1; else d[i][j]=max(d[i-1][j],d[i][j-1]);
}
void Afisare()
{int i=m,j=n,bst=0,sir[1025];
while((i>0)&&(j>0))
{
if (a[i]==b[j]) {bst++;sir[bst]=a[i];i--;j--;}
else if (d[i-1][j]>d[i][j-1]) i--; else j--;
}
fprintf(g,"%d\n",bst);
for (i=bst;i>=1;i--) fprintf(g,"%d ",sir[i]);
}
int main()
{
Citire();
Dinamic();
Afisare();
return 0;
}
