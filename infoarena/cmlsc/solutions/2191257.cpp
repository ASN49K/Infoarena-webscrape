#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, b) for (int i = a; i < b; i++)
#define MAXVAL 2000
#define INF 2000000000
typedef long long ll;

int arr1[MAXVAL], arr2[MAXVAL];
int DP[MAXVAL][MAXVAL];
bool mark[MAXVAL];
int main() {
	freopen("cmlsc.in", "r", stdin);
	freopen("cmlsc.out", "w", stdout);
	int n1, n2;
	scanf("%d%d", &n1, &n2);
	REP(i, 0, n1) scanf("%d", &arr1[i]);
	REP(i, 0, n2) scanf("%d", &arr2[i]);
	REP(i, 0, n1) {
		REP(j, 0, n2) {
			if (arr1[i] == arr2[j]) DP[i+1][j+1] = DP[i][j]+1;
			else DP[i+1][j+1] = max(DP[i+1][j], DP[i][j+1]);	
			// printf("%d ", DP[i+1][j+1]);
		}
		// printf("\n");
	}
	for(int i = n1, j = n2; i && j;) {
		if (arr1[i-1] == arr2[j-1]) {
			mark[i] = 1;
			i--; j--;
		}
		else
		if (DP[i-1][j] > DP[i][j-1]) i--;
		else j--;
	}
	printf("%d\n", DP[n1][n2]);
	REP(i, 1, n1+1)
		if (mark[i]) printf("%d ", arr1[i-1]);
	return 0;
}