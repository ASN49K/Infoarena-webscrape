#include<stdio.h>
unsigned int a,b,t;

void euclid(unsigned int a,unsigned int b)
{
    if(!b)
       printf("%u\n",a);
    else
    {
        unsigned int r=a%b;
        while(r)
        {
            a=b;b=r;
            r=a%b;
        }
        printf("%u\n",b);
    }

}

void rez()
{
    freopen("euclid.in","r",stdin);
    freopen("euclid.out","w",stdout);
    scanf("%u", &t);
    for(unsigned int i=1;i<=t;++i)
    {
        scanf("%u %u", &a,&b);
        euclid(a,b);
    }
}



int main()
{
    rez();
    return 0;
}
