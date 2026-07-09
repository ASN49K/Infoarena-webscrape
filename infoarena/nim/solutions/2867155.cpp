#include <fstream>

using namespace std;
ifstream cin("nim.in");
ofstream cout("nim.out");
void solve()
{
    int n, i, a, x = 0;
    cin >> n >> a;
    x = a;
    for(i = 1; i < n; i++)
    {
        cin >> a;
        x ^= a;
    }
    cout << (x == 0 ? "NU" : "DA") << '\n';
}
int main()
{
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
