using namespace std;
#include<stdio.h>

int euclids(int a, int b)
{
	if(a%b==0)
		return b;
	return euclids(b, a%b);
}

int main()
{
	int a,b;
	freopen("euclid2.in","r",stdin);
	scanf("%d %d",&a, &b);
	freopen("euclid2.out","w",stdout);
	printf("%d\n",euclids(a,b));
	return 0;
}
