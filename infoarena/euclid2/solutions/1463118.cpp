#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int N,a,b,r;
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    scanf("%d",&N);
    for(int i=1;i<=N;i++)
    {
        scanf("%d%d",&a,&b);
        while(b)
        {
            r=a%b;
            a=b;
            b=r;
        }
        printf("%d\n",a);
    }
}
