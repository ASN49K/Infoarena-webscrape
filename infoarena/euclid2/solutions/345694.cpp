#include<stdio.h>

#define CRY 100

int main()
{
	FILE *in, *out;

	int n, v[CRY], i;

	in = fopen("euclid2.in", "rt");
	out = fopen("euclid2.out", "wt");

	fscanf(in, "%d", &n);

	for(i=1;i<=n*2;i++)
		fscanf(in, "%d", &v[i]);

	for(i=1;i<n*2;i++)
	{
			while((v[i]-v[i+1])!=0)
			{
				if(v[i] > v[i+1])
					v[i] = v[i] - v[i+1];
				else
					v[i+1] = v[i+1] - v[i];
			}
		fprintf(out, "%d ", v[i]);
      i++;
	}

	fcloseall();

	return 0;

}






