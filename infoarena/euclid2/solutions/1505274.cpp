#include <cstdio>
#include <fstream>

using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main()
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    int t, a, b;
    //cin >> t;
    scanf("%d", &t);
    while (t--) {
        //cin >> a >> b;
        scanf("%d %d", &a, &b);
        //cout << gcd(a,b) << endl;
        printf("%d\n", gcd(a,b));
    }
    return 0;
}
