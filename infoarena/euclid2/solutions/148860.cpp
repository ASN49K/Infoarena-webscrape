#include<stdio.h>
	int main () {
	int a,b,c;  
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	scanf("%d%d",&a,&b);
	while (b) {  
		c = a % b;  
		a = b;  
		b = c;  
	} 
	printf("%d",a);
	return 0;
	}
