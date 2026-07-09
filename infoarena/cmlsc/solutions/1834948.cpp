#include <fstream>

using namespace std;

ifstream cin("euclid2.in");
ofstream cout("euclid2.out");

int gcd(int a, int b)
{
    if (b==0) return a;
    return gcd(b,a % b);
}

main()
{
    int x,y,t;
    cin >> t;
    for (; t; t--)
    {
        cin >> x >> y;
        cout << gcd(x,y) << '\n';
    }
}
