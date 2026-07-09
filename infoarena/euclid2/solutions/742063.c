#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmmdc(int a, int b){
	int t;
	while(a != b){
		if(a > b){
			t = a = a - b;
		} else {
			t = b = b - a;
		}
	}
	return t;
}

int main(){
	int a, b, i = 0, nr;
	freopen("euclid2.in", "r", stdin);
	freopen("euclid2.out", "w", stdout);
	scanf("%d", &nr);
	while(i != nr){
		scanf("%d %d", &a, &b);
		printf("%d\n", cmmdc(a, b));
		i++;
	}
}
