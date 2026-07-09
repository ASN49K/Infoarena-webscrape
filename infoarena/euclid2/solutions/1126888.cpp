#include <stdio.h>
long t,a,b,i;
int cmmdc(int a,int b)
{
    if(!b)return a;
    else return cmmdc(b,a%b);
}
int main()
{
    FILE *f1,*f2;
    f1=fopen("euclid2.in","r");
    f2=fopen("euclid2.out","w");
    fscanf(f1,"%ld",&t);
    for(i=0;i<t;i++)
    {
        fscanf(f1,"%ld %ld",&a,&b);
        fprintf(f2,"%d\n",cmmdc(a,b));
    }
    return 0;
}
