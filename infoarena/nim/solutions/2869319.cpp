#include <fstream>

using namespace std;

int main()
{
    ifstream cin ("nim.in");
    ofstream cout ("nim.out");
    int t, n, xorr = 0, a, i;
    cin >> t;
    while (t--)
    {
        cin >> n;
        xorr = 0;
        for (i = 1; i <= n; i++)
            cin >> a, xorr ^= a;
        if (xorr == 0)
            cout << "NU" << '\n';
        else
            cout << "DA" << '\n';
    }
    return 0;
}
