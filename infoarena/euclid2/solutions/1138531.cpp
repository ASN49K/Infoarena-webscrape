#include <stdio.h>
#include <fstream>
using namespace std;
FILE *fin=fopen("euclid2.in", "r");
ofstream fout("euclid2.out");
int a, b, r, t, i;

void Solutie()
{
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
    fscanf(fin, "%d ", &t);
    for(i=1; i<=t; i++)
        Solutie();
    fout.close();
    fclose(fin);
    return 0;
}
