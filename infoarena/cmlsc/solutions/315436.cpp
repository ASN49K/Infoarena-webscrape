#include<stdio.h>
int c[1027][1027];
int x[1027],y[1027],sol[1027];
max (int x,int y)
{ if (x>=y) return x;
  return y;
}
int main()
{freopen ("cmlsc.in","r",stdin);
 freopen ("cmlsc.out","w",stdout);
 int n,m,i,j,f,f1;
 scanf ("%d%d",&n,&m);
 for (i=1;i<=n;i++)
    scanf ("%d",&x[i]);
 for (i=1;i<=m;i++)
    scanf ("%d",&y[i]);
 for (i=1;i<=n;i++)
    for (j=1;j<=m;j++)
      {if (x[i]==y[j]) c[i][j]=c[i-1][j-1]+1;
	else c[i][j]=max(c[i-1][j],c[i][j-1]);
      }
 f=f1=c[n][m];
 for (i=n;i>=1&&f!=0;i--)
      for (j=m;j>=1;j--)
	if (x[i]==y[j]) {sol[f]=x[i];
			 i=i-1;
			 m=j-1;

			 f--;
			}
 for (i=1;i<=f1;i++)
     printf ("%d ",sol[i]);
 fcloseall();
 return 0;
}

