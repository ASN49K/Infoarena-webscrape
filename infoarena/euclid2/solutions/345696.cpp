#include<stdio.h>

#define CRY 100

int main()
{
	FILE *in, *out;

	long n, v[CRY], i, j, min;

	in = fopen("euclid2.in", "rt");
	out = fopen("euclid2.out", "wt");

	fscanf(in, "%d", &n);

	for(i=1;i<=n*2;i++)
		fscanf(in, "%d", &v[i]);

	for(i=1;i<n*2;i++)
	{
		if (v[i] > v[i+1])
			min = v[i+1];
		else
			min = v[i];

		for(j=min;j>=1;j--)
			if((v[i]%j==0) && (v[i+1]%j==0))
			{
				fprintf(out, "%d ", j);
				i++;
            break;
			}
	}

	fcloseall();

	return 0;

}






