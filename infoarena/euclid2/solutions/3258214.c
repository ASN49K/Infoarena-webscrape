#include <stdio.h>
#include <stdlib.h>
int cmmdc(int a,int b)
{
    int schimbdhaine;
    if(a>b){
        schimbdhaine=a;
        a=b;
        b=schimbdhaine;
    }
    if(b%a==0){
        return a;
    }

        int a,b,t,d;
        scanf("%d",&t);

        if(b%a==0)
        {
            return a;
        }
        int d=a/2;
        while(d>=1)
        {
            if(a%d==0&&b%d==0)
            {
                return d;
            }
            d--;
        }

        t--;
    }


    int main()

    FILE*r,*w;
    r=fopen("euclid2.in", *r);
    w=fopen("euclid2.out", *w);
    int t;
    while (t>=0)
    {
        scanf("%d", &a, &b);
        printf("%d", cmmdc(a,b));
        t--;
    }

}
