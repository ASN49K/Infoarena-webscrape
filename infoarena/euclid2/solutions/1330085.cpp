#include <fstream>

using namespace std;
FILE * fin=fopen("euclid2.in", "r");
FILE * fout=fopen("euclid2.out", "w");

int t;

void citire();
int euclid(int a, int b);
int euclid2(int a, int b);

int main()
{
citire();
return 0;
}

int euclid(int a, int b)
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

int euclid2(int a, int b)
{
if (!b) return a;
return euclid2(b, a%b);
}

void citire()
{
int i, a, b;
fscanf(fin, "%d", &t);
for (i=1; i<=t; ++i)
    {
        fscanf(fin, "%d %d", &a, &b);
        fprintf(fout, "%d\n", euclid(a, b));
    }
}
