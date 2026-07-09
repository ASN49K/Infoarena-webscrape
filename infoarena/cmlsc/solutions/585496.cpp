#include<cstdio>
#include<algorithm>
using namespace std;

int n1, n2;
int v1[15], v2[15], s[15][15], r[15];

int main() {
	int i, j, k = 0;
	
	freopen("cmlsc.in", "rt", stdin);
	freopen("cmlsc.out", "wt", stdout);
	scanf("%d%d", &n1, &n2);
	for(i = 1; i <= n1; ++i)
		scanf("%d", &v1[i]);
	for(i = 1; i <= n2; ++i)
		scanf("%d", &v2[i]);
	
	for(i = 1; i <= n1; ++i)
		for(j = 1; j <= n2; ++j) {
			s[i][j] = 0;
			if(v1[i] == v2[j])
				s[i][j] = s[i - 1][j - 1] + 1;
			if(max(s[i - 1][j], s[i][j - 1]) > s[i][j]) 
				s[i][j] = max(s[i - 1][j], s[i][j - 1]);
		}
	
	for(i = n1, j = n2; s[i][j];) {
		if(v1[i] == v2[j]) {
			r[++k] = v1[i];
			--i; --j;
		}
		else if(s[i][j] == s[i - 1][j])
			--i;
		else
			--j;
	}
	
	printf("%d\n", k);
	for(i = 1; i <= k; ++i)
		printf("%d ", r[k - i + 1]);
	printf("\n");
	return 0;
}