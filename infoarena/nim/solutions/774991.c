#include <stdio.h>

int main()
{
    int t, n, i, v, nimSum;
    FILE *in = fopen("nim.in", "r");
    FILE *out = fopen("nim.out", "w");

    for (fscanf (in, "%d", &t); t; --t)
    {
        for(fscanf (in, "%d", &n), nimSum = 0; n; --n)
        {
            fscanf (in, "%d", &v);
            nimSum ^= v;
        }

        if (nimSum) fprintf (out, "DA\n");
        else fprintf (out, "NU\n");
    }

    fclose(in);
    fclose(out);
    return 0;
}
