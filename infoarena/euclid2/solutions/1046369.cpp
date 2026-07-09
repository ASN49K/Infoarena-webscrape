#include <stdio.h>
FILE *fin,*fout;
using namespace std;
int teste,a,b;
int gcd(int a, int b)
{
    if(!b) return a;
    return gcd(b, a%b);
}
int main()
{
    fin=fopen("euclid2.in","r");
    fout=fopen("euclid2.out","w");
    fscanf(fin,"%d",&teste);
    while(teste--)
    {
        fscanf(fin,"%d%d",&a,&b);
        fprintf(fout,"%d\n", gcd(a,b));
    }
}
