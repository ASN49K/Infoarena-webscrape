#include <iostream>
#include <cstdio>
using namespace std;

int EUCLID(int a, int b)
{
    int c;
    while(b!=0)
    {
        c=a%b; a=b; b=c;
    }
    return a;
}

int main()
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    int N,i,a,b;

    scanf("%d",&N);
    for(i=1; i<=N; i++)
    {
        scanf("%d %d",&a,&b);
        printf("%d\n",EUCLID(a,b));

    }

    return 0;
}
