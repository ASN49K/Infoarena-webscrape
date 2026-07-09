#include <iostream>
#include <cstdio>

using namespace std;

int t, n, sXOR, x;

void read()
{
    scanf("%d", &t);
    for(int i=1; i<=t; ++i)
    {
        sXOR=0;
        scanf("%d", &n);
        for(int j=1; j<=n; ++j)
        {
            scanf("%d", &x);
            sXOR=(sXOR^x);
        }
        if(sXOR)
            printf("DA\n");
        else
            printf("NU\n");
    }
}

int main()
{
    freopen("nim.in", "r", stdin);
    freopen("nim.out", "w", stdout);
    read();
    return 0;
}
