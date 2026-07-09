#include<stdio.h>

#define NMAX 1025

int main(){
freopen("cmlsc.in","r",stdin);
freopen("cmlsc.out","w",stdout);
int m,n,i,j,k,a[NMAX],b[NMAX],c[NMAX][NMAX],lc,cc,sol[NMAX],lmax;
scanf("%d%d",&m,&n);
for(i=1;i<=m;++i) scanf("%d",&a[i]);
for(i=1;i<=n;++i) scanf("%d",&b[i]);
for(i=0;i<=m;++i) c[i][0]=0;
for(j=0;j<=n;++j) c[0][j]=0;
for(i=1;i<=m;++i)
	for(j=1;j<=n;++j)
		if(a[i]==b[j]) c[i][j]=c[i-1][j-1]+1;
		else
			if(c[i-1][j]>=c[i][j-1]) c[i][j]=c[i-1][j];
			else c[i][j]=c[i][j-1];
lmax=c[m][n];
printf("%d\n",lmax);
i=m;j=n;k=0;
while(i&&j){
	if(a[i]==b[j]) {k++;sol[k]=a[i];--i;--j;}
	else
		if(c[i][j]==c[i][j-1]) --j;
		else --i;
	}
for(k=lmax;k;--k) printf("%d ",sol[k]);
return 0;
}
