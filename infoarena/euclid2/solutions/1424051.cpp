#include <cstdio>
void cmmdc(int a,int b)
{
    int r;
    scanf("%d",&a);
    scanf("%d",&b);
    r=a;
    while(r!=b)
    {
        if(r>b)
        r=r-b;
        else
        b=b-r;
    }
    printf("%d \n",r);
}
int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    int a,b,t,i;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    cmmdc(a,b);

    return 0;
}
