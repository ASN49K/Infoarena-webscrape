#include<stdio.h>
int a[1030],b[1030],lcs[1030][1030];
int n,m;

int max(int a,int b){
	return a>b?a:b;
}

void doPrint(int i,int j){
	if(!(i>=1 &&j>=1)) return;
	if(a[i]==b[j]){
		doPrint(i-1,j-1);
		printf("%d ",a[i]);		
	}
	else{
		if(lcs[i-1][j]>lcs[i][j-1]) doPrint(i-1,j);
		else doPrint(i,j-1);
	}
}
int main(){
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=m;i++) scanf("%d",&b[i]);
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(a[i]==b[j]){
				lcs[i][j]=lcs[i-1][j-1]+1;
			}
			else{
				lcs[i][j]=max(lcs[i][j-1],lcs[i-1][j]);
			}
	printf("%d\n",lcs[n][m]);
	doPrint(n,m);
	return 0;
}