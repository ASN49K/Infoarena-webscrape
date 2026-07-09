#include <fstream>

using namespace std;

ifstream cin ("nim.in");
ofstream cout ("nim.out");

int n, m, x;

int main()
{
    for (cin >> m; m; --m)
    {
        cin >> n >> x;
        int sum = x;
        for (int i = 1; i < n; ++i)
            cin >> x, sum ^= x;
        if (!sum)
            cout << "NU\n";
        else
            cout << "DA\n";
    }
    return 0;
}
