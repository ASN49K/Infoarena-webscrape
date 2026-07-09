#include <bits/stdc++.h>
using namespace std;
int euclid(int x,int y)
{
    int r;
    while(y)
    {
        r=x%y;
        x=y;
        y=r;
    }
    return x;
}
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        printf("%d\n",euclid(a,b));
    }
    return 0;
}
