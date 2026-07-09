#include<stdio.h>
#define N 1024

int m,n,nr;
int A[N],B[N],v[N][N],sir[N];

inline int max(int a,int b){
	if(a>b)
		return a;
	return b;
}

int main(){
	int i,j;
	freopen("cmlsc.in", "r", stdin);
	freopen("cmlsc.out", "w", stdout);
	scanf("%d%d",&m,&n);
	for(i=1;i<=m;++i)
		scanf("%d",&A[i]);
	for(i=1;i<=n;++i)
		scanf("%d",&B[i]);
	for(i=1;i<=m;++i)
		for(j=1;j<=n;++j)
			if(A[i]==B[j])
				v[i][j]=1+v[i-1][j-1];
			else
				v[i][j]=max(v[i][j-1],v[i-1][j]);
	for(i=m,j=n;i;)
		if(A[i]==B[j]){
			sir[++nr]=A[i];
			--i;
			--j;
		}
		else
			if(v[i][j-1]>v[i-1][j])
				--j;
		else
			--i;
	printf("%d\n",nr);
	for(i=nr;i;--i)
		printf("%d ",sir[i]);
	printf("\n");
	fclose(stdin);
	fclose(stdout);
	return 0;  
}
