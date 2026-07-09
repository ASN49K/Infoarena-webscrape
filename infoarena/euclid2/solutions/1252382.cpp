#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    else return gcd(b, a%b);
}

int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    
    int T, a, b;
    f >> T;
    while (T--)
    {
        f >> a >> b;
        if (a < b) {
            swap(a, b);
        }
        g << gcd(a, b) << '\n';
    }

    return 0;
}
