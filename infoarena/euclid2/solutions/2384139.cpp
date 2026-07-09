#include<cstdio>

using namespace std;

int main ()
{
    FILE *f,*g;
    int a,b,aux,T;
    f=fopen("euclid2.in", "r");
    fscanf(f, "%i", &T);
    g=fopen("euclid2.out", "w");
    for(int i=0;i<T;i++)
    {
        fscanf(f, "%i", &a);
        fscanf(f, "%i", &b);
        b%=a;
        while(b)
        {
            a%=b;
            aux=a;
            a=b;
            b=aux;
        }
        fprintf(g, "%i\n", a);
    }
    fclose(g);
    fclose(f);
    return 0;
}
