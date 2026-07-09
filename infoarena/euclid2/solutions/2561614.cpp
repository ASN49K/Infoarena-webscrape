#include <fstream>

using namespace std;

ifstream cin("euclid2.in");
ofstream cout("euclid2.out");

int gcd(int a , int b)
{
   if(b == 0) return a;
   a %= b;
   return gcd(b, a);
}

int main()
{
    int q, x, y;
    cin >> q;
    while (q--)
    {
        cin >> x >> y;
        cout << gcd(x, y) << '\n';
    }
}
