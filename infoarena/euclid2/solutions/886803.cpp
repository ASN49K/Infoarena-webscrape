#include<stdio.h>
int a,b,cmmdc,i;
int main ()
{
    freopen("euclid2.in","rt",stdin);
    freopen("euclid2.out","wt",stdout);
    scanf("%d%d",&a,&b);
    i=1;
    cmmdc=0;
    while(i<=a)
    {
        if(a%i==0&&b%i==0)
        {
            cmmdc=i;
        }
        i=i+1;
    }
    printf("%d",cmmdc);
    fclose(stdin);
    fclose(stdout);
}
