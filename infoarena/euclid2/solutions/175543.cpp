#include <stdio.h>  
  
int main (){
	int a, b, r, T, i;
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	
	scanf ("%d", &T);
	for (i=0; i<T; i++){
		scanf ("%d", &a);
		scanf ("%d", &b);
		r=a%b;
		while (r!=0){
			a=b;
			b=r;
			r=a%b;}
		if (b!=1)
			printf ("%d\n", b);
		else
			printf ("%d\n", 1);
	}
}
