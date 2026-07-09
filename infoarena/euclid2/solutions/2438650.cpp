#include <fstream>
#include <algorithm>

using namespace std;

ifstream cin ("euclid2.in");
ofstream cout ("euclid2.out");

int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        int a, b;
        cin >> a >> b;
        cout << __gcd(a, b) << '\n';
    }
    return 0;
}
