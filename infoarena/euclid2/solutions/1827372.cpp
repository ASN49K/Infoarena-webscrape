#include <fstream>
#include <stdio.h>
using namespace std;
FILE *fin = fopen("euclid2.in", "r");
FILE *fout = fopen("euclid2.out", "w");
long T,a,b,r;
int main()
{
    fscanf(fin,"%ld", &T);
    while(T--)
    {
        fscanf(fin,"%ld %ld", &a, &b);
        while(b)
        {
            r=a%b;
            a=b;
            b=r;
        }
        fprintf(fout,"%ld\n",a);
    }
    return 0;
}
