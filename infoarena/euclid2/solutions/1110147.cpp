#include<iostream>
#include<cstdio>

using namespace std;
int i,n,x,y;

int euclid(int a, int b)
{
    while (a*b!=0)
    (a>b)?a=a%b:b%=a;
    return a+b;
}

int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    scanf("%d\n",&n);
    for(i=1;i<=n;++i)
    {
        scanf("%d%d\n",&x,&y);
        printf("%d\n",euclid(x,y));
    }
    return 0;
}
