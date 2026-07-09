#include<cstdio>
using namespace std;
int cmmdc(int a, int b)
{
    if(a % b == 0) return b;
    if(b % a == 0) return a;
    return cmmdc(a % b, b % a);
}
int main()
{
    FILE* in = fopen("euclid2.in", "r");
    FILE* out = fopen("euclid2.out", "w");
    int a, b, t;
    fscanf(in, "%d", &t);
    for(int i = 1; i <= t; ++i)
    {
        fscanf(in, "%d%d", &a, &b);
    fprintf(out, "%d\n", cmmdc(a, b));
    }
}
