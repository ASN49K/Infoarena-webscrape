#include <stdio.h>
#include <stdlib.h>
int euclid(int a, int b)
{
    if (b == 0) return a;
    else
       return euclid(b, a % b);
}

int main()
{
    FILE *f,*g;
    int x,y,n,i;
    f=fopen("euclid2.in", "r");
    g=fopen("euclid2.out", "w");
    fscanf(f,"%d",&n);
    for(i=0; i<n; i++)
    {
        fscanf(f,"%d %d",&x,&y);
        fprintf(g,"%d \n",euclid(x,y));
    }
    fclose(f);
    fclose(g);
    return 0;
}
