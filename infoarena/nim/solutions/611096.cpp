#include<stdio.h>

int main()
{
	int N, x, now, NIM;

	freopen("nim.in", "r", stdin);
	freopen("nim.out", "w", stdout);

	scanf("%d", &N);
	while(N --)
	{
		scanf("%d", &x);
		NIM = 0;
		while(x --)
			{
			scanf("%d", &now);
			NIM = NIM ^ now;
			}

		printf("%s\n", NIM > 0 ? "DA" : "NU");
	}

	return 0;
}
