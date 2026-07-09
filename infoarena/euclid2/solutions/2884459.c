#include <stdio.h>
#include <stdlib.h>

int cmmdc(int a, int b)
{
    while(b != 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main()
{
    int t,x,y,v[100001];
    scanf("%d", &t);
    for(int i = 1; i <= t; i++)
    {
        scanf("%d %d", &x, &y);
        v[i] = cmmdc(x,y);
    }
    for(int i = 1; i <= t; i++)
    {
        printf("%d\n", v[i]);
    }
    return 0;
}
