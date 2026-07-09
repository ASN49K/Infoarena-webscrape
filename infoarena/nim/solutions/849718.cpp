
#include <cstdio>

int main (void)
{
	std::freopen("nim.in","r",stdin);
	std::freopen("nim.out","w",stdout);
	int t, n, size, sum;
	std::scanf("%d",&t);
	while (t)
	{
		std::scanf("%d",&n);
		sum = 0;
		while (n)
		{
			std::scanf("%d",&size);
			sum ^= size;
			--n;
		}
		std::printf(sum ? "DA" : "NU");
		std::putchar('\n');
		--t;
	}
	std::fclose(stdin);
	std::fclose(stdout);
	return 0;
}

