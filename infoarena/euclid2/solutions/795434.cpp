#include <stdio.h>
#include <iostream>
using namespace std;

int t,a,b;
int div(int a,int b)
{
    if (!b)
        return a;
    div(b,a%b);
}
int main()
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
    scanf("%d", &t);
    for (int i=0; i<t; i++)
    {
        scanf("%d %d", &a, &b);
        printf("%d\n", div(a, b));
    }
    return 0;
}
