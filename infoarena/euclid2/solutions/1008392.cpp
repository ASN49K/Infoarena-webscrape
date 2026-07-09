#include<stdio.h>
using namespace std;
int T; long int a,b,c,r,aux;
int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    scanf("%d",&T);
    while(T!=0)
    {
        scanf("%ld %ld",&a,&b);
        if(a<b){aux=a;a=b;b=aux;}
        c=a/b;r=a%b;
        while(r!=0)
        {
            a=b;b=r;
            c=a/b;
            r=a%b;
        }
        printf("%d \n",b);
        T--;
    }
    return 0;
}
