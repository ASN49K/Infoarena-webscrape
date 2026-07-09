#include <stdio.h>
#include <string.h>

int euclid(int a,int b)
{
	while(a!=b){
		if(a==0) return b;
		else if(b==0) return a;
			else if(a>b) a -=b;
				else b -=a;
	return a;
	}
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

		

