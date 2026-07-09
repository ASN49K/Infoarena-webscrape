#include <iostream>
#include <fstream>
using namespace std;

int Cmmdc(int a, int b)
{
    if (!b) return a;
    return Cmmdc(b, a % b);
}

int main()
{
    FILE *fin = fopen("euclid2.in", "r");
    FILE *fout = fopen("euclid2.out", "w");
    int n;
    fscanf(fin, "%d", &n);
    for (int i = 0; i < n; i++)
    {
        int a, b;
        fscanf(fin, "%d%d", &a, &b);
        fprintf(fout, "%d\n", Cmmdc(a, b));
    }

    fclose(fin);
    fclose(fout);

      return 0;
}
