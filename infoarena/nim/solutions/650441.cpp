#include<cstdio>

int t, n, a, sum;

int main() {
	freopen("nim.in", "r", stdin), freopen("nim.out", "w", stdout);
	scanf("%d", &t);
	
	while(t--) {
		scanf("%d", &n); sum = 0;
		for(int i = 1; i <= n; i++) {
			scanf("%d", &a);
			sum = sum ^ a;
		}		
		printf(sum ? "DA\n" : "NU\n");
	}
	
	return 0;
}
