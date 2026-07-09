#include<cstdio>

void double_assign (int *plv1,int *plv2, int rv1,int rv2)
{
    *plv1=rv1;
    *plv2=rv2;
}

int main()
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
    int nN; scanf("%d", &nN);
    for (int i=1;i<=nN;i++)
    {
        int a,b;
        scanf("%d %d", &a, &b);
        while (b!=0)
            double_assign(&a,&b,  b,a%b);
        printf("%d\n", a);
    }
    return 0;
}
