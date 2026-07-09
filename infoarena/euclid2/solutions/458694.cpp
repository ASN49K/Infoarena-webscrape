#include <stdio.h>   
int T, a, b, i, aux; 
int main(){   
  freopen("euclid2.in", "r", stdin);   
  freopen("euclid2.out", "w", stdout);   
  scanf("%d", &T);   
  for (i=1;i<=T;i++){   
	scanf("%d %d", &a, &b); 
	while(b){
	  aux=a;
	  a=b;
	  b=aux;
	  b=a%b;
	}
	printf("%d\n", a);
  }           
  return 0;   
} 
