#include<stdio.h>
#include<iostream>
using namespace std;

const int maxn=1025;
int n,m,a[maxn],b[maxn],d[maxn][maxn],sol[maxn],nr,i,j;
int main()
{
	freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);
 
    scanf("%d %d", &m, &n);
    for(i=1;i<=m;++i)
        scanf("%d", &a[i]);
    for(i=1;i<=n;++i)
        scanf("%d", &b[i]);
 
	for(i=1;i<=m;++i)
for(j=1;j<=n;++j)
	if(a[i]==b[j])
		d[i][j]=1+d[i-1][j-1];
	else
		d[i][j]=max(d[i-1][j],d[i][j-1]);
	
	for(i=m,j=n;i;)
		if(a[i]==b[j])
			sol[++nr]=a[i],--i,--j;
		else
			if(d[i-1][j]<d[i][j-1])
				--j;
			else
				--i;
			 printf("%d\n", nr);
    for (i = nr; i; --i)
        printf("%d ", sol[i]);
 
    return 0;
}