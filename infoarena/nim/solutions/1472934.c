#include <stdio.h>
#define MAX 10005

int t, n, sum, a, i, j;

int main(){
	freopen("nim.in", "r", stdin);
	freopen("nim.out", "w", stdout);
	scanf("%d", &t);
	for(i = 0; i < t; i++){
		scanf("%d", &n);
		scanf("%d", &sum);
		for(j = 1; j < n; j++){
			scanf("%d", &a);
			sum ^= a;
		}
		if(sum > 0)
			printf("DA\n");
		else
			printf("NU\n");
	}
	return 0;
}
