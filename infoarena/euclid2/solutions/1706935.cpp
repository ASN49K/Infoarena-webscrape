#include <stdio.h>

using namespace std;

int cmmdc(int a, int b) {
    int rest;
    while(b) {
        rest=a%b;
        a=b;
        b=rest;
    }
    return a;
}

int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    int t,a,b;
    scanf("%d",&t);
    for(int i=0;i<t;i++) {
        scanf("%d%d",&a,&b);
        printf("%d\n",cmmdc(a,b));
    }
    return 0;
}
