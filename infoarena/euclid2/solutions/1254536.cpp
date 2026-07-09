#include <iostream.h>
#include <fstream.h>
using namespace std;

int T, A, B;

int gcd(int a, int b)
{
    if (!b) return a;
    return gcd(b, a % b);
}

int main(void)
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    //for (scanf("%d", &T); T; --T)
    cin>>T;
    for (; T; --T)
    {
        cin>>A>>B;
        cout<<gcd(A, B);
    }

    return 0;
}
