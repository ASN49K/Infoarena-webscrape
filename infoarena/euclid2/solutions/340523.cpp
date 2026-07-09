#include<stdio.h>
int n;
int a,b;
int cmmdc(int x, int y)
{
    int aux;
    while (x % y != 0)
     {
         aux = x;
         x = y;
         y = aux % y;
     }
    return y;
}

int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);

    scanf("%d",&n);
    for(int i = 1; i <= n; i++)
    {
     scanf("%d %d",&a,&b);
     printf("%d\n",cmmdc(a,b));
    }
}
