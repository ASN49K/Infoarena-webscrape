#include <stdio.h>
#include <stdlib.h>

void citire(int** a,int n,FILE* f)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<=1; j++)
        {
            fscanf(f,"%d",&a[i][j]);
        }
    }
}

int euclid(int a,int b)
{
    int r=a%b;

    while(r)
    {
        a=b;
        b=r;
        r=a%b;
    }
    return b;
}

void afisare(int** a,int n,FILE* g)
{
    for(int i=0; i<n; i++)

        for(int j=0; j<=1; j++)
        {
            fprintf(g,"%d\n",euclid( a[i][j], a[i][j+1]) );
            break;
        }
}

int main()
{
    FILE* f=fopen("euclid2","r");
    FILE* g=fopen("euclid2.out","w");
    int size;
    fscanf(f,"%d",&size);
    int* a=(int* )malloc(size*sizeof(int));
    for(int i=0; i<size; i++)
    {
        a[i]=(int *)malloc(2*sizeof(int));
    }
    citire(a,size,f);
    afisare(a,size,g);

    return 0;
}
