#include<cstdio>
#include<iostream>
using namespace std;
int n,a,b,r=0,i;
int main()
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a);
        scanf("%d",&b);
        while (b)
        {
            r = a % b;
            a = b;
            b = r;
        }
        printf("%d\n",a);
    }
}
