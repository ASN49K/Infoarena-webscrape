#include<cstdio>
using namespace std;
int cmmdc( int a , int b )
{
    int r;
    r = a % b;
    while ( r ){
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}
int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    int a,b,d,t;
    scanf("%d",&t);
    for ( int i = 1 ; i <= t ; i++ ){
        scanf("%d%d",&a,&b);
        d = cmmdc(a,b);
        printf("%d\n",d);
    }
    printf("\n");
    return 0;
}
