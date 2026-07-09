#include <stdio.h>


int T, A, B;

int main()
{
	freopen("euclid2.in", "r", stdin);
	freopen("euclid2.out", "w", stdout);
	for(scanf("%d", &T); T; --T)
	{
		scanf("%d %d", &A, &B);
		while(A != B)
		{
			if(A > B)
				A -= B;
			else
				B -= A;
		}
		printf("%d\n", A);
	}
	return 0;
}