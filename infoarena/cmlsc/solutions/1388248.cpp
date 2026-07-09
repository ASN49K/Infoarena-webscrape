#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int M,N, v1[1025], v2[1025], dp[1025][1025], sol[1025][1025], s[1025];
void readElems(int* v, int len){
	for(int i = 1;i <= len;i++)
		scanf("%d", v + i);
}
void printElems(int* v, int len){
	for(int i = 1;i <= len;i++)
		printf("%d ", v[i]);
	printf("\n");
}
void calculeazaCmlsc(){
	for(int i = 1; i <= N;i++){
		for(int j = 1; j<= M;j++){
			if(v1[i] == v2[j]){
				dp[i][j] = dp[i-1][j-1] + 1;
				sol[i][j] = 1;
			}else{
				if(dp[i-1][j] >= dp[i][j-1]){
					dp[i][j] = dp[i-1][j];
				}else{
					dp[i][j] = dp[i][j-1];
				}
			}
		}
	}
}
void computeSol(){
	for(int i = N, j = M; i;){
		if(sol[i][j] == 1) s[dp[i][j]--] = v1[i], i-- , j--;
		else if (dp[i-1][j] < dp[i][j-1]) j--;
		else i--;
		
	}
}
int main() {
	freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
	scanf("%d%d", &N, &M);
	readElems(v1,N);
	readElems(v2,M);
	calculeazaCmlsc();
	int len = dp[N][M];
	printf("%d\n", dp[N][M]);
	computeSol();
	printElems(s,len);
	return 0;
}