#include <iostream>
#include <cstdio>

using namespace std;

int a,b,r,n;
int cmmdc(int a, int b)
{
    if(b) return cmmdc(b, a%b);
    return a;
}

int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        scanf("%d %d", &a, &b);
        printf("%d\n", cmmdc(a, b));
    }
    return 0;
}
