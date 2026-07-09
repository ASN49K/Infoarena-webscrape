#include <cstdio>
using namespace std;

int main()
{
	freopen ("euclid2.in", "r", stdin);
	freopen ("euclid2.out", "w", stdout);
	
	int a,b,n,r;
	scanf ("%d", &n);
	for (int i=1;i<=n;i++)
	{
		scanf ("%d %d", &a, &b);
		do
		{
			r=a%b;
			a=b;
			b=r;
		}while (r!=0);
		printf ("%d \n", a);
	}
	return 0;
}
