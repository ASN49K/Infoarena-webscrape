#include<stdio.h>

int f(int x, int y){
	while(x != y){
		if(x > y) x -= y;
		else y -= x;
	}
	
return x;
}

int main(){
	freopen("euclid2.in", "r", stdin);
	freopen("euclid2.out", "w", stdout);
	int n; int a, b, i;
	scanf("%d", &n);
	for(i = 0; i < n; i++){
		scanf("%d%d", &a, &b);
		printf("%d\n", f(a, b));
	}
}
