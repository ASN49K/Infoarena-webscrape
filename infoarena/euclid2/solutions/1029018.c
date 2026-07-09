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
    int x,y;
    f=fopen("in.txt", "r");
    g=fopen("out.txt", "w");
    fscanf(f,"%d%d",&x,&y);
    fprintf(g,"%d",euclid(x,y));
    return 0;
}
