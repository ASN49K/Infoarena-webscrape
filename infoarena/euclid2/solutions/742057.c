#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmmdc(int a, int b){
	if(a == b){return a;} 
	else if(a > b){cmmdc(a - b, b);} 
	else {cmmdc(a, b - a);}
}

int main(){
	int a, b, nr, i;
	freopen("euclid.in", "r", stdin);
	freopen("euclid.out", "w", stdout);
	scanf("%d", &nr);
	for(i = 0; i < nr; i++){
		scanf("%d", &a);scanf("%d", &b);
		printf("%d\n", cmmdc(a, b));
	}
	return 0;
}
