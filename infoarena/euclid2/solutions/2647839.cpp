#include<stdio.h>

int cnt, a, b;

int gcd(int a, int b)
{
    if(b == 0)
        return a;
    return gcd(b,a%b);
}
int main()
{
    freopen("Euclid2.in", "r", stdin);
    freopen("Euclid2.out", "w", stdout);

    scanf("%d", &cnt);

    for(int i = 0 ; i < cnt; i++)
    {
        scanf("%d %d",&a,&b);
        printf("%d\n",gcd(a,b));
    }
}
