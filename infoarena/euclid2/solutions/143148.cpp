#include <cstdio>

FILE *in = fopen("euclid2.in","r"), *out = fopen("euclid2.out","w");

int a, b;

int cmmdc(int a, int b)
{
    if ( !b )
        return a;

    return cmmdc(b, a % b);
}

int main()
{
    fscanf(in, "%d %d", &a, &b);

    fprintf(out, "%d\n", cmmdc(a, b));


	return 0;
}
