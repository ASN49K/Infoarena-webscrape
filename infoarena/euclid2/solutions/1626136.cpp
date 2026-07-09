#include <stdio.h>

int main(){
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	int T, a, b, aux, i;
	scanf("%d ", &T);
	for(i = 0; i < T; i++){
		scanf("%d %d ", &a, &b);
		if(a<b){
			aux = a;
			a = b;
			b = aux;
		}
		while(a%b != 0){
			aux = a % b;
			a = b;
			b = aux;
		}
		printf("%d\n",b);
	}
	return 0;
}