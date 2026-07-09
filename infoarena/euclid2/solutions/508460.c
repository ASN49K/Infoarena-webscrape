#include <stdio.h>
#include <string.h>

int euclid(int a,int b)
{
	while(a!=b){
		 if(a>b) a =a-b;
		 else b =b-a;
	}
	return a;
}
int main()
{
	int a,b,n;
	freopen("euclid.in", "r", stdin);
	freopen("euclid.out", "w", stdout);

	scanf("%d",&n);

	while(n){
		scanf("%d%d",&a,&b);
		printf("%d",euclid(a,b));
		n--;
	}
}

		

