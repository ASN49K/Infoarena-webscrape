#include <iostream>
#include <cstdio>
using namespace std;
int a,b;
int cmmdc()
{
    int c;
    while(b!=0)
    {
        c=a%b;
        a=b;
        b=c;
    }
    return a;
}
int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    int n;
    scanf("%d",&n);
    while(n){
        scanf("%d%d",&a,&b);
        int best=cmmdc();
        printf("%d\n",best);
        --n;
    }
    return 0;
}
