#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stack>
#include <cstdlib>

using namespace std;

#define INPUT "source.in"
#define IN "cmlsc.in"
#define OUT "cmlsc.out"

#define N 1024

int n, m;
int* x = (int*)malloc(N*sizeof(int));
int* y = (int*)malloc(N*sizeof(int));
int dp[N][N];

void sol()
{
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; i++) {
		scanf("%d", &x[i]);
	}
	for(int i=0; i<m; i++) {
		scanf("%d", &y[i]);
	}

	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			int max = 0;
			if(i>0 && max<dp[i-1][j]) max=dp[i-1][j];
			if(j>0 && max<dp[i][j-1]) max=dp[i][j-1];
			if(x[i]==y[j]) {
				dp[i][j]=(i>0 && j>0)?dp[i-1][j-1]+1:1;
			} else {
				dp[i][j]=max;
			}
		}
	}
	int cnt=0;
	int i=n-1;
	int j = m-1;
	int ret[N];
	while(i>=0&&j>=0) {
		if(x[i]==y[j]) {
			ret[cnt++] = x[i];
			i--;
			j--;
		} else {
			if(dp[i-1][j]>dp[i][j-1]) {
				i--;
			} else {
				j--;
			}
		}
	}
	printf("%d\n", cnt);
	for(int i=cnt-1; i>=0; i--) {
		printf("%d ", ret[i]);
	}
	printf("\n");
}

int main()
{
#ifdef PADREATI
	freopen(INPUT, "r", stdin);
#else
	freopen(IN, "r", stdin);
	freopen(OUT, "w", stdout);
#endif
	sol();
	return 0;
}
