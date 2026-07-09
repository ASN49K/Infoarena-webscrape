#include<stdio.h>
#define max(a,b) ((a>b) ? a:b)
#define fr(i,a,b) for(i=a;i<=b;i++)
#define nmax 1000

 int a[nmax],b[nmax],d[nmax][nmax],i,j,v[nmax],nr,m,n;
 
  int main()
{
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	
 scanf("%d%d\n",&m,&n);
 fr(i,1,m)
 scanf("%d",&a[i]);
 fr(j,1,n)
 scanf("%d",&b[j]);
 
 fr(i,1,m)
 fr(j,1,n)
 {
	 if(a[i]==b[j])
		 d[i][j]=1+d[i-1][j-1];
	else
	d[i][j]=max(d[i-1][j],d[i][j-1]);
 }
 
for(i=m,j=n;i;)
 {
	if(a[i]==b[j]) 
	{
	nr++;
	v[nr]=a[i];
	i--; j--;
	}
	else
		{
			if(d[i-1][j]<d[i][j-1])
			j--;
		else
			i--;
	}
 }
 
 printf("%d\n",nr);
 for(i=nr;i;i--)
 printf("%d ",v[i]);
 
 return 0;
  }
 