#include <fstream>
#include <cstdio>

using namespace std;

ifstream cin("euclid2.in");
ofstream cout("euclid2.out");

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return gcd(b, a % b);
    }
}

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int a, b, c;
        cin >> a >> b;
        c = gcd(a, b);
        cout << c << "\n";
    }
}
