#include <fstream>

using namespace std;

ifstream cin("euclid2.in");
ofstream cout("euclid2.out");

int n, a, b;

int cmmdc(int x, int y)
{
    int r;
    while (y != 0)
    {
        r = x%y;
        x = y;
        y = r;
    }
    return x;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a >> b;
        cout << cmmdc(a, b) << '\n';
    }
    return 0;
}
