#include <iostream>
#include <stdio.h>
using namespace std;
int n,x,y;
int euclid(int a, int b)
{
    int r;
    while(b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        scanf("%d %d", &x, &y);
        euclid(x,y);
        printf("%d \n", euclid(x,y));
    }
    return 0;
}
