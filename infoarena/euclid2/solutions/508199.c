#include <stdio.h>
int main()
{
	int a,b,n, c[100000],i;
	freopen("euclid.in", "r", stdin);
	freopen("euclid.out", "w", stdout);

	scanf("%d",&n);

	for (i = 0; i < n; ++i){

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

	}
		
	for (i = 0; i < n; ++i)

	printf("%d",a);
	
	
	
	return 0;
}
