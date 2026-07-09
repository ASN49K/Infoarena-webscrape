#include <stdio.h>

int main()
{
    FILE *in, *out;
    int a, b, rest, nr, ok = 0;
    in = fopen( "euclid2.in", "r");
    out = fopen( "euclid2.out", "w");
    fscanf(in,"%d", &nr);
    while( ok < nr)
    {
        fscanf(in,"%d", &a);
        fscanf(in,"%d", &b);
        do
        {
             rest = a % b;
             a = b;
             b = rest;                    
        }while( rest != 0);
        fprintf(out, "%d\n", a);
        ok++;
    }
    return 0;   
}
