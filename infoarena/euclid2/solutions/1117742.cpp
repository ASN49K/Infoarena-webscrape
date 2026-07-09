#include<stdio.h>

void main(){
	freopen("euclid2.in", "r", stdin);
	freopen("euclid2.out", "w", stdout);
	int a, b,n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i){
		scanf("%d%d", &a, &b);
		while (a != b && a>0 && b>0){
			if (a>b)
				a %= b;
			else
				b %= a;
		}
		if (a > 0)
			printf("%d\n", a);
		else
			printf("%d\n", b);
	}
}