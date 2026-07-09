#include <cstdio>

using namespace std;

unsigned T,A,B;

unsigned alg_lui_euc(unsigned a, unsigned b)
{
    if(!b)
        return a;
    return alg_lui_euc(b,a%b);
}

int main()
{
    FILE *f=fopen("euclid2.in","r"),*g=fopen("euclid2.out","w");
    fscanf(f,"%d",&T);
    for(;T;--T)
    {
        fscanf(f,"%d",&A);
        fscanf(f,"%d",&B);
        fprintf(g,"%d\n",alg_lui_euc(A,B));
    }
    return 0;
}
