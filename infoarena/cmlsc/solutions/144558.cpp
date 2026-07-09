#include<stdio.h>
long n,m,i,a[2000],b[2000],j,t[100][100],max,k,sol[2000];
int main()
{
 freopen("cmlsc.in","r",stdin);
 freopen("cmlsc.out","w",stdout);
 scanf("%ld%ld",&n,&m);
 for(i=1;i<=n;++i) scanf("%ld",&a[i]);
 for(i=1;i<=m;++i) scanf("%ld",&b[i]);
 for(i=1;i<=n;++i)
    for(j=1;j<=n;++j)
       if(a[i]==b[j])
	 {t[i][j]=t[i-1][j-1]+1;
	  if(t[i][j]>max) max=t[i][j];}
		 else
	 {if(t[i-1][j]>t[i][j-1]) t[i][j]=t[i-1][j];
			     else t[i][j]=t[i][j-1];
	  if(t[i][j]>max) max=t[i][j];}
 printf("%ld\n",max);
 k=0;
 i=n;
 j=m;
 while(t[i][j])
  if(a[i]==b[j])
    {sol[++k]=a[i];--i;--j;}
	    else
    if(t[i-1][j]==t[i][j]) --i;
		      else --j;
 for(k;k>=1;--k) printf("%ld ",sol[k]);
 printf("\n");
 return 0;
}