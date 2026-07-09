#include <fstream>

using namespace std;

FILE*fin=fopen ("euclid2.in", "r");
FILE*fout=fopen ("euclid2.out", "w");

int cmmdc (int x, int y)
{
    int r=x%y;
    while (r)
    {
        x=y;
        y=r;
        r=x%y;
    }
    return y;
}

int main ()
{
    int t, a, b, i;
    fscanf (fin, "%d", &t);
    for (i=1; i<=t; i++)
    {
        fscanf (fin, "%d", &a);
        fscanf (fin, "%d", &b);
        fprintf (fout, "%d", cmmdc(a,b));
        fprintf (fout, "%c", '\n');
    }
    return 0;
}
