#include <iostream>
#include <stdio.h>

int Euclid(int a, int b)
{
    int rest = a % b;
    
    if (!rest)
        return b;
        
    else
        return Euclid(b, rest);

}

int main()
{
	FILE *in = fopen("euclid2.in", "rt");
	FILE *out = fopen("euclid2.out", "wt");
	
    int v[2], N;
    fscanf (in, "%d", &N);
	while (N--)
	{
		fscanf(in, "%d%d", &v[0], &v[1]);     
		fprintf(out, "%d\n", Euclid(v[0],v[1]));
    }
	fclose(in);
	fclose(out);
    return 0;
}
