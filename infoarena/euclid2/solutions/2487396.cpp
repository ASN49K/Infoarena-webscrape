#include <iostream>
#include <stdio.h>
using namespace std;
int Euclid(int a,int b)
{
    if(!b)return a;
    return Euclid(b,a%b);
}
int main()
{
    int a,b,t;
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
    scanf("%d",&t);
    while(t)
    {
        scanf("%d %d",&a,&b);
        printf("%d\n", Euclid(a,b));
        t--;
    }
}
