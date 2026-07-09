#include<stdio.h>


int  x,y , t;
int euclid(int a, int b)
{
    if(b==0)
        return a;
    else
        return euclid(b, a%b);
}
int main()
{
    freopen("euclid2.in", "r", stdin);
freopen("euclid2.out", "w", stdout);
     scanf("%d", &t);
    for(;t ;--t)
    {
        scanf("%d %d", &x, &y);
        printf("%d\n", euclid(x, y));
    }


    return 0;
}
