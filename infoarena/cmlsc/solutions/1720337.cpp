#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#define NMAX 1025
using namespace std;

int n, m, a[NMAX], b[NMAX], lcs[NMAX][NMAX];
vector<int> ans;

int main(){
	freopen("cmlsc.in", "r", stdin);
	freopen("cmlsc.out", "w", stdout);

	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= m; i++){
		scanf("%d", &b[i]);
	}
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			if (a[i] == b[j]) {
				lcs[i][j] = lcs[i - 1][j - 1] + 1;
			}
			else {
				lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
			}
		}
	}

	printf("%d\n", lcs[n][m]);

	int pozx = n, pozy = m;
	while (pozx > 0 && pozy > 0){
		if (a[pozx] == b[pozy]){
			ans.push_back(a[pozx]);
			pozx--; pozy--;
		}
		else{
			if (lcs[pozx] > lcs[pozy]){
				pozx--;
			}
			else pozy--;
		}
	}

	for (int i = ans.size() - 1; i >= 0; i--){
		printf("%d ", ans[i]);
	}
	printf("%\n");
	return 0;
}
