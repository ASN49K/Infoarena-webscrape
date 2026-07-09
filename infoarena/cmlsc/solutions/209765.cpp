#include<stdio.h>
int v[1100], w[1100], a[1100][1100];
void lungime(int i, int j){
	if(i==0){
		a[i][j]=0;
		return;
	}
	if(j==0){
		a[i][j]=0;
		return;
	}
	if(v[i]==w[j]){
		a[i][j]=a[i-1][j-1]+1;
	}
	else{
		if(a[i-1][j]>=a[i][j-1]){
			a[i][j]=a[i-1][j];
		}
		else{
			a[i][j]=a[i][j-1];
		}
	}
	
}
void refac(int i, int j){
	//printf("(%d,%d) ",i,j);
	if(i==0)
		return;
	if(j==0)
		return;
	if(v[i]==w[j]){
		refac(i-1, j-1);
		printf("%d ", v[i]);
		return;
	}
	if(a[i][j]==a[i-1][j]){
		refac(i-1, j);
		return;
	}
	refac(i, j-1);
}

int main(){
	freopen("cmlsc.in", "r", stdin);
	freopen("cmlsc.out", "w", stdout);
	int m, n, i, j;
	scanf("%d", &m);
	scanf("%d", &n);
	for(i=1; i<=m;++i)
		scanf("%d", &v[i]);
	for(i=1; i<=n;++i)
		scanf("%d", &w[i]);
	for(i=1; i<=m;++i)
		for(j=1; j<=n; ++j)
			lungime(i, j);
	lungime(m, n);
	printf("%d\n", a[m][n]);
	refac(m, n);
	

	return 0;
}