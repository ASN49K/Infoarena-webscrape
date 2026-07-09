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
	scanf("%d %d",&a, &b);
	printf("%d\n",euclids(a,b));
	return 0;
}
