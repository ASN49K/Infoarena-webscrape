#include <fstream>

using namespace std;

ifstream cin("euclid2.in");
ofstream cout("euclid2.out");

int n, a, b, r;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a >> b;
        r = 0;
        while (b)
        {
            r = a % b;
            a = b;
            b = r;
        }
        cout << a << '\n';
    }
    return 0;
}
