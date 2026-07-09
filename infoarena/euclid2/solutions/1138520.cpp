#include <fstream>
#include <stdio.h>
#define Nmax
using namespace std;
FILE *fin=fopen("Euclid2.in", "r");
ofstream fout("Euclid2.out");

void Solutie()
{
    int a, b, r;
    fscanf(fin, "%d %d ", &a, &b);
    r=a%b;
    while(r)
    {
        a=b;
        b=r;
        r=a%b;
    }
    fout<<b<<'\n';
}

int main()
{
    int t, i;
    fscanf(fin, "%d ", &t);
    for(i=1; i<=t; i++)
        Solutie();
    fout.close();
    fclose(fin);
    return 0;
}
