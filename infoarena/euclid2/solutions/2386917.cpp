#include <cstdio>

using namespace std;

int EuclidScadere(int a, int b)
{
    if(b == 0)
        return a;

    if(a > b)
        EuclidScadere(a-b,b);
    else
        EuclidScadere(b,b-a);
}

int EuclidImpartire(int a, int b)
{
    if(b == 0)
        return a;
    EuclidImpartire(b,a%b);
}

int main()
{
    FILE *f = fopen("euclid2.in","r");
    FILE *g = fopen("euclid2.out","w");

    int T,a,b;
    fscanf(f,"%d",&T);
    while(T--)
    {
        fscanf(f,"%d %d",&a,&b);
        fprintf(g,"%d\n",EuclidImpartire(a,b));
    }
    return 0;
}
