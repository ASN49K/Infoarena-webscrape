#include <fstream>

using namespace std;

int main()
{
    int t, a, b, x;

    FILE * fin = fopen("euclid2.in", "r");
    FILE * fout = fopen("euclid2.out", "w");

    fscanf(fin, "%d", &t);
    while (t--)
    {
        fscanf(fin, "%d%d", &a, &b);
        while ((x = a % b))
        {
            a = b;
            b = x;
        }
        fprintf(fout, "%d\n", b);
    }
    fclose(fin);
    fclose(fout);
    return 0;
}
