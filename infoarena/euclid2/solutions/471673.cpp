#include <iostream>
#include <stdio.h>
#define fin "euclid2.in"
#define fout "euclid2.out"

using namespace std;

int main()
{
    freopen(fin,"r",stdin);
    freopen(fout,"w",stdout);

    int a,b,r,n;
    scanf("%d",&n);
    while(n)
    {
        scanf("%d %d",&a,&b);
        while(b)
        {
            r=a%b;
            a=b;
            b=r;
        }
        printf("%d\n",a);
        n--;
    }

    return 0;
}
