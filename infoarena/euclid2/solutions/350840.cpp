#include<stdio.h>
#include<values.h>
#define CRY 10000
int main()
{
	FILE *in, *out;

	unsigned long n, v[CRY];
	int i, j, max;

	in = fopen("euclid2.in", "rt");
	out = fopen("euclid2.out", "wt");

	fscanf(in, "%d", &n);

	for(i=1;i<=2*n;++i)
		fscanf(in, "%d", &v[i]);

	for(i=1;i<=2*n;i=i+2)
	{
		max = -MAXINT;

		if(v[i]>=v[i+1])
			for(j=1;j<=v[i];++j)
			{
				if((v[i]%j==0) && (v[i+1]%j==0))
					if(max<j)
						max=j;
			}
		else
			for(j=1;j<=v[i+1];++j)
			{
				if((v[i]%j==0) && (v[i+1]%j==0))
					if(max<j)
						max=j;
			}

		fprintf(out, "%d\n", max);
   }


	return 0;
	fcloseall();
}
