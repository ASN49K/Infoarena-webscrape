#include <stdio.h>
#include <stdlib.h>

int cmmdc(int a,int b)
{
    while(b)
    {
        int r=a%b;
        a=b;
        b=r;
    }
    return a;
}
//haide sa gandesc mai bine!
struct puncte{
int x,y;
}A,B;
int main()
{
    FILE *f,*g;
    int T;
    f=fopen("euclid2.in","r");
    g=fopen("euclid2.out","w");
    if(f==NULL || g==NULL)
        exit(1);
    fscanf(f,"%d",&T);
    while(T)
    {
        fscanf(f,"%d%d",&A.x,&A.y);
        T--;
        fprintf(g,"%d\n",cmmdc(A.x,A.y));
    }
    fclose(f);
    fclose(g);

    return 0;
}
