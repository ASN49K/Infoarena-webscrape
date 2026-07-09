#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmmdc(int a, int b){
	while(a != b){
		if(a > b){
			a = a - b;
		} else {
			b = b - a;
		}
	}
}

int main(){
	int a, b, nr, i;
	freopen("euclid2.in", "r", stdin);
	freopen("euclid2.out", "w", stdout);
	scanf("%d", &nr);
	for(i = 0; i < nr; i++){
		scanf("%d", &a);scanf("%d", &b);
		printf("%d\n", cmmdc(a, b));
	}
	return 0;
}
