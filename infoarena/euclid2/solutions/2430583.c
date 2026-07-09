#include <stdio.h>

inline int euclid(int a, int b) {
	int c = 0;
	if (a < b)
	{
		a = a+b;
		b = a - b;
		a = a - b;
	}
	while (a % b > 0)
	{
		if (b % (a%b) == 0) return a % b;
		a = a / b;
		if (a<b)
			if (a < b)
			{
				a = a + b;
				b = a - b;
				a = a - b;
			}
		if (a / b < 2) return 1;
	};
	return b;
}

int main()
{
	FILE *f = fopen("euclid.in", "r");
	FILE *g = fopen("euclid.out", "w");
	int n;
	fscanf(f, "%d", &n);
	//printf("n = %d", n);
	int i = 0;
	for (i; i < n; ++i)
	{
		int a = 0;
		int b = 0;
		fscanf(f,"%d %d", &a, &b);
		printf("%d \n", euclid(a, b));
	}
	getch();

}