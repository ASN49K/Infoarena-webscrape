#include<stdio.h>
int cmmdc(int a, int b)
{
    if(b==0) return a;
    return cmmdc(b,a%b);
}
int main()
{
    FILE *f1 = fopen("euclid2.in","r");
    FILE *f2 = fopen("euclid2.out","w");
    int n,a,b,i;
    fscanf(f1,"%d",&n);
    for(i=1;i<=n;i++)
        {
            fscanf(f1,"%d%d",&a,&b);
            fprintf(f2,"%d \n",cmmdc(a,b));
        }
    return 0;
}
