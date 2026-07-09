#include <cstdio>
void cmmdc(int i)
{
    int r,a,b;
    scanf("%d",&a);
    scanf("%d",&b);
    r=a;
    while(r!=b)
    {
        if(r>b)
        r=r%b;
        else
        b=b%r;
        if(b==0)
        {
            break;
        }
        else
        if(r==0)
        {
            r=b;
            break;
        }
    }
    printf("%d \n",r);
}
int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    int t,i;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    cmmdc(i);

    return 0;
}
