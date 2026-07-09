#include <iostream>
#include <cstdio>

using namespace std;


long long cmmdc(long long a, long long b)
{
    if(b == 0 )
        return a;

    if( !(a%b) )
        return b;

    return cmmdc(b,a%b);
}


int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);

    int T;
    scanf("%d",&T);
    for(int i=1; i<=T; i++)
    {
        long long num1,num2;
        scanf("%llu%llu",&num1,&num2);

        if(num1 > num2)
            printf("%llu\n",cmmdc(num1,num2));

        else if(num1 < num2)
            printf("%llu\n",cmmdc(num2,num1));

        else
            printf("%llu\n",num1);
    }

    return 0;
}
