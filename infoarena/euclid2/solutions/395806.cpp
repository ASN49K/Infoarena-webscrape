#include <iostream>

using namespace std;

long divi(long a,long b)
{
    if(!b) return a;
    else return divi(b,a%b);
}

int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    long n,a,b;
    scanf("%d",&n);



    for(int i=1;i<=n;i++)
        {
            scanf("%ld%ld",&a,&b);
            int x;x=divi(a,b);
            printf("%ld\n",x);
        }




    return 0;
}
