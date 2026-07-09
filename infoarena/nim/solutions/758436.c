#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE * in = fopen("nim.in","r");
    FILE * out = fopen("nim.out","w");
    int i, j, xorizare, x;
    for (fscanf(in,"%d", &i); i; i--)
    {
        xorizare = 0;
        for (fscanf(in,"%d", &j); j; j--)
        {
            fscanf(in,"%d", &x);
            xorizare ^= x;
        }
        if (xorizare)
            fprintf(out,"DA\n");
        else
            fprintf(out,"NU\n");
    }
    fclose(in);
    fclose(out);
    return 0;
}
