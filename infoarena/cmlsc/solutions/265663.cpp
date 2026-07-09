#include <stdio.h>
#include <stdlib.h>

int n,m,i,j,k;
unsigned char x[1025],y[1025],c[1025][1025];

int max(int a, int b)
{
 if (a>b) return a;
  else return b;
}

int cmlsc(int a, int b)
{
 if (a<=0 || b<=0)
	return 0;
 if (x[a]==y[b])
	{
	 k++;
	 if (k<c[m][n]) cmlsc(a-1,b-1);
	 printf("%d ", x[a]);
	}
  else
   if (c[a][b-1]==c[a-1][b])
	{
	 if (x[a-1]>y[b-1])
		cmlsc(a-1,b);
	   else
		cmlsc(a,b-1);
	}
    else
	if (c[a][b-1]>c[a-1][b])
		cmlsc(a,b-1);
	  else
		cmlsc(a-1,b);
}

int main()
{
 freopen("cmlsc.in","r",stdin);
 freopen("cmlsc.out","w",stdout);

 scanf("%d %d", &m, &n);
 for (i=1;i<=m;i++)
	scanf("%d", &x[i]);
 for (i=1;i<=n;i++)
	scanf("%d", &y[i]);
 for (i=1;i<=m;i++)
 for (j=1;j<=n;j++)
	if (x[i]==y[j])
		c[i][j]=c[i-1][j-1]+1;
	 else
		c[i][j]=max(c[i-1][j],c[i][j-1]);
 printf("%d\n", c[m][n]);
 cmlsc(m,n);

 return 0;
}