#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
	int i,n,a,b,c;
	freopen("euclid2.in","r", stdin);
	freopen("euclid2.out","w", stdout);
	scanf("%d\n",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d %d\n",&a,&b);
		while(b)
		{
			c=a%b;
			a=b;
			b=c;
		}
		printf("%d",a);

	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
