#include<stdio.h>
#define maxn 1025
int a[maxn],b[maxn],nr[maxn][maxn],sol[maxn];
inline int max(int a,int b){
	return a>b?a:b;
}
int main(){
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	int n,m,i,j;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for(i=1;i<=m;++i)
		scanf("%d",&b[i]);
	
	for(i=1;i<=n;++i){
		for(j=1;j<=m;++j){
			if(a[i]==b[j])
				nr[i][j]=1+nr[i-1][j-1];
			else
				nr[i][j]=max(nr[i-1][j],nr[i][j-1]);
		}
	}
	printf("%d\n",nr[n][m]);
	
	for(i=n,j=m;i;){
		if(a[i]==b[j]){
			sol[++sol[0]]=a[i];
			--i;
			--j;
		}
		else{
			if(nr[i][j-1]<=nr[i-1][j])
				--i;
			else
				--j;
		}
	}
	for(i=sol[i];i>0;--i)
		printf("%d ",sol[i]);
	printf("\n");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
