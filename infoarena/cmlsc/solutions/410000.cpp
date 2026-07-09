#include<stdio.h>
#include<iostream.h>
#define lmax 1024

int a[lmax],b[lmax],n,m,p,d[lmax];
int c[lmax][lmax];

void rez()
{int i ,j,s;
for(i=0;i<n;i++)
for(j=0;j<m;j++)
{
	if(a[i]==b[j])c[i][j]=1+c[i-1][j-1];

else
	if(c[i-1][j]>c[i][j-1])c[i][j]=c[i-1][j];
else
	c[i][j]=c[i][j-1];
}}

void afisare(int i,int j)
{if(i>=0&&j>=0)
{if(a[i]==b[j])
{
afisare(i-1,j-1);
d[++p]=a[i];
}
else
if(c[i-1][j]>c[i][j-1])afisare(i-1,j);
else
	afisare(i,j-1);}
}


int main()
{freopen("cmlsc.in","r",stdin);
freopen("cmlsc.out","w",stdout);
scanf("%d %d",&n,&m);
int i;
for(i=0;i<n;i++)
	scanf("%d ",&a[i]);
for(i=0;i<m;i++)
	scanf("%d ",&b[i]);
rez();
afisare(n-1,m-1);
printf("%d\n",p);
for(i=1;i<=p;i++)
printf("%d ",d[i]);	
return 0;}
