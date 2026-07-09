#include <iostream>
#include <cstdio>
using namespace std;

int euclid(int a, int b)
{

    int r;
    while(b!=0){
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}

int main()
{
    int cmmdc;
    freopen("euclid2.out","w",stdout);
    freopen("euclid2.in","r",stdin);
    int n,a,b;
    scanf("%d\n", &n);
    for(int i=1;i<=n;i++){
        scanf("%d %d\n", &a, &b);
        cmmdc=euclid(a,b);
        printf("%d\n", cmmdc);
    }
    return 0;
}
