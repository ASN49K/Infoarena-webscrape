#include <iostream>

#include <cstdio>

using namespace std;

int a,b,d,T,i;

int main()
{
    FILE*f=fopen("euclid2.in"," r ");
    FILE*g=fopen("euclid2.out" ," w ");
    fscanf(f,"%d", &T);
    for(i=0;i<T;i++)
    {
        d=0;
        fscanf(f,"%d %d", &a , &b);
        while(b)
        {
            d=a%b;
            a=b;
            b=d;
        }
        fprintf(g,"%d" "\n", a);
    }
    return 0;

}
