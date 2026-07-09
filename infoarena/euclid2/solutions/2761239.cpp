#include <fstream>

using namespace std;

ifstream cin ("euclid2.in");
ofstream cout ("euclid2.out");

int euclid(int x, int y)    {
    if (x == 0)
        return y;
    if (y == 0)
        return x;
    return euclid(y, x % y);
}

int main()  {
    int t, a, b;
    cin >> t;
    while (t--) {
        cin >> a >> b;
        cout << euclid(a, b) << '\n';
    }
    return 0;
}
