#include <fstream>

using namespace std;

ifstream cin("euclid2.in");
ofstream cout("euclid2.out");


    int gcd(int a, int b) {

        if (!b)
        return a;

        return gcd(b, a % b);

    }

int main()
{
    int a, b, n;
    cin >> n;

    while (n--) {
        cin >> a >> b;
        cout << gcd(a, b) << '\n';
    }
    return 0;
}
