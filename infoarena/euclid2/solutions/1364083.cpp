#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>

using namespace std;

int _gcd(int a,int b){
    if(!b)
        return a;
    return _gcd(b,a%b);
}

int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);

    int N,a,b;
    scanf("%d",&N);
    for(int i = 1; i <= N; ++i)
    {
        scanf("%d%d",&a,&b);
        printf("%d\n",_gcd(a,b));
    }
    return 0;
}
