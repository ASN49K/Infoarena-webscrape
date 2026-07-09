#include<cstdio>
int T,a,b,aux;
int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    scanf("%d", &T);
    for(int i=1;i<=T;i++)
    {
        scanf("%d %d", &a, &b);
        while(b!=0)
        {
            aux=a;
            a=b;
            b=aux%a;
        }
        printf("%d\n", a);
    }
    return 0;
}
