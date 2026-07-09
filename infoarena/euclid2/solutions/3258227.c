#include <stdio.h>
#include <stdlib.h>
int euclid(int a,int b)
{
    while(b!=0){
        int r = a%b;
        a = b;
        b = r;
    }
    return a;
}
int main()
{
    FILE *r, *w;
    r=fopen("euclid2.in", "r");
    w=fopen("euclid2.out", "w");
    int a,b,i,n;
    fscanf(r,"%d", &n);
    for(i=0; i<n; i++)
    {
        fscanf(r,"%d%d", &a,&b);
        fprintf(w, "%d\n", euclid(a,b));
    }
    return 0;
}
