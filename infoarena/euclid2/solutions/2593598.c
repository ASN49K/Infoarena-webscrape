#include <stdio.h>
#include <stdlib.h>

int euclid(int a,int b)
{
    int r=a%b;
    if(r==0)
        return b;
    else
        return euclid(b,a%b);
}



int main()
{
    FILE* f=fopen("euclid.in","r");
    FILE* g=fopen("euclid.out","w");
    int T;
    fscanf(f,"%d",&T);
    int A,B;
    for (;T; --T)
    {
        fscanf(f,"%d %d", &A, &B);
        fprintf(g,"%d\n", euclid(A, B));
    }
    return 0;
}
