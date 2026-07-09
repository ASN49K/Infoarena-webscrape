#include <bits/stdc++.h>

using namespace std;

long long euclid(long long A,long long B)
{
    if(!B) return A;
    return euclid(B,A%B);
}

int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);

    int N;
    scanf("%d",&N);
    long long A,B;
    for(int i = 1; i <= N; ++i)
    {
        scanf("%lld%lld",&A,&B);
        printf("%lld\n",euclid(A,B));
    }

    return 0;
}
