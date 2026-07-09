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
    f=fopen("in.txt", "r");
    g=fopen("out.txt", "w");
    fscanf(f,"%d",&n);
    for(i=0; i<n; i++)
    {
        fscanf(f,"%d %d",&x,&y);
        fprintf(g,"%d",euclid(x,y));
    }
    return 0;
}
