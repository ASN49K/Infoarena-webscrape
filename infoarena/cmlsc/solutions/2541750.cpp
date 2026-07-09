#include<stdio.h>
int M,N;

int max(int a,int b){
	if(a>b) return a;
	return b;
}

int main(){
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	scanf("%d %d",&M,&N);
	int A[M+1],B[N+1];
	int dp[M+1][N+1];
	for(int i=1;i<=M;i++) scanf("%d",&A[i]);
	for(int i=1;i<=N;i++) scanf("%d",&B[i]);
	for(int i=0;i<=M;i++) dp[i][0] = 0;
	for(int j=0;j<=N;j++) dp[0][j] = 0;
	for(int i=1;i<=M;i++)
	for(int j=1;j<=N;j++){
		if(A[i]==B[j]) dp[i][j]=1+dp[i-1][j-1];
		else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
	}

	printf("%d\n",dp[M][N]);

	int i=M,j=N;
	int k=0;
	int st[M+N+2];
	while(i>0){
		if(A[i]==B[j]) {
			st[k]=A[i];k++;
			i-=1;
			j-=1;
		}
		else if (dp[i-1][j]<dp[i][j-1]) j--;
		else i--;
	}
	while(k) printf("%d ",st[--k]);
}
