#include <cstdio>
using namespace std;

FILE* is = fopen("euclid2.in", "r");
FILE* os = fopen("euclid2.out", "w");

int Cmmdc(int a, int b);

int main()
{
    int T, a, b;
    fscanf(is, "%d", &T);
    for ( int i = 0; i < T; ++i )
    {
        fscanf(is, "%d%d", &a, &b);
        fprintf(os, "%d\n", Cmmdc(a, b));
    }
    fclose(is);
    fclose(os);
    return 0;
}
int Cmmdc(int a, int b)
{
    int rest;
    do
    {
        rest = a % b;
        a = b;
        b = rest;
    } while ( rest != 0 );
    return a;
}
