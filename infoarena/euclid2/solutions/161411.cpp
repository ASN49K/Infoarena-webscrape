#include<stdio.h>

int t,a,b;

int euclid( int a, int b)
{
    while(b!=0)
    {
        int aux=b;
        b=a%b;
        a=aux;
    }
    return a;
}


        

int main()
{
     int i;
     freopen("euclid2.in","r",stdin);
     freopen("euclid2.out","w",stdout);
     scanf("%d",&t);
     for(i=1;i<=t;++i)
     {
        scanf("%d%d",&a,&b);
        printf("%d\n",euclid(a,b));
     }
     return 0;
}

        
        
