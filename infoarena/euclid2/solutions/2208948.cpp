#include<iostream>
using namespace std;

int euclid(int a, int b)
{
	if (b == 0)
		return a;
	else
		return euclid(b, a%b);
}

int main()
{
	freopen("euclid2.in", "r", stdin);
	freopen("euclid2.out", "w", stdout);
	int t, a, b;
	scanf("%d",&t);
	for (int i = 1; i <= t; i++)
	{
		scanf("%d %d", &a, &b);
		printf("%d \n", euclid(a, b));
	}
}