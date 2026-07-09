#include <stdio.h>
#include <iostream>
using namespace std;
int T, A, B;

int gcd(int a, int b)
{
    if (!b) return a;
    return gcd(b, a % b);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    cin>>T;
    for (; T; --T)
    {
        cin>>A>>B;
        cout<<gcd(A,B)<<'\n';
    }

    return 0;
}
