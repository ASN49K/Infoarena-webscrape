#include <stdio.h>
#include <string.h>
int main()
{
	int a,b,n,i,c[100];
	freopen("euclid.in", "r", stdin);
	freopen("euclid.out", "w", stdout);


	scanf("%d",&n);

	while(n){

		scanf("%d%d",&a,&b);
	
	while(a && b && a != b){
		if (a > b){
			a -= b;
		}
		else{
			b -= a;
		}
	}

	c[i] = a;
	n--;

	}
		
	for (i = 0; i < n; ++i)

	printf("%d\n",a);	
	return 0;
}
