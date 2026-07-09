#include <iostream>
#include <fstream>
using namespace std;
int t,a,b,r,i,n;
int main()
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    scanf("%d", &t);
    for(i=1; i<=t; i++)
    {
        scanf("%d%d", &a, &b);
        r=a%b;
        while(r)
        {
            a=b;
            b=r;
            r=a%b;
        }
        printf("%d\n", b);
    }

    return 0;
}
