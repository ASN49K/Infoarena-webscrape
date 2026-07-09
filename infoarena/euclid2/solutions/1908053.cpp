#include <fstream>

using namespace std;

ifstream cin ("euclid3.in" );
ofstream cout("euclid3.out");

int cmd(int x, int y)
{
    if (y == 0) return x;
    return cmd(y, x % y);
}

int main()
{
    int t, x, y;
    cin >> t;

    for (; t; t--)
    {
        cin >> x >> y;
        cout << cmd(x, y) << '\n';
    }

    return 0;
}
