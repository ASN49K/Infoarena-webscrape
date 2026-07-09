#include <stdio.h>
#define NMAX 1024

int n,m;
int a[NMAX],b[NMAX];
int c[NMAX][NMAX];
int sir[NMAX];
int lungime,i,j;

int maxim(int a,int b)
{
if (a>b) return a;
    else return b;
}

int main()
{

freopen("cmlsc.in","rt",stdin);
freopen("cmlsc.out","wt",stdout);
scanf("%d %d", &n, &m);
for (i=1;i<=n;i++)
    scanf("%d", &a[i]);
for (j=1;j<=n;j++)
    scanf("%d", &b[j]);

for (i=1;i<=n;i++)
    for (j=1;j<=m;j++)
	if (a[i]==b[j])
	   c[i][j]=c[i-1][j-1]+1;
	   else c[i][j]=maxim(c[i-1][j],c[i][j-1]);

for (i=n,j=m;i,j;)
    if (a[i]==b[j])
       {
	sir[++lungime]=a[i];
	--i;
	--j;
	}
	else if (c[i-1][j]>c[i][j-1]) --i;
		       else --j;

printf("%d\n", lungime);
for (i=lungime;i>=1;i--)
    printf("%d ",sir[i]);
return 0;
}