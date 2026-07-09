#include <fstream>

using namespace std;

ifstream cin ("euclid2.in" );
ofstream cout("euclid2.out");

int gcd(int a, int b)
{
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main()
{
    int i, t, x, y;
    cin >> t;

    for (i = 0; i < t; i++)
    {
        cin >> x >> y;
        cout << gcd(x, y) << '\n';
    }

    return 0;
}
