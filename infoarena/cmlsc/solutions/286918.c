#include <stdio.h>
#include <stdlib.h>

#define maxim(a,b) ((a>b) ? a : b)
#define FOR(i, a, b) for(i=a; i<=b; i++)
#define Nmax 1024




int main()
{

int a[Nmax], b[Nmax], c[Nmax][Nmax], sir[Nmax], n, m, i, j,poz;


freopen ("cmlsc.in","r",stdin);
freopen ("cmlsc.out","w",stdout);

scanf ("%d %d",&m,&n);

FOR(i, 1, m) scanf ("%d",&a[i]);

FOR(i,1,n) scanf ("%d",&b[i]);

FOR(i,1,m)
  FOR(j,1,n)
     if (a[i]==b[j])
	 c[i][j]=c[i-1][j-1]+1;
	     else
		c[i][j]=maxim (c[i-1][j],c[i][j-1]);


poz=0;
for (i=m;i>1;i--)
  for (i=m,j=m;i;)
     if (a[i]==b[j]) { sir[++poz]=a[i];
		       i--; j--;}
	 else
	   if (c[i-1][j]<c[i][j-1])
		j--;
		   else i--;

printf ("%d\n",poz);

FOR(i,1,poz) printf ("%d ",sir[poz]);

return 0;

}

