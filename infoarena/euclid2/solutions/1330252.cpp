#include <cstdio>
using namespace std;
FILE*fout=fopen ("euclid2.out", "w");

void citire();
int cmmdc(int, int);

int main()
{
    citire();
    return 0;
}

void citire()
{
    int t, a, b;
    FILE*fin=fopen ("euclid2.in", "r");
    fscanf(fin, "%d", &t);
    while (t)
    {
        fscanf(fin, "%d %d", &a, &b);
        fout<<cmmdc(a, b);
        --t;
    }
    fclose(fin);
    fclose(fout);
    return;
}

int cmmdc (int a, int b)
{
    int r;
    while (b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
