#include <cstdio>

using namespace std;

FILE *in, *out;

int main()
{
    in = fopen("nim.in", "r");
    out = fopen("nim.out", "w");

    int t, n, x, sol;

    fscanf(in, "%d", &t);

    while(t > 0)
    {
        sol = 0;
        fscanf(in, "%d", &n);
        for(int i = 0; i < n; i++)
        {
            fscanf(in, "%d", &x);
            sol ^= x;
        }
        if(sol == 0)
            fprintf(out, "NU\n");
        else fprintf(out, "DA\n");
        t--;
    }

    fclose(in);
    fclose(out);
    return 0;
}
