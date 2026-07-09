#include<stdio.h>
unsigned int a,b,t;

void euclid(unsigned int a,unsigned int b)
{
    if(!b)
       printf("%ud\n",a);
    else
    {
        unsigned int r=a%b;
        while(r)
        {
            b=r;a=b;
            r=a%b;
        }
        printf("%ud\n",b);
    }

}

void rez()
{
    freopen("euclid.in","r",stdin);
    freopen("euclid.out","w",stdout);
    scanf("%ud", &t);
    for(unsigned int i=1;i<=t;++i)
    {
        scanf("%ud %ud", &a,&b);
        euclid(a,b);
    }
}



int main()
{
    rez();
    return 0;
}
