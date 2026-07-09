#include <stdio.h>
#define Nmax 1025

int n,m,a[Nmax],b[Nmax],i,j,c[Nmax][Nmax],k;
char d[Nmax][Nmax];

void scr(int x,int y)
{
 if(d[x][y]=='e')
  {
   scr(x-1,y-1);
   printf("%d ",a[x]);
  }
 if(d[x][y]=='1')
  scr(x-1,y);
 if(d[x][y]=='2')
  scr(x,y-1);
}

int main()
{
 freopen("cmlsc.in","r",stdin);
 freopen("cmlsc.out","w",stdout);
 scanf("%d %d",&n,&m);
 for(i=1;i<=n;i++)
  scanf("%d",&a[i]);
 for(i=1;i<=m;i++)
  scanf("%d",&b[i]);
 for(i=1;i<=n;i++)
  for(j=1;j<=m;j++)
   if(a[i]==b[j])
     {
      c[i][j]=c[i-1][j-1]+1;
      d[i][j]='e';
     }
    else
     if(c[i-1][j]>c[i][j-1])
       {
        c[i][j]=c[i-1][j];
        d[i][j]='1';
       }
      else
       {
	c[i][j]=c[i][j-1];
	d[i][j]='2';
       }
 printf("%d\n",c[n][m]);
 scr(n,m);
 return 0;
}
