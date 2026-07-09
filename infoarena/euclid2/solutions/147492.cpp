#include<stdio.h>
long int x,y;
long int cmmdc(long int a, long int b);
int main()
{   FILE *f=fopen("euclid2.in","r"),
         *g=fopen("euclid2.out","w");
    fscanf(f,"%ld%ld",&x,&y);
    fprintf(g,"%ld",cmmdc(x,y));
    fcloseall();
    return 0;
}
long int cmmdc(long int a, long int b)
{    if(!b) return a;
     return cmmdc(b,a%b);
}