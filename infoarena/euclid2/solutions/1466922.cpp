#include <cstdio>

int cmmdc(int x, int y)
{
    if(!(x%y))
    {
        return y;
    }
    return cmmdc(y, x%y);
}

int main()
{
    FILE *in = fopen("euclid2.in", "r");
    FILE *out = fopen("euclid2.out", "w");

    int x,y,t;
    fscanf(in, "%d", &t);
    for(int i = 0; i < t; i++)
    {
        fscanf(in, "%d %d", &x, &y);

        x > y ? fprintf(out, "%d\n", cmmdc(x,y)) : fprintf(out, "%d\n", cmmdc(y,x));
    }
    return 0;
}
