#include <cstdio>
#define BM 1030
int maxim(int a,int b){
	if(a>b)return a;
	return b;
}
int nume[BM][BM],rez[BM],a[BM],b[BM],dim,n,m;
int main () {
	int i,j;
	
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;++i)scanf("%d",&a[i]);
	for(i=1;i<=m;++i)scanf("%d",&b[i]);
	for(i=1;i<=n;++i)for(j=1;j<=m;++j){
		if(a[i]==b[j])nume[i][j]=nume[i-1][j-1]+1;
		else nume[i][j]=maxim(nume[i-1][j],nume[i][j-1]);
	}
	for(i=n,j=m;i&&j;){
		if(a[i]==b[j]){
			rez[++dim]=a[i];
			--i;
			--j;
		}
		else {
			if(nume[i][j-1]>nume[i-1][j])--j;
			else --i;
		}
	}
	printf("%d\n",dim);
	for(i=dim;i;--i)printf("%d ",rez[i]);
	return 0;
}
