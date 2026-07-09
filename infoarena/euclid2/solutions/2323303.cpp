/*#include <stdio.h>

int main()
{
	int N, S;
	freopen("1-sir.in", "r", stdin);
	freopen("1-sir.out", "w", stdout);
	scanf("%d %d", &N, &S);

	if(S > N*(N-1)/2)
		printf("0");
	else
	{
		//
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
*/
/*
#include <stdio.h>

int div[1000005];
int main()
{
	int n, aux;
	freopen("fractii.in", "r", stdin);
	freopen("fractii.out", "w", stdout);
	scanf("%d", &n);

	int t = 0;
	for(int i = 2; i <= n; i++)
	{
		aux = 1;
		for(int j = 2; j < i; j++)
			if(i%j == 0)
				aux++;

		t += (i-aux);
		printf("nr %d => %d\n", i, aux);
	}
	printf("%d", 2*t+1);
	return 0;
}*//*
#include <iostream>

int main()
{
	int *p = new int[1368709120];
	Sleep(30 * 1000);
	return 0;
}
*/

#include <stdio.h>

int main()
{
	int n, a, b, aux;
	FILE *in = fopen("euclid2.in", "r");
	FILE *out = fopen("euclid2.out", "w");

	fscanf(in, "%d", &n);
	while(!feof(in))
	{
		fscanf(in, "%d %d", &a, &b);

		if(b > a)
		{
			aux = a;
			a = b;
			b = aux;
		}
		while(a%b)
		{
			aux = a%b;
			a = b;
			b = aux;
		}

		fprintf(out, "%d\n", b);
	}

	fclose(in);
	fclose(out);
	return 0;
}