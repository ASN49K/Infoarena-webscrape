#include <stdio.h>


/*int euclid(int a,int b)
{
	while(a!=b){
		 if(a>b) a =a-b;
		 else b =b-a;
	}
	return a;
}
*/
int main()
{
	long a,b,n;
	freopen("euclid.in", "r", stdin);
	freopen("euclid.out", "w", stdout);

	scanf("%ld",&n);

	while(n){
		scanf("%ld%ld",&a,&b);
		while(a!=b){
		 if(a>b) a =a-b;
		 else b =b-a;
	        }
		if(a==b) printf("%ld\n",a);
		n--;
	}
}

		

