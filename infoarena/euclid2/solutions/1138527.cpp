#include <stdio.h>
//#include <fstream>
using namespace std;
FILE *fin=fopen("Euclid2.in", "r");
FILE *fout=fopen("Euclid2.out", "w");
//ofstream fout("Euclid2.out");
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
    //fout<<b<<'\n';
    fprintf(fout, "%d\n", b);
}

int main()
{
    fscanf(fin, "%d ", &t);
    for(i=1; i<=t; i++)
        Solutie();
    //fout.close();
    fclose(fout);
    fclose(fin);
    return 0;
}
